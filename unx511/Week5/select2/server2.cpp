//server.cpp - Server code with multiple connections
//
// 10-Mar-19  M. Watler         Created.

#include <iostream>
#include <netinet/in.h>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

using namespace std;

bool is_running;
const int BUF_LEN=4096;
const int MAX_CLIENTS=3;

int main(int argc, char *argv[])
{
    //Create the socket for inter-process communications
    struct sockaddr_in addr, cli_addr[MAX_CLIENTS];
    socklen_t clilen;
    char buf[BUF_LEN];
    int len;
    int master_fd,max_fd,cl[MAX_CLIENTS],rc;
    fd_set activefds;
    fd_set readfds;
    int ret;

    if(argc<2) {
        cout<<"usage: server <port number>"<<endl;
	return -1;
    }

    //Create the socket
    memset(&addr, 0, sizeof(addr));
    if ( (master_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) < 0) {
        cout << "server: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(atoi(argv[1]));
    //Set the socket path to a local socket file

    //Bind the socket to this local socket file
    if (bind(master_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(master_fd);
        exit(-1);
    }

    cout<<"Waiting for the client..."<<endl;
    //Listen for a client to connect to this local socket file
    if (listen(master_fd, 5) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(master_fd);
        exit(-1);
    }

    FD_ZERO(&readfds);
    FD_ZERO(&activefds);
    //Add the master_fd to the socket set
    FD_SET(master_fd, &activefds);
    max_fd = master_fd;

    cout<<"client(s) connected to the server"<<endl;
    bool is_running = true;
    int numClients = 0;
    clilen = sizeof(cli_addr[0]);
    is_running = true;
    while(is_running){
	readfds = activefds;
        ret = select(max_fd+1, &readfds, NULL, NULL, NULL);
        if(FD_ISSET(master_fd, &readfds)){//incoming connection
            cl[numClients] = accept(master_fd, (struct sockaddr *) &cli_addr[numClients], &clilen);
            cout<<"server: incoming connection "<<cl[numClients]<<endl;
            FD_SET(cl[numClients], &activefds);
            if(max_fd<cl[numClients]) max_fd=cl[numClients];
	    memset(buf, 0, BUF_LEN);
            len = sprintf(buf, "Send PID")+1;
            ret = write(cl[numClients], buf, len);
            if(ret==-1) {
                cout<<"server: Write Error"<<endl;
                cout<<strerror(errno)<<endl;
            }
	    ++numClients;
        } else if(FD_ISSET(cl[0], &readfds)) {
	    memset(buf, 0, BUF_LEN);
            ret=read(cl[0], buf, BUF_LEN);
            cout<<"Got pid "<<buf<<" from connection 1"<<endl;
	    memset(buf, 0, BUF_LEN);
            len = sprintf(buf, "Sleep")+1;
            ret = write(cl[0], buf, len);
            if(ret==-1) {
                cout<<"server: Write Error"<<endl;
                cout<<strerror(errno)<<endl;
            }
        } else if(FD_ISSET(cl[1], &readfds)) {
	    memset(buf, 0, BUF_LEN);
            ret=read(cl[1], buf, BUF_LEN);
            cout<<"Got pid "<<buf<<" from connection 2"<<endl;
	    memset(buf, 0, BUF_LEN);
            len = sprintf(buf, "Sleep")+1;
            ret = write(cl[1], buf, len);
            if(ret==-1) {
                cout<<"server: Write Error"<<endl;
                cout<<strerror(errno)<<endl;
            }
        } else if(FD_ISSET(cl[2], &readfds)) {
	    memset(buf, 0, BUF_LEN);
            ret=read(cl[2], buf, BUF_LEN);
            cout<<"Got pid "<<buf<<" from connection 3"<<endl;
	    memset(buf, 0, BUF_LEN);
            len = sprintf(buf, "Sleep")+1;
            ret = write(cl[2], buf, len);
            if(ret==-1) {
                cout<<"server: Write Error"<<endl;
                cout<<strerror(errno)<<endl;
            }
	} else {
            sleep(1);
	}
    }
    for(int i=0; i<numClients; ++i) {
        close(cl[i]);
    }
    close(master_fd);
    return 0;
}
