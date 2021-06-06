//client1.cpp - client 1 in the client server application
//
// 30-Jan-19  M. Watler         Created.
//
#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

char socket_path[] = "/tmp/tmp1";

void *recv_func(void *arg);
bool isRunning;

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    char buf[100];
    int fd,rc;

    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_UNIX, SOCK_STREAM | SOCK_NONBLOCK, 0)) == -1) {
        cout << "client1: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
cout << "client1: addr.sun_path: " << addr.sun_path << endl;

cout << "client1: connect()" << endl;
    //Connect to the local socket
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        cout << "client1: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

    isRunning = true;
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, recv_func, &fd);
    if(ret!=0) {
        cout<<"Cannot create receive thread"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }

cout << "client1: read(STDIN_FILENO)" << endl;
    //Read from the standard input (keyboard)
    while( isRunning && (rc=read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
cout << "client1: write:"<<buf<< endl;
        //Write to the socket
        if (write(fd, buf, rc) != rc) {
            if (rc > 0) fprintf(stderr,"partial write");
            else {
                cout << "client1: " << strerror(errno) << endl;
                close(fd);
                exit(-1);
            }
        }
	if(strncmp("quit", buf, 4)==0) {
	    isRunning = false;
	}
	memset(buf,0,100);
    }
   
cout << "client1: close(fd)" << endl;
    close(fd);
    pthread_join(tid, NULL);
    return 0;
}

void *recv_func(void *arg)
{
    int fd = *(int *)arg;
    char buf[100];

cout << "client: read thread" << endl;
    while(isRunning) {
        //Wait for data to read on this local socket file
        memset(buf,0,100);
        int rc=read(fd,buf,sizeof(buf));
	if(rc<0) sleep(1);
	else     cout<<"read: "<<buf<<endl;
    }
    pthread_exit(NULL);

}

