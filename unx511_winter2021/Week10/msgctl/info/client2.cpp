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
    struct msginfo info;
//  struct msginfo {
//      int msgpool; /* Size in kibibytes of buffer pool
//                      used to hold message data;
//                      unused within kernel */
//      int msgmap;  /* Maximum number of entries in message
//                      map; unused within kernel */
//      int msgmax;  /* Maximum number of bytes that can be
//                      written in a single message */
//      int msgmnb;  /* Maximum number of bytes that can be
//                      written to queue; used to initialize
//                      msg_qbytes during queue creation
//                      (msgget(2)) */
//      int msgmni;  /* Maximum number of message queues */
//      int msgssz;  /* Message segment size;
//                      unused within kernel */
//      int msgtql;  /* Maximum number of messages on all queues
//                      in system; unused within kernel */
//      unsigned short int msgseg;
//                   /* Maximum number of segments;
//                      unused within kernel */
//  };

    msgctl(msgid, IPC_INFO, (struct msqid_ds *)&info); 
    cout<<endl<<endl;
    cout<<"Message Queue Info:"<<endl;
    cout<<"msgpool:"<<info.msgpool<<" msgmap:"<<info.msgmap<<" msgmax:"<<info.msgmax<<" msgmnb:"<<info.msgmnb<<endl;
    cout<<"msgmni:"<<info.msgmni<<" msgssz:"<<info.msgssz<<" msgtql:"<<info.msgtql<<" msgseg:"<<info.msgseg<<endl<<endl;

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
	    cout<<"client2: received "<<recvMsg.buf<<endl;
	}
	Message sendMsg;
        sendMsg.mtype=2;// the first message from the queue is removed
	if(messageNo<=10) {
            sprintf(sendMsg.buf, "client 1: Message #%d\n", messageNo++);
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
