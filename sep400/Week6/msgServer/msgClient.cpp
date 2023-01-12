//msgClient.cpp - A client for multi-client text messages
//                The connection protocol is UDP.
//
// For a good tutorial, UDP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html
//                       IP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/index.html
//
// 05-Mar-19  M. Watler         Created.

#include <arpa/inet.h>
#include <queue>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

using namespace std;

const int PORT=1153;
const char IP_ADDR[]="192.168.218.128";//Address of the server
const int BUF_LEN=4096;
bool is_running;

void *recv_func(void *arg);

queue<string> message;

int main(void)
{
    int fd, ret, len;
    struct sockaddr_in servaddr;
    socklen_t addrlen = sizeof(servaddr);
    char buf[BUF_LEN];


    fd=socket(AF_INET, SOCK_DGRAM | SOCK_NONBLOCK, 0);
    if(fd<0) {
        cout<<"Cannot create the socket"<<endl;
	cout<<strerror(errno)<<endl;
	return -1;
    }

    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, IP_ADDR, &servaddr.sin_addr);
    if(ret==0) {
        cout<<"No such address"<<endl;
	cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    servaddr.sin_port = htons(PORT);

    is_running = true;
    pthread_t tid;
    ret = pthread_create(&tid, NULL, recv_func, &fd);
    if(ret!=0) {
        cout<<"Cannot start thread"<<endl;
	cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    char msgText[][64]={"Hello", "Feeling Good", "Feeling Better", "Quit"};
    for(int i=0; i<4; ++i) {
//  while(is_running) {
        len = strlen(msgText[i]);
        ret = sendto(fd, msgText[i], len, 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

	sleep(1);
    }

    is_running=false;
    pthread_join(tid, NULL);
    close(fd);
}

void *recv_func(void *arg)
{
    int fd = *(int *)arg;
    struct sockaddr_in remaddr;
    socklen_t addrlen = sizeof(remaddr);
    char buf[100];

cout << "server: read()" << endl;
    while(is_running) {
        memset(buf,0,100);
        int len = recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&remaddr, &addrlen);
        if(len > 0) {
            cout<<"received "<<len<<" bytes from "<<inet_ntoa(remaddr.sin_addr)<<endl;
            buf[len] = '\0';
            cout<<"received message: "<<buf<<endl;
//          message.push(buf);
        } else sleep(1);
    }
    pthread_exit(NULL);

}

