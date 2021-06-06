// client1.cpp - C Program for Message Queue (Read/Write) 
//
// 27-Mar-20  M. Watler         Created.
//
#include <errno.h> 
#include <iostream> 
#include <queue> 
#include <signal.h> 
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <unistd.h>
#include "client.h"

using namespace std;

key_t key1;
int msgid1;

bool is_running;
queue<Message> message1;

void *recv_func1(void *arg);

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
  
int main() 
{ 
    int ret;
    pthread_t tid1;
  
    //Intercept ctrl-C
    struct sigaction action;

    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    // ftok to generate unique key 
    key1 = ftok("serverclient", 65); 

    // msgget creates a message queue 
    // and returns identifier 
    msgid1 = msgget(key1, 0666 | IPC_CREAT); 

    pthread_mutex_init(&lock_x, NULL);
    is_running=true;
    ret = pthread_create(&tid1, NULL, recv_func1, NULL);
    if(ret!=0) {
        is_running = false;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    int dest=0;
    while(is_running) {
        while(message1.size()>0) {
	    pthread_mutex_lock(&lock_x);
            Message recvMsg=message1.front();
	    message1.pop();
	    pthread_mutex_unlock(&lock_x);
	    cout<<"client 1: from client "<<recvMsg.msgBuf.source<<" "<<recvMsg.msgBuf.buf<<endl;
	}
	//Alternate between client 2 and client 3
	if(dest==2) dest=3;
	else        dest=2;
	Message sendMsg;
        sendMsg.mtype=4;// Send the message to the server for dispatch
	sendMsg.msgBuf.source = 1;
	sendMsg.msgBuf.dest = dest;
        sprintf(sendMsg.msgBuf.buf, "%d: Message from client 1\n", getpid());
	msgsnd(msgid1, &sendMsg, sizeof(sendMsg), 0);
        sleep(1);
    }
    cout<<"client1: quitting..."<<endl;
    pthread_join(tid1, NULL);
    msgctl(msgid1, IPC_RMID, NULL); 

    return 0; 
} 

void *recv_func1(void *arg)
{
    while(is_running) {
        // msgrcv to receive message 
        Message msg;
        msgrcv(msgid1, &msg, sizeof(msg), 1, 0);//extract messages of mtype 1 for client 1
	if(strncmp(msg.msgBuf.buf, "Quit", 4)==0) is_running=false;
	else {
	    pthread_mutex_lock(&lock_x);
            message1.push(msg);
	    pthread_mutex_unlock(&lock_x);
	}
    }
    pthread_exit(NULL);
}
