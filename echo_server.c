#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<ctype.h>
#include<arpa/inet.h>
#define SERVER_PORT 9003
int main(void){
	int sockfd_Head = socket( AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in Server_addr;
	bzero(&Server_addr,sizeof(Server_addr));
	Server_addr.sin_family = AF_INET;
	Server_addr.sin_port = htons((unsigned short)SERVER_PORT);//采用htons函数将unsiged short类型的变量转换成大端模式即网络序
	Server_addr.sin_addr.s_addr = inet_addr("192.168.0.4");//采用inet_addr函数将常量字符串类型的变量转换成网络序方式的32位无符号整型

	//printf("%u\n", Server_addr.sin_addr.S_un.S_addr);


	//调用函数int bind(int sockfd,const struct sockaddr* addr,socklen_t addrlen)将套接字绑定到本地的IP和端口
	//参数1: 套接字
	//参数2：指向struct sockaddr结构体类型的指针，一般绑定IPV4地址传入struct sockaddr_in指针(需强制转换)
	//参数3: 参数2所指对象的内存大小，采用sizeof()计算得到。
	//返回值：0 表示执行成功；-1 表示执行失败
	if (bind(sockfd_Head, (struct sockaddr*)&Server_addr, sizeof(Server_addr))<0){
		printf("bind error\n");
	}

	//调用函数int listen(int sockfd,int backlog)将套接字设置为监听状态，等待客户端连接
	//参数1: 套接字
	//参数2：排队的最大连接数量(包括1、已完成连接队列和未完成连接队列)
	//返回值：0 表示执行成功；-1 表示执行失败
	if (listen(sockfd_Head, 1) < 0){
		printf("listen error\n");
	}

	//客户端IP和地址
	struct sockaddr_in Client_addr;
	socklen_t Client_addr_len = sizeof(Client_addr);

	//调用函数int accept(int sockfd, struct sockaddr* Client_addr,socklen_t *addrlen)进入阻塞状态，直至建立连接
	//参数1: 套接字
	//参数2：指向struct sockaddr结构体类型的指针，一般绑定IPV4地址传入struct sockaddr_in指针(需强制转换)
	//参数3: 指向socklen_t类型的指针，所指向的对象采用sizeof()计算得到。
	//返回值：用于连接的新套接字
	int sockfd_Son = accept(sockfd_Head, (struct sockaddr*) &Client_addr, &Client_addr_len);

	printf("Server success run\n");

	const int Max_length = 100;
	char RecvBuf[Max_length];
	char SendBuf[Max_length];
	//收发消息
	while (1){
		//清理接收区
		memset(RecvBuf, 0, 100 * sizeof(char));
		//调用函数size_t recv(int sockfd,void *buff,size_t nbytes,int flags)从流式套接字接收缓存区内容
		//参数1: 套接字
		//参数2：指向缓冲区的指针(自己取的缓冲区)
		//参数3: 缓存区长度，单位为字节
		//参数4: 表示函数的调用方式
		//返回值：接收到的数据长度
		int n = recv(sockfd_Son, (char *)RecvBuf, Max_length, 0);
		if (n > 0){
			//克隆发送方数据
			memset(SendBuf, 0, 100 * sizeof(char));
			memcpy(SendBuf, RecvBuf, 100 * sizeof(char));
			//打印接收到的数据
			RecvBuf[Max_length - 1] = '\0';
			printf("Client:%s\n", RecvBuf);

			

			//调用函数size_t send(int sockfd,void *buff,size_t nbytes,int flags)从流式套接字接收缓存区内容
			//参数1: 套接字
			//参数2：指向缓冲区的指针(自己取的缓冲区)
			//参数3: 发送字节长度，单位为字节
			//参数4: 表示函数的调用方式
			//返回值：成功返回发送的数据长度，错误返回-1
			if (send(sockfd_Son, (char *)SendBuf, n, 0) < 0){
				printf("Failed to return data\n");
			}
			RecvBuf[3] = '\0';
			if (strcmp(RecvBuf,"bye") == 0){
				close(sockfd_Son);
				printf("Disconnect\n");
				break;
			}
		}
	}
	
	return 1;
}
