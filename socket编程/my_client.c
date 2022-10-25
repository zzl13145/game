#include <sys/types.h>         
#include <sys/socket.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

/* 
 * socket
 * connect
 * send/recv
 */

 #define SERVER_PORT 8888
 
int main(int argc,char** argv)
{
	int iSocketClient;//客户端文件描述符
	struct sockaddr_in tSocketServerAddr;//存储服务器端地址信息	
	int iRet;
	unsigned char ucSendBuf[1000];
	int iSendLen;	
	if (argc != 2)
	{
		printf("Usage:\n");
		printf("%s <server_ip>\n", argv[0]);
		return -1;
	}		
	iSocketClient = socket(AF_INET, SOCK_STREAM, 0);
	tSocketServerAddr.sin_family      = AF_INET;
	tSocketServerAddr.sin_port        = htons(SERVER_PORT);
 	if (0 == inet_aton(argv[1], &tSocketServerAddr.sin_addr))//手动输入服务器端ip转化并存储到tSocketServerAddr.sin_addr
 	{
/*int inet_aton(const char *cp, struct in_addr *inp);
参数说明：
cp : IPv4点分十进制字符串，例如“192.168.1.2”、“10.28.1.1”等;
inp: 点分十进制转换成二进制后的结构体(网络字节序)
返回值：成功返回非0；失败返回0*/
		printf("invalid server_ip\n");
		return -1;
	}
	memset(tSocketServerAddr.sin_zero, 0, 8);		
	
	/*int connect(int sockfd, struct sockaddr * serv_addr,int addrlen);
	 *sockfd 是 socket 函数返回的文件描述符
	 *serv_addr 储存了服务器端的连接信息，其中 sin_add 是服务端的地址
	 *addrlen 是 serv_addr 的长度
	 *connect 函数是客户端用来同服务端连接的.成功时返回 0，sockfd 是同服务端通讯的文件描述符，失败时返回-1。
	 */
	iRet=connect(iSocketClient, (const struct sockaddr *)&tSocketServerAddr,sizeof(struct sockaddr));
	if (-1 == iRet)
	{
		printf("connect error!\n");
		return -1;
	}	
    
	/* char *fgets(char *s, int size, FILE *stream);
	 * s 代表要保存到的内存空间的首地址，可以是字符数组名，也可以是指向字符数组的字符指针变量名
	 *size 代表的是读取字符串的长度
	 *stream 表示从何种流中读取，可以是标准输入流 stdin，也可以是文件流
	 */
	while (1)
	{
		if (fgets(ucSendBuf, 999, stdin))
		{
			/* ssize_t send(int sockfd, const void *buf, size_t len, int flags);
			 * sockfd 指定发送端套接字描述符;
			 * buf 指明一个存放应用程序要发送数据的缓冲区;
			 * len 指明实际要发送的数据的字节数；
			 * flags 一般置 0。
			 * 客户或者服务器应用程序都用 send 函数来向 TCP 连接的另一端发送数据
			 */
			iSendLen = send(iSocketClient, ucSendBuf, strlen(ucSendBuf), 0);
			if (iSendLen <= 0)
			{
				close(iSocketClient);
				return -1;
			}
		}
	}	
	
	
	return 0;
}


























