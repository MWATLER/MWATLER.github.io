//server.cpp - Server code for Lab8 with multiple connections
//             and multiple read threads
//
// 19-Nov-20  M. Watler         Created.

#include <arpa/inet.h>
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
const int MAX_CLIENTS=3;
void *recv_func(void *arg);
queue<string> message;
int  numClients;
int  master_fd, cl[MAX_CLIENTS];

/* shared mutex between receive thread and send */
pthread_mutex_t lock_x;

static void signalHandler(int signum)
{
    switch(signum) {
        case SIGINT:
            cout<<"signalHandler("<<signum<<"): SIGINT"<<endl;
            is_running=false;
            break;
       default:
            cout<<"signalHandler("<<signum<<"): unknown"<<endl;
    }
}

int main(int argc, char *argv[])
{
    //Create the socket for inter-process communications
    struct sockaddr_in addr;
    char buf[BUF_LEN];
    int cl[MAX_CLIENTS];
    int len;
    int master_fd,rc;
    int ret;

    //Set up a signal handler to terminate the program gracefully
    struct sigaction action;
    action.sa_handler = signalHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    cout<<"1.main:"<<endl;
    if(argc<2) {
        cout<<"usage: server <port number>"<<endl;
	return -1;
    }
    cout<<"2.main:"<<endl;

    //Create the socket
    memset(&addr, 0, sizeof(addr));
    cout<<"3.main:"<<endl;
    if ( (master_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) < 0) {
        cout << "server: " << strerror(errno) << endl;
        exit(-1);
    }
    cout<<"4.main:"<<endl;

    //Set the socket to this port
    addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
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
    pthread_t tid[MAX_CLIENTS];
    numClients = 0;
    is_running = true;
    while(is_running){
        if(numClients<MAX_CLIENTS) {
            cl[numClients] = accept(master_fd, NULL, NULL);
            if(cl[numClients]>=0) {
                ret = pthread_create(&tid[numClients], NULL, recv_func, &cl[numClients]);
                if(ret!=0) {
                    cout<<"Cannot create receive thread"<<endl;
                    cout<<strerror(errno)<<endl;
                } else {
                   ++numClients;
                }
            }
	}
        while(message.size()>0) {
	    pthread_mutex_lock(&lock_x);
            cout<<message.front()<<endl;
	    message.pop();
	    pthread_mutex_unlock(&lock_x);
	}
        sleep(1);
    }
    memset(buf, 0, BUF_LEN);
    len = sprintf(buf, "Quit")+1;
    for(int i=0; i<numClients; ++i) {
        cout<<"write("<<cl[i]<<", "<<buf<<", "<<len<<");"<<endl;
        ret = write(cl[i], buf, len);
        if(ret==-1) {
            cout<<"server: Write Error"<<endl;
            cout<<strerror(errno)<<endl;
        }
    }
    for(int i=0; i<numClients; ++i) pthread_join(tid[i], NULL);
    close(master_fd);
    for(int i=0; i<numClients; ++i) close(cl[i]);
    return 0;
}

void *recv_func(void *arg)
{
    int conn_fd = *(int *)arg;
    char buf[BUF_LEN];
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    setsockopt(conn_fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

    while(is_running) {
        memset(buf, 0, BUF_LEN);
	cout<<"recv_func: read()"<<endl;
        int ret=read(conn_fd, buf, BUF_LEN);
	if(ret>=0) {
            pthread_mutex_lock(&lock_x);
            message.push(buf);
            pthread_mutex_unlock(&lock_x);
        }
    }
    pthread_exit(NULL);
}
