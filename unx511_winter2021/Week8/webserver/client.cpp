//client.cpp - Connects to a web-page on the internet. You have to provide the
//             IP address of the webpage and connect via port 80.
//             The IP address of a webpage can be found from WhatIsMyIpAddress at:
//             https://whatismyipaddress.com/hostname-ip
//
//             The program could also use getaddrinfo/getnameinfo to get the IP
//             address of a web-page via its host name.
//
// 02-Mar-19  M. Watler         Created.
//
#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <net/if.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

using namespace std;

const int BUF_LEN=4096;

int main(void)
{
    int fd;
    struct sockaddr_in addr;
    char host[64], ipAddr[20];
    char buf[BUF_LEN];
    int len, ret;
    unsigned short portNum;

    cout<<"Enter the Host Name: ";
    cin>>host;
    cout<<"Enter the IP Address: ";
    cin>>ipAddr;
    cout<<"Enter the Port number: ";
    cin>>portNum;

    fd = socket(PF_INET, SOCK_STREAM, 0);

    memset(&addr, 0, sizeof(addr)); /* create & zero struct */
    addr.sin_family = AF_INET;      /* select internet protocol */
    addr.sin_port = htons(portNum); /* set the port # */
    ret = inet_pton(AF_INET, ipAddr, &addr.sin_addr);
    if(ret==0) {
        cout<<"No such address"<<endl;
	close(fd);
	return -1;
    }

    connect(fd, (struct sockaddr *)&addr, sizeof(addr));
    len=sprintf(buf, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);
    write(fd, buf, len);
    memset(buf,0,BUF_LEN);
    read(fd, buf, BUF_LEN);
    cout<<buf<<endl;
    close(fd);



    return 0;
}
