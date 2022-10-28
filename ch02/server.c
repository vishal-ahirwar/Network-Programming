//Copyright(c)2022 Vishal Ahirwar. All rights reserved.
#if defined(_WIN32)
#ifndef _WIN32_WINT
#define _WIN32_WINT 0x0600
#endif
#include<winsock2.h>
#include<ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
#else
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<errno.h>
#endif

#include<stdio.h>

int main(void)
{
#if defined(_WIN32)
	printf("running on win32...\n");
#else
	printf("running on linux machine...\n");
#endif
	return 0;
};


