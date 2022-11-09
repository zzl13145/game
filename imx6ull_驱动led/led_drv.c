#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <linux/poll.h>
#include <linux/mutex.h>
#include <linux/wait.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <asm/io.h>

static struct class *led_class;
static int major;//主设备号

/* registers寄存器地址 */
/* IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3 地址：0x02290000 + 0x14*/
static volatile unsigned int *IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3;//	 configure gpio5_io3 as gpio
/* GPIO5_GDIR 地址：0x020AC004*/
static volatile unsigned int *GPIO5_GDIR;//  configure gpio5_io3 as output
/*GPIO5_DR 地址：0x020AC000*/
static volatile unsigned int *GPIO5_DR;// 	set gpio register: out 1/0 


static int led_open(struct inode *inode, struct file *filp)
{
	/* enable gpio5 （imx6ull板的gpio5默认使能）
	 * configure gpio5_io3 as gpio
	 * configure gpio5_io3 as output 
	 */
	*IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3 &= ~0xf;//低四位置0
	*IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3 |= 0x5;//0101

	*GPIO5_GDIR |= (1<<3);//configure gpio5_io3 as output
	
	return 0;
}

static ssize_t led_write(struct file *filp, const char __user *buf,
			 size_t count, loff_t *ppos)
{
	char val;
	int ret;
	/* copy_from_user : 从app读取数据 */
	ret = copy_from_user(&val, buf, 1);

	/* to set gpio register: out 1/0 */
	if(val==1)
	{
		/* set gpio to let led on */
		*GPIO5_DR &= ~(1<<3);
	}
	else
	{
		/* set gpio to let led off */
		*GPIO5_DR |= (1<<3);
	}
	
	return 1;
}



static struct file_operations led_fops=
{
	.owner		= THIS_MODULE,
	.write		= led_write,
	.open		= led_open,
};



/*入口函数*/
static int __init led_init(void)
{
	printk("%s %s %d\n",__FILE__,__FUNCTION__,__LINE__);

	major=register_chrdev(0,"100ask_my_led",&led_fops);/*register_chrdev：注册字符设备*/
	led_class =class_create( THIS_MODULE,"my_led");//class_create动态创建设备的逻辑类，并完成部分字段的初始化，然后将其添加到内核中。创建的逻辑类位于/sys/class/。
	device_create(led_class, NULL, MKDEV(major, 0), NULL, "myled");//创建设备节点,MKDEV(major, 0)主次设备号

	/* ioremap */
	/* IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3 地址：0x02290000 + 0x14*/
	IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3 = ioremap(0x02290000 + 0x14, 4);
	/* GPIO5_GDIR 地址：0x020AC004*/
	GPIO5_GDIR = ioremap(0x020AC004, 4);
	/*GPIO5_DR 地址：0x020AC000*/
	GPIO5_DR  = ioremap(0x020AC000, 4);


	return 0;


}




/*出口函数*/
static void __exit led_exit(void)
{
	iounmap(IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3);
	iounmap(GPIO5_GDIR);
	iounmap(GPIO5_DR);
	
	device_destroy(led_class, MKDEV(major, 0));//销毁设备节点
	class_destroy(led_class);//销毁设备的逻辑类
	unregister_chrdev(major,"100ask_my_led");

}




module_init(led_init);//修饰led_init为入口函数
module_exit(led_exit);//修饰led_exit为出口函数
MODULE_LICENSE("GPL");//指定GPL协议



