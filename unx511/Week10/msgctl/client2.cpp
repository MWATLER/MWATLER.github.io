// client2.cpp - C Program for Message Queue (Read/Write) 
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
  
    signal(SIGINT, shutdownHandler);
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
	    cout<<"client2: received "<<recvMsg.msgInfo.buf<<endl;
	}
	Message sendMsg;
        sendMsg.mtype=2;// the first message from the queue is removed
	if(messageNo<=10) {
            sendMsg.msgInfo.len=sprintf(sendMsg.msgInfo.buf, "client 2: Message #%d\n", messageNo++)+1;
	    msgsnd(msgid, &sendMsg, sizeof(sendMsg), 0);
	}
        sleep(1);
    }
    cout<<"client2: quitting..."<<endl;
    msgctl(msgid, IPC_RMID, NULL); 
    pthread_join(tid, NULL);

    return 0; 
} 

void *recv_func(void *arg)
{
    while(is_running) {
        // msgrcv to receive message 
        Message msg;
	int ret;
        ret=msgrcv(msgid, &msg, sizeof(msg), 1, 0); 
	if(ret>=0) {
            pthread_mutex_lock(&lock_x);
            message.push(msg);
            pthread_mutex_unlock(&lock_x);
	}
    }
    pthread_exit(NULL);
}
