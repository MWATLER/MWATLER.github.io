// client3.cpp - C Program for Message Queue (Read/Write) 
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

key_t key3;
int msgid3;

bool is_running;
queue<Message> message3;

void *recv_func3(void *arg);

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
    pthread_t tid3;
  
    //Intercept ctrl-C
    struct sigaction action;

    action.sa_handler = shutdownHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    // ftok to generate unique key 
    key3 = ftok("serverclient", 65); 

    // msgget creates a message queue 
    // and returns identifier 
    msgid3 = msgget(key3, 0666 | IPC_CREAT); 

    pthread_mutex_init(&lock_x, NULL);
    is_running=true;
    ret = pthread_create(&tid3, NULL, recv_func3, NULL);
    if(ret!=0) {
        is_running = false;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    int dest=0;
    while(is_running) {
        while(message3.size()>0) {
	    pthread_mutex_lock(&lock_x);
            Message recvMsg=message3.front();
	    message3.pop();
	    pthread_mutex_unlock(&lock_x);
	    cout<<"client 3: from client "<<recvMsg.msgBuf.source<<" "<<recvMsg.msgBuf.buf<<endl;
	}
	//Alternate between client 1 and client 2
	if(dest==1) dest=2;
	else        dest=1;
	Message sendMsg;
        sendMsg.mtype=4;// Send the message to the server for dispatch
	sendMsg.msgBuf.source = 3;
	sendMsg.msgBuf.dest = dest;
        sprintf(sendMsg.msgBuf.buf, "%d: Message from client 3\n", getpid());
	msgsnd(msgid3, &sendMsg, sizeof(sendMsg), 0);
        sleep(1);
    }
    cout<<"client3: quitting..."<<endl;
    pthread_join(tid3, NULL);
    msgctl(msgid3, IPC_RMID, NULL); 

    return 0; 
} 

void *recv_func3(void *arg)
{
    while(is_running) {
        // msgrcv to receive message 
        Message msg;
        msgrcv(msgid3, &msg, sizeof(msg), 3, 0);//extract messages of mtype 3 for client 3
	if(strncmp(msg.msgBuf.buf, "Quit", 4)==0) is_running=false;
	else {
	    pthread_mutex_lock(&lock_x);
            message3.push(msg);
	    pthread_mutex_unlock(&lock_x);
	}
    }
    pthread_exit(NULL);
}
