//server.cpp - Server code for sockets with read and write threads
//
// 04-Apr-19  M. Watler         Created.

#include <iostream>
#include <netinet/in.h>
#include <queue>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

using namespace std;

bool is_running;
const int BUF_LEN=1024;
void *recv_func(void *arg);
void *send_func(void *arg);
queue<string> message;
int cl, master_fd;

/* shared mutex between receive thread and send */
pthread_mutex_t lock_x;

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
    //Create the socket for inter-process communications
    struct sockaddr_in addr;
    int ret;

    if(argc<2) {
        cout<<"usage: server <port number>"<<endl;
	return -1;
    }

    signal(SIGINT, shutdownHandler);

    //Create the socket
    memset(&addr, 0, sizeof(addr));
    if ( (master_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        cout << "server: " << strerror(errno) << endl;
        exit(-1);
    }

    //Set the socket to this port
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(atoi(argv[1]));

    //Bind the socket to this port
    if (bind(master_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(master_fd);
        exit(-1);
    }

    cout<<"Waiting for the client..."<<endl;
    //Listen for a client to connect to this port
    if (listen(master_fd, 5) == -1) {
        cout << "server: " << strerror(errno) << endl;
        close(master_fd);
        exit(-1);
    }

    cout<<"client(s) connected to the server"<<endl;

    /* initialize pthread mutex */
    pthread_mutex_init(&lock_x, NULL);

    /* start the receive thread */
    pthread_t tid[2];
    is_running=true;
    ret = pthread_create(&tid[0], NULL, recv_func, NULL);
    if(ret!=0) {
        cout<<"Cannot create receive thread"<<endl;
        cout<<strerror(errno)<<endl;
        close(master_fd);
        return -1;
    }
    ret = pthread_create(&tid[1], NULL, send_func, NULL);
    if(ret!=0) {
        is_running=false;
        cout<<"Cannot create send thread"<<endl;
        cout<<strerror(errno)<<endl;
        close(master_fd);
        return -1;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock_x);
    close(master_fd);
    return 0;
}

void *recv_func(void *arg)
{
    char buf[BUF_LEN];
    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);

    cl = accept(master_fd, (struct sockaddr *) &cli_addr, &clilen);
    while(is_running) {
        memset(buf, 0, BUF_LEN);
        int ret=read(cl, buf, BUF_LEN);
	if(ret<0) sleep(1);
	else {
           if(strncmp(buf, "Quit", 4)==0) is_running=false;
	   else {
               pthread_mutex_lock(&lock_x);
               message.push(buf);
               pthread_mutex_unlock(&lock_x);
	   }
	}
    }
    pthread_exit(NULL);
}

void *send_func(void *arg)
{
    string recvMsg;
    char buf[BUF_LEN];
    int len, ret;

    while(is_running){
        while(message.size()>0) {
            pthread_mutex_lock(&lock_x);
	    recvMsg=message.front();
            message.pop();
            pthread_mutex_unlock(&lock_x);
            cout<<"server: received "<<recvMsg<<endl;
	    memset(buf, 0, BUF_LEN);
	    len=sprintf(buf, "Received")+1;
	    ret=write(cl, buf, len);
	    if(ret<0) {
                cout<<"server: Write Error"<<endl;
                cout<<strerror(errno)<<endl;
            }
        }
        sleep(1);
    }

    pthread_exit(NULL);
}
