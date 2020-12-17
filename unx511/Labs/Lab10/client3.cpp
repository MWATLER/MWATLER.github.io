// client3.cpp - An exercise with named semaphores and shared memory
//
// 23-Jul-20  M. Watler         Created.
//
#include <errno.h>
#include <iostream>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "client.h"

using namespace std;
const int CLIENT_NO=3;
bool is_running=true;

static void sigHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_running=false;
            break;
    }
}

int main(void) {
    key_t          ShmKey;
    int            ShmID;
    struct Memory  *ShmPTR;

    //Intercept ctrl-C for controlled shutdown
    struct sigaction action;
    action.sa_handler = sigHandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    //key_t ftok(const char *pathname, int proj_id);
    //
    //The ftok() function uses the identity of the file named by the given pathname
    //and the least significant 8 bits of proj_id (which must be nonzero) to
    //generate a key_t type suitable for use with msgget(2), semget(2), or shmget(2).
    ShmKey=ftok(MEMNAME, 65);

    //int shmget(key_t key, size_t size, int shmflg);
    //
    //shmget() returns the identifier of the shared memory segment associated with
    //the value of the argument key.
    //struct Memory {
    //    int           packet_no;
    //    unsigned char sourceIP[4];
    //    unsigned char destIP[4];
    //    char          message[BUF_LEN];
    //};

    ShmID=shmget(ShmKey, sizeof(struct Memory), IPC_CREAT | 0666);
    if (ShmID < 0) {
        cout<<"client3: shmget() error"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    //void *shmat(int shmid, const void *shmaddr, int shmflg);
    //
    //shmat() attaches the shared memory segment identified by shmid to the
    //address space of the calling process. The attaching address is specified
    //by shmaddr. If shmaddr is NULL, the system chooses a suitable (unused)
    //page-aligned address to attach the segment.
    ShmPTR = (struct Memory *) shmat(ShmID, NULL, 0);
    if (ShmPTR == (void *)-1) {
        cout<<"client3: shmat() error"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    // initialize named semaphore, can be used between processes
    //Client 3 starts everything
    ShmPTR->srcClientNo=CLIENT_NO;
    ShmPTR->destClientNo=1;
    memset(ShmPTR->message, 0, BUF_LEN);
    sprintf(ShmPTR->message, "This is message 0 from client %d\n", CLIENT_NO);

    for(int i=0; i<NUM_MESSAGES && is_running; ++i) {
	if(ShmPTR->destClientNo==CLIENT_NO) {
            cout<<"Client "<<CLIENT_NO<<" has received a message from client "<<ShmPTR->srcClientNo<<":"<<endl;
	    cout<<ShmPTR->message<<endl;
	    //Send a message to client 1 or 2
	    ShmPTR->srcClientNo=CLIENT_NO;
	    ShmPTR->destClientNo=1+i%2;//send a message to client 1 or 2
	    memset(ShmPTR->message, 0, BUF_LEN);
	    sprintf(ShmPTR->message, "This is message %d from client %d\n", i+1, CLIENT_NO);
        }
    }

    shmdt((void *)ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);

    cout<<"client3: DONE"<<endl;

    return 0;
}
