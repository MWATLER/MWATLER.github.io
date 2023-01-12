//server.cpp - The server in the client server application
//
// 27-Mar-19  M. Watler         Created.
//
#include <arpa/inet.h>
#include <iostream>
#include <net/if.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>

using namespace std;

const int PORT=1153;
const char IP_ADDR[]="192.168.218.128";
const int MSG_SIZE=30;

int main(int argc, char *argv[]) {
    struct sockaddr_in myaddr;
    struct sockaddr_in remaddr;
    socklen_t addrlen = sizeof(remaddr);
    char buf[MSG_SIZE];
    int fd,cl,rc;
    bool isRunning = true;

    //Create the socket
    if ( (fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "server: " << strerror(errno) << endl;
        exit(-1);
    }

    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    rc = inet_pton(AF_INET, IP_ADDR, &myaddr.sin_addr);
    if(rc==0) {
        cout<<"No such address"<<endl;
        cout<<strerror(errno)<<endl;
        close(fd);
        return -1;
    }
    myaddr.sin_port = htons(PORT);

cout << "server: bind()" << endl;
    //Bind the socket to this local socket file
    if (bind(fd, (struct sockaddr*)&myaddr, sizeof(myaddr)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

cout << "server: listen()" << endl;
    //Listen for a client to connect to this local socket file
    if (listen(fd, 5) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

cout << "server: accept()" << endl;
        //Accept the client's connection to this local socket file
    if ( (cl = accept(fd, NULL, NULL)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

cout << "server: read()" << endl;
    while (isRunning) {
        rc=read(cl,buf,MSG_SIZE);
    }

cout << "server: close(fd), close(cl)" << endl;
    close(fd);
    close(cl);
    return 0;
}
