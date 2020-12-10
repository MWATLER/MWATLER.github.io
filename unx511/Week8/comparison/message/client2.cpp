// client2.cpp - C Program for Message Queue (Read/Write) 
//
// 27-Mar-19  M. Watler         Created.
//
#include <errno.h> 
#include <iostream> 
#include <queue> 
#include <signal.h> 
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <unistd.h>

using namespace std;

const int BUF_LEN=300;

// structure for message queue
typedef struct mymsg {
    long mtype; /* Message type */
    char buf[BUF_LEN];
} Message;

int main() 
{ 
    int ret;
    key_t key;
    int msgid;
    Message msg;
  
    // ftok to generate unique key 
    key = ftok("client1client2", 65); 

    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    if(msgid<0) {
        cout<<"client1: "<<strerror(errno)<<endl;
	return -1;
    }

    bool is_running=true;

    while(is_running) {
        msgrcv(msgid, &msg, sizeof(msg), 1, 0); 
    }

    cout<<"client2: quitting..."<<endl;
    msgctl(msgid, IPC_RMID, NULL); 

    return 0; 
} 
