#include <sys/types.h>         
#include <sys/socket.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>


/* socket 			"创建socket描述符"
 * bind				"绑定信息:IP,端口等"
 * sendto/recvfrom	"收发数据"		
（1）使用函数socket()，生成套接字文件描述符；

（2）通过struct sockaddr_in 结构设置服务器地址和监听端口；

（3）使用bind() 函数绑定监听端口，将套接字文件描述符和地址类型变量（struct sockaddr_in ）进行绑定；

（4）接收客户端的数据，使用recvfrom() 函数接收客户端的网络数据；

（5）关闭套接字，使用close() 函数释放资源；
 */

#define SERVER_PORT 8888

int main(int argc, char **argv)
{
	int iSocketServer;//服务器端文件描述符
	int iSocketClient;//客户端文件描述符
	struct sockaddr_in tSocketServerAddr;//服务器端地址信息
	struct sockaddr_in tSocketClientAddr;//客户端地址信息
	int iRet;
	int iAddrLen;//地址长度

	int iRecvLen;//接收到数据的大小
	unsigned char ucRecvBuf[1000];//存储客户端发送来的信息

	int iClientNum = -1;//给客户端编号
	
	/*AF_INET：IPv4；SOCK_STREAM：TCP，返回文件描述符*/
	iSocketServer = socket(AF_INET, SOCK_DGRAM, 0);
	
	if (-1 == iSocketServer)
	{
		printf("socket error!\n");
		return -1;
	}

	tSocketServerAddr.sin_family      = AF_INET;
	tSocketServerAddr.sin_port        = htons(SERVER_PORT);  /* host to net, short */
 	tSocketServerAddr.sin_addr.s_addr = INADDR_ANY;
	memset(tSocketServerAddr.sin_zero, 0, 8);//char sin_zero[8];      //预留不使用，置0
	
	iRet = bind(iSocketServer, (const struct sockaddr *)&tSocketServerAddr, sizeof(struct sockaddr));
	if (-1 == iRet)
	{
		printf("bind error!\n");
		return -1;
	}


	while (1)
	{
		iAddrLen = sizeof(struct sockaddr);
/* ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr *src_addr, socklen_t *addrlen);
 * recvfrom 通常用于无连接套接字，因为此函数可以获得发送者的地址。
 * sockfd 是服务器端文件描述符
 * buf是把客户端发来的数据存到由参数buf 指向的内存空间
 * len 为可接收数据的最大长度
 * flags 调用操作方式（一般置 0）
 * src_addr 是一个 struct sockaddr 类型的变量，该变量保存源机的 IP 地址及端口号
 * addrlen 地址长度，常置为 sizeof （struct sockaddr） 
 */
		iRecvLen = recvfrom(iSocketServer, ucRecvBuf, 999, 0, (struct sockaddr *)&tSocketClientAddr, &iAddrLen);
		if (iRecvLen > 0)
		{
			ucRecvBuf[iRecvLen] = '\0';//给接收到数据的数组加上结束符标志
			printf("Get Msg From %s : %s\n", inet_ntoa(tSocketClientAddr.sin_addr), ucRecvBuf);
/*函数的作用是：将以网络字节序给出的网络主机地址 ip 转换成以点分十进制表示的字符串（如127.0.0.1）。结果作为函数返回结果返回*/
		}
	}
	
	close(iSocketServer);
	return 0;
}


