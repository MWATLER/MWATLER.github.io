//client.cpp - client code with receive and send threads.
//
// 04-Apr-19  M. Watler         Created.

#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <net/if.h>
#include <netinet/in.h>
#include <signal.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

bool is_running;
const int BUF_LEN=1024;

void *recv_func(void *arg);
void *send_func(void *arg);

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_running=false;
            break;
    }
}

int main(int argc, char *argv[])
{
    //Set up socket communications
    struct sockaddr_in addr;
    int ret;
    int fd;

    if(argc<2) {
        cout<<"usage: client <port number>"<<endl;
	return -1;
    }
    signal(SIGINT, shutdownHandler);
    cout<<"client("<<getpid()<<"): running..."<<endl;
    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        cout << "client("<<getpid()<<"): cannot create socket. "<<strerror(errno)<<endl;
        exit(-1);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(atoi(argv[1]));

    //Connect to the local socket
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        cout << "client("<<getpid()<<"): cannot connect. " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

    pthread_t tid[2];
    is_running=true;
    ret = pthread_create(&tid[0], NULL, recv_func, &fd);
    if(ret!=0) {
        cout<<"Cannot create receive thread"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    ret = pthread_create(&tid[1], NULL, send_func, &fd);
    if(ret!=0) {
        is_running=false;
        cout<<"Cannot create send thread"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    cout<<"client("<<getpid()<<"): stopping..."<<endl;
    close(fd);
    return 0;
}

void *recv_func(void *arg)
{
    int recvFd = *(int *)arg;
    char buf[BUF_LEN];
    while(is_running)
    {
        int len = read(recvFd,buf,BUF_LEN);
        if(len<0) sleep(1);
        else {
            cout<<"client("<<getpid()<<"): received "<<buf<<endl;
        }
    }
    pthread_exit(NULL);
}

void *send_func(void *arg)
{
    int sendFd = *(int *)arg;
    char buf[BUF_LEN];
    int len, ret;

    while(is_running){
        cout<<"Enter Something: ";
        fgets(buf, BUF_LEN, stdin);
	len=strlen(buf);
        ret=write(sendFd, buf, len);
        if(ret<0) {
            cout<<"server: Write Error"<<endl;
            cout<<strerror(errno)<<endl;
        }
	if(strncmp(buf, "Quit", 4)==0) is_running=false;
	else sleep(1);
    }

    pthread_exit(NULL);
}

