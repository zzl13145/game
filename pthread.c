#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>//信号量头文件
#include <string.h>


static char g_buf[1000];
static int g_flag=0;
static sem_t g_sem;//信号量
static pthread_mutex_t g_tMutex = PTHREAD_MUTEX_INITIALIZER;//定义互斥量，防止多线程同时访问临界资源
static void *my_thread_func(void *data)
{
	while(1)
	{
		//sleep(1);
		//等等通知
		//while(g_flag==0);
		sem_wait(&g_sem);
		pthread_mutex_lock(&g_tMutex);
		printf("recv:%s\n",g_buf);
		pthread_mutex_unlock(&g_tMutex);
		int varl;
		sem_getvalue(&g_sem, &varl);
		printf("g_sem0:%d\n",varl);
		/*打印*/


		 
	}
	return NULL;
}





int main(int argc, char **argv)
{  

	pthread_t tid;//创建线程ID
	int ret;
	sem_init(&g_sem,0,0);
	/* 1.创建“接受线程” */
	ret = pthread_create(&tid, NULL,my_thread_func, NULL);
	if(ret)
	{
		printf("pthread_create err!\n");
		return -1;
	}
	/* 2.主线程读取标准输入，发给“接受线程” */
		

		while(1)
		{
			pthread_mutex_lock(&g_tMutex);//锁上线程
			fgets(g_buf, 1000, stdin);
			pthread_mutex_unlock(&g_tMutex);//解锁线程
			/*通知接受线程*/
			sem_post(&g_sem);//通知接受线程
			int varl;
			sem_getvalue(&g_sem, &varl);
			printf("g_sem1:%d\n",varl);
			
		}
	




	return 0;

}
