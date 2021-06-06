//server.cpp - Server code for Lab6 with multiple connections
//
// 24-Feb-19  M. Watler         Created.

#include <iostream>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <vector>

using namespace std;

char socket_path[]="/tmp/lab6";
bool is_running;
const int BUF_LEN=100;
const int MAX_CLIENTS=3;

static void sigHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_running=false;
            break;
    }
}


int main()
{
    //Create the socket for inter-process communications
    struct sockaddr_un addr;
    char buf[BUF_LEN];
    int len;
    int master_fd,max_fd,cl[MAX_CLIENTS],rc;
    fd_set activefds;
    fd_set readfds;
    int ret;

    signal(SIGINT, sigHandler);
    //Create the socket
    memset(&addr, 0, sizeof(addr));
    if ( (master_fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
        cout << "server: " << strerror(errno) << endl;
        exit(-1);
    }

    addr.sun_family = AF_UNIX;
    //Set the socket path to a local socket file
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path)-1);
    unlink(socket_path);

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
        unlink(socket_path);
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
    while(is_running) {
        cout<<"select("<<max_fd+1<<", &readfds)"<<endl;
	readfds = activefds;
        ret = select(max_fd+1, &readfds, NULL, NULL, NULL);
        if(FD_ISSET(master_fd, &readfds)){//incoming connection
            cl[numClients] = accept(master_fd, NULL, NULL);
            cout<<"server: incoming connection "<<cl[numClients]<<endl;
            FD_SET(cl[numClients], &activefds);
            if(max_fd<cl[numClients]) max_fd=cl[numClients];
            cout<<"server: request pid for connection "<<cl[numClients]<<endl;
            len = sprintf(buf, "Pid")+1;
            ret = write(cl[numClients], buf, len);
            if(ret==-1) {
                cout<<"server: Write Error"<<endl;
                cout<<strerror(errno)<<endl;
            }
	    ++numClients;
        } else {
            readfds = activefds;
            cout<<"select("<<max_fd+1<<", &readfds)"<<endl;
            ret = select(max_fd+1, &readfds, NULL, NULL, NULL);
            bool found=false;
            int sock=-1;
            cout<<"server: received a message"<<endl;
            for(int i=0; i<numClients && !found; ++i) {
                ret = FD_ISSET(cl[i], &readfds);
                if(ret!=0) {
                    cout<<"server: message from "<<cl[i]<<endl;
                    found=true;
                    sock = cl[i];
                }
            }
            if(found) {
                ret = read(sock,buf,BUF_LEN);
                if(ret==-1) {
                    cout<<"server: Read Error"<<endl;
                    cout<<strerror(errno)<<endl;
                }
                cout<<"server: read(sock:"<<sock<<", buf:"<<buf<<")"<<endl;
                cout<<"server: request connection "<<sock<<" to quit"<<endl;
                len = sprintf(buf, "Quit")+1;
                ret = write(sock, buf, len);
                if(ret==-1) {
                    cout<<"server: Write Error"<<endl;
                    cout<<strerror(errno)<<endl;
                }
                close(sock);
            }
        }
    }
    close(master_fd);
    unlink(socket_path);
    return 0;
}
