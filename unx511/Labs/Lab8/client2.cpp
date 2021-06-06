// client2.cpp - C Program for Message Queue (Read/Write) 
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

key_t key2;
int msgid2;

bool is_running;
queue<Message> message2;

void *recv_func2(void *arg);

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
    pthread_t tid2;
  
    //Intercept ctrl-C
    struct sigaction action;

    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    // ftok to generate unique key 
    key2 = ftok("serverclient", 65); 

    // msgget creates a message queue 
    // and returns identifier 
    msgid2 = msgget(key2, 0666 | IPC_CREAT); 

    pthread_mutex_init(&lock_x, NULL);
    is_running=true;
    ret = pthread_create(&tid2, NULL, recv_func2, NULL);
    if(ret!=0) {
        is_running = false;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    int dest=0;
    while(is_running) {
        while(message2.size()>0) {
	    pthread_mutex_lock(&lock_x);
            Message recvMsg=message2.front();
	    message2.pop();
	    pthread_mutex_unlock(&lock_x);
	    cout<<"client 2: from client "<<recvMsg.msgBuf.source<<" "<<recvMsg.msgBuf.buf<<endl;
	}
	//Alternate between client 1 and client 3
	if(dest==3) dest=1;
	else        dest=3;
	Message sendMsg;
        sendMsg.mtype=4;// Send the message to the server for dispatch
	sendMsg.msgBuf.source = 2;
	sendMsg.msgBuf.dest = dest;
        sprintf(sendMsg.msgBuf.buf, "%d: Message from client 2\n", getpid());
	msgsnd(msgid2, &sendMsg, sizeof(sendMsg), 0);
        sleep(1);
    }
    cout<<"client2: quitting..."<<endl;
    pthread_join(tid2, NULL);
    msgctl(msgid2, IPC_RMID, NULL); 

    return 0; 
} 

void *recv_func2(void *arg)
{
    while(is_running) {
        // msgrcv to receive message 
        Message msg;
        msgrcv(msgid2, &msg, sizeof(msg), 2, 0);//extract messages of mtype 2 for client 2
	if(strncmp(msg.msgBuf.buf, "Quit", 4)==0) is_running=false;
	else {
	    pthread_mutex_lock(&lock_x);
            message2.push(msg);
	    pthread_mutex_unlock(&lock_x);
	}
    }
    pthread_exit(NULL);
}
