//server.cpp - The server in the client server application
//
// 04-Apr-19  M. Watler         Created.
//
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>

using namespace std;

char socket_path[] = "/tmp/tmp1";
const int MSG_SIZE=30;

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    char buf[MSG_SIZE];
    int fd,cl,rc;
    bool isRunning = true;

    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
        cout << "server: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
    unlink(socket_path);

    //Bind the socket to this local socket file
    if (bind(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

    //Listen for a client to connect to this local socket file
    if (listen(fd, 5) == -1) {
        cout << "server: " << strerror(errno) << endl;
        unlink(socket_path);
        close(fd);
        exit(-1);
    }

    //Accept the client's connection to this local socket file
    if ( (cl = accept(fd, NULL, NULL)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        unlink(socket_path);
        close(fd);
        exit(-1);
    }

    rc=read(cl,buf,MSG_SIZE);
    if(rc<0) {
        cout << "server: " << strerror(errno) << endl;
        unlink(socket_path);
        close(fd);
        exit(-1);
    }
    cout<<"server: received "<<buf<<endl;
    char newBuf[MSG_SIZE];
    memset(newBuf, 0, MSG_SIZE);
    for(int i=0; i<strlen(buf); ++i)
        newBuf[i]=toupper(buf[i]);
    rc=write(cl, newBuf, strlen(newBuf));
    if(rc<0) {
        cout << "server: " << strerror(errno) << endl;
        unlink(socket_path);
        close(fd);
        exit(-1);
    }

    unlink(socket_path);
    close(fd);
    close(cl);
    return 0;
}
