// client1.cpp - C Program for Message Queue (Read/Write) 
//
// 26-Mar-19  M. Watler         Created.
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

key_t key;
int msgid;

bool is_running;
queue<Message> message;

void *recv_func(void *arg);

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
    pthread_t tid;
  
    //Set up a signal handler to terminate the program gracefully
    struct sigaction action;
    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    // ftok to generate unique key 
    key = ftok("client1client2", 65); 

    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    if(msgid<0) {
        cout<<"client1: "<<strerror(errno)<<endl;
	return -1;
    }

    pthread_mutex_init(&lock_x, NULL);
    is_running=true;
    ret = pthread_create(&tid, NULL, recv_func, NULL);
    if(ret!=0) {
        is_running = false;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    int messageNo=1;
    while(is_running) {
        while(message.size()>0) {
	    pthread_mutex_lock(&lock_x);
            Message recvMsg=message.front();
	    message.pop();
	    pthread_mutex_unlock(&lock_x);
	    cout<<"client1: received "<<recvMsg.buf<<endl;
	}
	Message sendMsg;
        sendMsg.mtype=1;// the first message from the queue is removed
	if(messageNo<=10) {
            sprintf(sendMsg.buf, "client 1: Message #%d\n", messageNo++);
	    msgsnd(msgid, &sendMsg, sizeof(sendMsg), 0);
	}
        sleep(1);
    }
    cout<<"client1: quitting..."<<endl;
    pthread_join(tid, NULL);
    msgctl(msgid, IPC_RMID, NULL); 

    return 0; 
} 

void *recv_func(void *arg)
{
    while(is_running) {
        // msgrcv to receive message 
        Message msg;
	int ret;
//      ret=msgrcv(msgid, &msg, sizeof(msg), 2, 0); 
        ret=msgrcv(msgid, &msg, sizeof(msg), 2, IPC_NOWAIT); 
	if(ret>=0) {
            pthread_mutex_lock(&lock_x);
            message.push(msg);
            pthread_mutex_unlock(&lock_x);
	} else {
            sleep(1);
	}
    }
    pthread_exit(NULL);
}
