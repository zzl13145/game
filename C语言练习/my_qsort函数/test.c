#include <stdio.h>
#include <string.h>
//交换一对元素
void swap(char* buf1, char* buf2, int width)
{
	int i;
	for (i = 0;i < width;i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

//1.定义结构体
typedef struct
{
	char name[20];
	int age;
}Stu;

void my_qsort(void* base,int sz,int width,int (*cmp)(void* e1,void* e2))//冒泡排序任何类型的数组的函数
{
	int i;
	for (i = 0;i < sz-1;i++)//确定趟数
	{
		int j;
		for (j = 0;j < sz - 1 - i;j++) //每趟比较的对数
		{
			if (cmp((char*)base + j * width ,(char*)base+(j+1)*width) > 0)//两个元素的比较,width代表一个元素类型的大小，
																		  //+j*width代表指针base指向第 j 个元素的位置（下标从0开始）。
			{
				//交换
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}

}
//比较整型的函数
int cmp_int(const char* e1, const char* e2)
{
	return *(int*)e1 - *(int*)e2;
}
//比较浮点型数组
int cmp_float(const void* e1, const void* e2)
{
	return (int)(*(float*)e1 - *(float*)e2);
}
//比较结构体数组
int cmp_stu_age(const void* e1, const void* e2)
{
	return ((Stu*)e1)->age - ((Stu*)e2)->age;//比较年龄
}
int cmp_stu_name(const void* e1, const void* e2)
{
	return strcmp(((Stu*)e1)->name, ((Stu*)e2)->name);//比较名字（比较字符串）
}
//比较字符串的大小
int cmp_str_size(const void* e1, const void* e2)
{
	return strcmp((char*)e1, (char*)e2);
}

//排序整型数组
void test0()
{
	int arr[] = { 5,6,4,8,9,10,25 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), cmp_int);
	
}

//排序结构体数组
void test1()
{
	Stu s[3] = { {"zhangsan",20},{"lisi",25},{"wangwu",30} };
	int sz = sizeof(s) / sizeof(s[0]);
	my_qsort(s, sz, sizeof(s[0]), cmp_stu_name);
}
//排序字符串
void test2()
{
	char string[] = { "bdcafglmn" };
	int sz = sizeof(string) / sizeof(string[0])-1;
	my_qsort(string, sz, sizeof(string[0]), cmp_str_size);
}
int main()
{
	test0();//排序整型数组
	test1();//排序结构体数组
	test2();//排序字符串数组
	return 0;
}
