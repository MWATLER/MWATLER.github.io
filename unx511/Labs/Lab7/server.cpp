// server.cpp - C Program for Message Queue (Read/Write) 
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

    //Intercept ctrl-C
    struct sigaction action;

    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);
  
    // ftok to generate unique key 
    key = ftok("serverclient", 65); 

    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 

    pthread_mutex_init(&lock_x, NULL);
    is_running=true;
    ret = pthread_create(&tid, NULL, recv_func, NULL);
    if(ret!=0) {
        is_running = false;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    while(is_running) {
        while(message.size()>0) {
            pthread_mutex_lock(&lock_x);
            Message msg=message.front();
	    message.pop();
	    pthread_mutex_unlock(&lock_x);
	    cout<<"server: received from client "<<msg.msgBuf.source<<" sending to client "<<msg.msgBuf.dest<<endl;
	    if (msg.msgBuf.dest==1) {
                msg.mtype=1;
                msgsnd(msgid, &msg, sizeof(msg), 0); 
	    } else if (msg.msgBuf.dest==2) {
                msg.mtype=2;
                msgsnd(msgid, &msg, sizeof(msg), 0); 
	    } else if(msg.msgBuf.dest==3) {
                msg.mtype=3;
                msgsnd(msgid, &msg, sizeof(msg), 0); 
	    }
	}
        sleep(1);
    }
    Message msg;
    sprintf(msg.msgBuf.buf, "Quit");
    cout<<"server: quitting..."<<endl;
    for(int i=1; i<=3; ++i) {
        msg.msgBuf.dest = i;
	msg.mtype = i;
        msgsnd(msgid, &msg, sizeof(msg), 0);
        sleep(1);
    }
    msgctl(msgid, IPC_RMID, NULL); 
    pthread_join(tid, NULL);
    pthread_mutex_destroy(&lock_x);

    return 0; 
} 

void *recv_func(void *arg)
{
    while(is_running) {
        // msgrcv to receive message 
        Message msg;
        msgrcv(msgid, &msg, sizeof(msg), 4, 0);//the server receives on message type 4 
	pthread_mutex_lock(&lock_x);
	message.push(msg);
	pthread_mutex_unlock(&lock_x);
    }
    pthread_exit(NULL);
}
