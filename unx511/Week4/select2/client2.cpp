//client.cpp - client code.
//
// 10-Mar-19  M. Watler         Created.

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
const int BUF_LEN=4096;

int main(int argc, char *argv[])
{
    //Set up socket communications
    struct sockaddr_in addr;
    char buf[BUF_LEN];
    int len, ret;
    int fd,rc;

    if(argc<2) {
        cout<<"usage: client <port number>"<<endl;
	return -1;
    }
    cout<<"client("<<getpid()<<"): running..."<<endl;
    memset(&addr, 0, sizeof(addr));
    //Create the socket
    if ( (fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        cout << "client("<<getpid()<<"): "<<strerror(errno)<<endl;
        exit(-1);
    }

    addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    addr.sin_port = htons(atoi(argv[1]));

    //Connect to the local socket
    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        cout << "client("<<getpid()<<"): " << strerror(errno) << endl;
        close(fd);
        exit(-1);
    }

    is_running=true;
    while(is_running) {
        ret = read(fd,buf,BUF_LEN);
        cout<<"client("<<getpid()<<"): read "<<ret<<" bytes"<<endl;
        if(ret<0) {
            cout<<"client("<<getpid()<<"): error reading the socket"<<endl;
            cout<<strerror(errno)<<endl;
        }
	if(strcmp(buf, "Send PID")==0) {
            cout<<"client("<<getpid()<<"): received request send pid"<<endl;
            len = sprintf(buf, "%d", getpid());
            ret = write(fd, buf, len);
            if(ret==-1) {
               cout<<"client("<<getpid()<<"): Write Error"<<endl;
               cout<<strerror(errno)<<endl;
            }
        } else if(strcmp(buf, "Sleep")==0) {
            cout<<"client("<<getpid()<<"): received request to sleep"<<endl;
	    sleep(5);
            cout<<"client("<<getpid()<<"): sleep done"<<endl;
            is_running = false;
        }
    }

    cout<<"client("<<getpid()<<"): stopping..."<<endl;
    close(fd);
    return 0;
}
