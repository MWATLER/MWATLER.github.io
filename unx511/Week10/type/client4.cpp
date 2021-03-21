// client4.cpp - C Program for Message Queue (Read/Write) 
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
queue<Message> message1;
queue<Message> message2;

void *recv_func1(void *arg);
void *recv_func2(void *arg);
void *send_func1(void *arg);
void *send_func2(void *arg);

/* shared mutex between receive thread and send */
pthread_mutex_t lock_x1;
pthread_mutex_t lock_x2;

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_running=false;
	    cout<<"shutdownHandler: SIGINT is_running=false"<<endl;
            break;
    }
}
  
int main() 
{ 
    int ret;
    pthread_t tid[4];
  
    //Set up a signal handler to terminate the program gracefully
    struct sigaction action;
    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    // ftok to generate unique key 
    key = ftok("client3client4", 65); 

    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    if(msgid<0) {
        cout<<"client4: "<<strerror(errno)<<endl;
	return -1;
    }

    pthread_mutex_init(&lock_x1, NULL);
    pthread_mutex_init(&lock_x2, NULL);
    is_running=true;
    ret = pthread_create(&tid[0], NULL, recv_func1, NULL);
    if(ret!=0) {
        cout<<strerror(errno)<<endl;
        is_running = false;
        msgctl(msgid, IPC_RMID, NULL); 
        return -1;
    }
    ret = pthread_create(&tid[1], NULL, recv_func2, NULL);
    if(ret!=0) {
        cout<<strerror(errno)<<endl;
        is_running = false;
        msgctl(msgid, IPC_RMID, NULL); 
        return -1;
    }
    ret = pthread_create(&tid[2], NULL, send_func1, NULL);
    if(ret!=0) {
        cout<<strerror(errno)<<endl;
        is_running = false;
        msgctl(msgid, IPC_RMID, NULL); 
        return -1;
    }
    ret = pthread_create(&tid[3], NULL, send_func2, NULL);
    if(ret!=0) {
        cout<<strerror(errno)<<endl;
        is_running = false;
        msgctl(msgid, IPC_RMID, NULL); 
        return -1;
    }

    int messageNo=1;
    while(is_running) {
        while(message1.size()>0) {
	    pthread_mutex_lock(&lock_x1);
            Message recvMsg=message1.front();
	    message1.pop();
	    pthread_mutex_unlock(&lock_x1);
	    cout<<"client4: received from message type 1: "<<recvMsg.buf<<endl;
	}
        while(message2.size()>0) {
	    pthread_mutex_lock(&lock_x2);
            Message recvMsg=message2.front();
	    message2.pop();
	    pthread_mutex_unlock(&lock_x2);
	    cout<<"client4: received from message type 2: "<<recvMsg.buf<<endl;
	}
	sleep(1);
    }

    cout<<"client4: quitting..."<<endl;
    for(int i=0; i<2; ++i) {
        Message sendMsg;
        sendMsg.mtype=i;
        sprintf(sendMsg.buf, "Quit");
        msgsnd(msgid, &sendMsg, sizeof(sendMsg), 0);
    }

    for(int i=0; i<4; ++i) pthread_join(tid[i], NULL);
    msgctl(msgid, IPC_RMID, NULL); 

    return 0; 
} 

void *send_func1(void *arg)
{
    int messageNo=1;
    while(is_running)
    {
	Message sendMsg;
        sendMsg.mtype=3;
	if(messageNo<=10) {
            sprintf(sendMsg.buf, "client 4: message type 3 Message #%d\n", messageNo++);
	} else {
            sprintf(sendMsg.buf, "Quit");
            is_running=false;
	}
	msgsnd(msgid, &sendMsg, sizeof(sendMsg), 0);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *send_func2(void *arg)
{
    int messageNo=1;
    while(is_running)
    {
	Message sendMsg;
        sendMsg.mtype=4;
	if(messageNo<=10) {
            sprintf(sendMsg.buf, "client 4: message type 4 Message #%d\n", messageNo++);
	} else {
            sprintf(sendMsg.buf, "Quit");
            is_running=false;
	}
	msgsnd(msgid, &sendMsg, sizeof(sendMsg), 0);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *recv_func1(void *arg)
{
    while(is_running) {
        // msgrcv to receive message 
        Message msg;
        msgrcv(msgid, &msg, sizeof(msg), 1, 0); 
	if(strncmp(msg.buf, "Quit", 4)==0) is_running=false;
	else {
	    pthread_mutex_lock(&lock_x1);
            message1.push(msg);
	    pthread_mutex_unlock(&lock_x1);
	}
    }
    pthread_exit(NULL);
}

void *recv_func2(void *arg)
{
    while(is_running) {
        // msgrcv to receive message 
        Message msg;
        msgrcv(msgid, &msg, sizeof(msg), 2, 0); 
	if(strncmp(msg.buf, "Quit", 4)==0) is_running=false;
	else {
	    pthread_mutex_lock(&lock_x2);
            message2.push(msg);
	    pthread_mutex_unlock(&lock_x2);
	}
    }
    pthread_exit(NULL);
}
