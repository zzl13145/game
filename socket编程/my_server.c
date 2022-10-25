#include <sys/types.h>          
#include <sys/socket.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

/* 
 * socket	 "创建socket描述符"
 * bind    	 "绑定信息:IP,端口等"
 * listen	 "启动监听数据"
 * accept	 "等待接受客户端发来的连接"
 * send/recv "收发数据"
 */
 
#define SERVER_PORT 8888
#define BACKLOG     10

/*
sockaddr_in在头文件#include<netinet/in.h>或#include <arpa/inet.h>中定义，
该结构体解决了sockaddr的缺陷，把port和addr 分开储存在两个变量中。
struct sockaddr_in {
    sa_family_t    sin_family; //地址族
    in_port_t      sin_port;   //端口号
    struct in_addr sin_addr;   //32位IP地址
	char     sin_zero[8];      //预留未使用
};
struct in_addr{
	In_addr_t  s_addr;    //32位IPv4地址
};
*/
 int main(int argc,char** argv)
 {
	 int iSocketServer;//服务器端文件描述符
	 int iSocketClient;//客户端文件描述符
	 struct sockaddr_in tSocketServerAddr;//存储服务器端地址信息
	 struct sockaddr_in tSocketClientAddr;//存储客户端地址信息	 
	 int iRet;
	 int iAddrLen;
	 int iRecvLen;
	 unsigned char ucRecvBuf[1000];//存储客户端发送来的信息
	 int iClientNum = -1;	

	 signal(SIGCHLD,SIG_IGN);//清除僵尸进程
	 
	 /*int socket(int domain, int type, int protocol);
	  * domain：	协议族（如ipv4）
	  * type：		信息传送方式（如TCP、UDP）
	  * protocol：	对应协议（通常设置为0,让其自动匹配）
	  */
	 iSocketServer = socket(AF_INET, SOCK_STREAM, 0);/*AF_INET：IPv4；SOCK_STREAM：TCP*/
	if (-1 == iSocketServer)
	{
		printf("socket error!\n");
		return -1;//失败返回-1
	}	 
	
	 /*int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen); */
	tSocketServerAddr.sin_family      = AF_INET;
	tSocketServerAddr.sin_port        = htons(SERVER_PORT);  /* host to net, short */
 	tSocketServerAddr.sin_addr.s_addr = INADDR_ANY;
	memset(tSocketServerAddr.sin_zero, 0, 8);
	iRet = bind(iSocketServer, (const struct sockaddr*)&tSocketServerAddr,sizeof(struct sockaddr)); 
	if (-1 == iRet)
	{
		printf("bind error!\n");
		return -1;
	}	 
	 
	 /*int listen(int sockfd, int backlog);*/
	 iRet = listen(iSocketServer, BACKLOG);
	if (-1 == iRet)
	{
		printf("listen error!\n");
		return -1;
	}	
	
	 while(1)
	{
	 /*int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	  *成功返回客户端的文件描述符，失败返回-1	
	  */
		iAddrLen = sizeof(struct sockaddr);
		iSocketClient = accept(iSocketServer,(struct sockaddr*)&tSocketClientAddr,&iAddrLen);
		if (-1 != iSocketClient)
		{
			iClientNum++;
			printf("Get connect from client %d : %s\n",  iClientNum, inet_ntoa(tSocketClientAddr.sin_addr));
			if(!fork())
			{
				/*子进程的源码*/
				while(1)
				{
					/*接收客户端发来的数据并显示出来*/
					/*ssize_t recv(int sockfd, void *buf, size_t len, int flags);
					返回值为接收到的数据大小*/
					iRecvLen = recv(iSocketClient, ucRecvBuf, 999, 0);
					if(iRecvLen <=0)
					{
						close(iSocketClient);
						return -1;
					}
					else
					{
						ucRecvBuf[iRecvLen] = '\0';//给接收到数据的数组加上结束符标志
						printf("Get Msg From Client %d: %s\n", iClientNum, ucRecvBuf);
					}
				}
			}
		}
	 
	}
	  close(iSocketServer);
	 return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 