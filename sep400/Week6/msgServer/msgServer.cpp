//msgServer.cpp - The server for multi-client text messages
//                The connection protocol is UDP.
//
// For a good tutorial, UDP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/udp.html
//                       IP sockets: see https://www.cs.rutgers.edu/~pxk/417/notes/sockets/index.html
//
// 05-Mar-19  M. Watler         Created.

#include <arpa/inet.h>
#include <iostream>
#include <queue>
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
const char IP_ADDR[]="192.168.218.128";
const int BUF_LEN=4096;
bool is_running;
struct sockaddr_in remaddr;

void *recv_func(void *arg);

queue<string> message;

pthread_mutex_t lock_x;

int main(void)
{
    int fd, ret, len;
    struct sockaddr_in myaddr;
    socklen_t addrlen = sizeof(remaddr);
    char buf[BUF_LEN];


    fd=socket(AF_INET, SOCK_DGRAM, 0);
    if(fd<0) {
        cout<<"Cannot create the socket"<<endl;
	cout<<strerror(errno)<<endl;
	return -1;
    }

    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    ret = inet_pton(AF_INET, IP_ADDR, &myaddr.sin_addr);
    if(ret==0) {
        cout<<"No such address"<<endl;
	cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    myaddr.sin_port = htons(PORT);

    ret = bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr));
    if(ret<0) {
        cout<<"Cannot bind the socket to the local address"<<endl;
	cout<<strerror(errno)<<endl;
	return -1;
    } else {
#ifdef DEBUG
       cout<<"socket fd:"<<fd<<" bound to address "<<inet_ntoa(myaddr.sin_addr)<<endl;
#endif
    }

    pthread_mutex_init(&lock_x, NULL);
    is_running = true;
    pthread_t tid;
    ret = pthread_create(&tid, NULL, recv_func, &fd);
    if(ret!=0) {
        cout<<"Cannot start thread"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    while(is_running) {
        while(message.size()>0) {
            pthread_mutex_lock(&lock_x);
            message.pop();
            pthread_mutex_unlock(&lock_x);
            memset(buf,0,100);
            len = sprintf(buf, "DONE")+1;
            ret = sendto(fd, buf, len, 0, (struct sockaddr *)&remaddr, sizeof(remaddr));
        }
    }

#ifdef DEBUG
    cout<<"Server is quitting..."<<endl;
#endif
    memset(buf,0,100);
    len = sprintf(buf, "DONE")+1;
    ret = sendto(fd, buf, len, 0, (struct sockaddr *)&remaddr, sizeof(remaddr));
    pthread_join(tid, NULL);
    close(fd);
    pthread_mutex_destroy(&lock_x);
}

void *recv_func(void *arg)
{
    int fd = *(int *)arg;
    socklen_t addrlen = sizeof(remaddr);
    char buf[100];

cout << "server: read()" << endl;
    while(is_running) {
        memset(buf,0,100);
        int len = recvfrom(fd, buf, BUF_LEN, 0, (struct sockaddr *)&remaddr, &addrlen);
        cout<<"received "<<len<<" bytes from "<<inet_ntoa(remaddr.sin_addr)<<endl;
	if(strncmp("Quit",buf,4)==0) is_running=false;
	else if(len > 0) {
            cout<<"received message: "<<buf<<endl;
            pthread_mutex_lock(&lock_x);
            message.push(buf);
            pthread_mutex_unlock(&lock_x);
        }
    }
    pthread_exit(NULL);

}
