//server.cpp - The server in the client server application
//
// 30-Jan-19  M. Watler         Created.
//
#include <iostream>
#include <queue>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>

using namespace std;

char socket_path[] = "/tmp/tmp1";
bool isRunning = true;
queue<string> message;
pthread_mutex_t lock_x;

void *recv_func(void *arg);

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    char buf[100];
    int fd,cl,rc;

    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
        cout << "server: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
cout << "server: addr.sun_path:" << addr.sun_path << endl;
    unlink(socket_path);

cout << "server: bind()" << endl;
    //Bind the socket to this local socket file
    if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

cout << "server: listen()" << endl;
    //Listen for a client to connect to this local socket file
    if (listen(fd, 5) == -1) {
        cout << "server: " << strerror(errno) << endl;
        unlink(socket_path);
        close(fd);
        exit(-1);
    }

cout << "server: accept()" << endl;
    //Accept the client's connection to this local socket file
    if ( (cl = accept(fd, NULL, NULL)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        unlink(socket_path);
        close(fd);
        exit(-1);
    }

    pthread_mutex_init(&lock_x, NULL);
    isRunning = true;
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, recv_func, &cl);
    if(ret!=0) {
        cout<<"Cannot create receive thread"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }

    while(isRunning) {
        int size=message.size();
        while(message.size()>0) {
            pthread_mutex_lock(&lock_x);
            string msg=message.front();
	    message.pop();
            pthread_mutex_unlock(&lock_x);
            cout<<message.size()<<"."<<msg<<endl;
	}
	if(size>0) {
cout<<"server: writing to client"<<endl;
            memset(buf,0,100);
            int len=sprintf(buf, "server: received %d messages\n", size)+1;
	    write(cl, buf, len);
	}
	sleep(10);
    }

    cout<<"server: quitting..."<<endl;
    unlink(socket_path);
    close(fd);
    close(cl);
    pthread_join(tid, NULL);
    return 0;
}

void *recv_func(void *arg)
{
    int cl = *(int *)arg;
    char buf[100];

cout << "server: read()" << endl;
    while(isRunning) {
        //Wait for data to read on this local socket file
	memset(buf,0,100);
        int rc=read(cl,buf,sizeof(buf));
        cout<<"read "<<rc<<" bytes"<<endl;
        //Continue reading until the client sends "quit"
        if(strncmp("quit", buf, 4)==0) {
            isRunning = false;
        } else {
            pthread_mutex_lock(&lock_x);
            message.push(buf);
            pthread_mutex_unlock(&lock_x);
	}
    }
    pthread_exit(NULL);

}
