//server.cpp - The server in the client server application
//
// 30-Jan-19  M. Watler         Created.
//
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>

using namespace std;

const char socket_path[] = "/tmp/tmp1";
const int BUF_LEN=100;

int main(int argc, char *argv[]) {
    struct sockaddr_un addr;
    char buf[BUF_LEN];
    int fd,cl,rc;
    bool isRunning = true;

    memset(&addr, 0, sizeof(addr));
    //Create the socket
cout << "server: socket()" << endl;
    if ( (fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
        cout << "server: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
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

cout << "server: read()" << endl;
    //Wait for data to read on this local socket file
    while (isRunning) {
        memset(buf,0,BUF_LEN);
        rc=read(cl,buf,BUF_LEN);
        if(rc<0) isRunning = false;
        else {
            cout << "read " << rc << " bytes: " << buf << endl;
            //Continue reading until the client sends "quit"
            if(strncmp("quit", buf, 4)==0) {
                isRunning = false;
            }
        }
    }

cout << "server: unlink("<<socket_path<<"), close(fd), close(cl)" << endl;
    unlink(socket_path);
    close(fd);
    close(cl);
    return 0;
}
