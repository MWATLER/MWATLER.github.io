// client1.cpp - C Program for Message Queue (Read/Write) 
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
    key_t key;
    int msgid;
    int ret;
    Message sendMsg;
    sendMsg.mtype=1;
    sprintf(sendMsg.buf, "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz" \
                  "abcdefghijklmnopqrstuvwxyz");
    int msgSize = sizeof(sendMsg);
    timespec ts1, ts2;
    const long nanosecsPerSecond=1000000000;
    double elapsedTime;

    // ftok to generate unique key 
    key = ftok("client1client2", 65); 

    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    if(msgid<0) {
        cout<<"client1: "<<strerror(errno)<<endl;
	return -1;
    }

    clock_gettime(CLOCK_REALTIME, &ts1);
    for(int i=0; i<5000000; ++i) {
	msgsnd(msgid, &sendMsg, msgSize, 0);
    }
    clock_gettime(CLOCK_REALTIME, &ts2);
    elapsedTime = (double)(ts2.tv_sec-ts1.tv_sec)*nanosecsPerSecond + (ts2.tv_nsec-ts1.tv_nsec);
    elapsedTime /= nanosecsPerSecond;
    cout << "The elapsed time with message queues is "<<elapsedTime<<" seconds."<<endl;


    cout<<"client1: quitting..."<<endl;
    msgctl(msgid, IPC_RMID, NULL); 

    return 0; 
} 
