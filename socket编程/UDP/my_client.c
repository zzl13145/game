#include <sys/types.h>          
#include <sys/socket.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

/* socket
 * connect
 * send/recv
（1）使用socket()，生成套接字文件描述符；

（2）通过struct sockaddr_in 结构设置服务器地址和监听端口；

（3）向服务器发送数据，sendto() ；

（4）关闭套接字，close() 
 */

#define SERVER_PORT 8888

int main(int argc, char **argv)
{
	int iSocketClient;//客户端文件描述符
	struct sockaddr_in tSocketServerAddr;//服务器端地址信息（ip、端口等）
	
	int iRet;
	unsigned char ucSendBuf[1000];//缓存输入的信息
	int iSendLen;

	if (argc != 2)
	{
		printf("Usage:\n");
		printf("%s <server_ip>\n", argv[0]);
		return -1;
	}
 /*int socket(int domain, int type, int protocol);
  * domain：	协议族（如ipv4）
  * type：		信息传送方式（如TCP、UDP）
  * protocol：	对应协议（通常设置为0,让其自动匹配）
  */
	iSocketClient = socket(AF_INET, SOCK_DGRAM, 0);
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
	tSocketServerAddr.sin_family      = AF_INET;
	tSocketServerAddr.sin_port        = htons(SERVER_PORT);  /* host to net, short */
 	/*inet_aton将点分十进制的字符串（如127.0.0.1）转换为网络字节序的二进制数，
	并存储在tSocketServerAddr.sin_addr，成功返回非0；失败返回0*/
 	if (0 == inet_aton(argv[1], &tSocketServerAddr.sin_addr))
 	{
		printf("invalid server_ip\n");
		return -1;
	}
	memset(tSocketServerAddr.sin_zero, 0, 8);
	
	while (1)
	{
		if (fgets(ucSendBuf, 999, stdin))
		{
			//iAddrLen = sizeof(struct sockaddr);
/* ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen);
 * sendto 和 send 相似，区别在于 sendto 允许在无连接的套接字上指定一个目标地址。
 * dest_addr 表示目地机的 IP 地址和端口号信息
 * addrlen 常常被赋值为 sizeof （struct sockaddr）。
 * sendto 函数也返回实际发送的数据字节长度或在出现发送错误时返回-1。
 */
			iSendLen = sendto(iSocketClient, ucSendBuf, strlen(ucSendBuf), 0,
			                      (const struct sockaddr *)&tSocketServerAddr, sizeof(struct sockaddr));
			
			if (iSendLen <= 0)
			{
				close(iSocketClient);
				return -1;
			}
		}
	}
	
	return 0;
}

