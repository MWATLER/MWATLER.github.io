// memoryManager.cpp - The shared memory manager. Creates the shared memory for
//                     the radio.
//
// 06-Aug-20  M. Watler         Created.
//
#include <errno.h>
#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "client.h"

using namespace std;
bool is_running;

static void interruptHandler(int signum)
{
    switch(signum) {
        case SIGINT:
            cout<<"interruptHandler("<<signum<<"): SIGINT"<<endl;
            is_running=false;
	    break;
    }
}

int main(void) {
    sem_t *sem_id1;
    key_t          ShmKey;
    int            ShmID;
    struct Memory  *ShmPTR;

    struct sigaction action;

    action.sa_handler = interruptHandler;
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
        cout<<"client1: shmget() error"<<endl;
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
        cout<<"client1: shmat() error"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    // initialize the named semaphore with a value of 4
    sem_unlink(SEMNAME);
    // If O_CREAT is specified in oflag, then the semaphore is
    // created if it does not already exist.
    sem_id1 = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 4);
    int val;
    sem_getvalue(sem_id1, &val);
    cout<<"Initial semaphore value is "<<val<<endl;
    int channel;
    for(channel=0; channel<NUM_CHANNELS; ++channel) {//Initialize all channels to READ
        ShmPTR->radioChannel[channel].status=READ;
    }
    is_running=true;
    while(is_running) {
        bool isFound=false;
        for(channel=0; channel<NUM_CHANNELS; ++channel) {//Go through all the channels
            if(ShmPTR->radioChannel[channel].status==WRITTEN) {
                cout<<"channel "<<channel<<": "<<ShmPTR->radioChannel[channel].message<<endl;
		ShmPTR->radioChannel[channel].status=READ;
		isFound=true;
            }
        }
	if(isFound) cout<<endl<<endl;
        sleep(1);
    }
    sem_close(sem_id1);
    sem_unlink(SEMNAME);

    shmdt((void *)ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);

    cout<<"client1: DONE"<<endl;

    return 0;
}
