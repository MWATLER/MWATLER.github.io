// client.cpp - A client that wishes to use the radio
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

int main(int argc, char *argv[]) {
    sem_t *sem_id1;
    key_t          ShmKey;
    int            ShmID;
    struct Memory  *ShmPTR;
    if(argc!=2) {
        cout<<"Usage: client <client_number>"<<endl;
	return -1;
    }
    int clientNo=atoi(argv[1]);

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
        cout<<"client"<<clientNo<<": shmget() error"<<endl;
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
        cout<<"client"<<clientNo<<": shmat() error"<<endl;
        cout<<strerror(errno)<<endl;
        return -1;
    }

    // initialize named semaphore, can be used between processes
    // If O_CREAT is specified, and a semaphore with the given name
    // already exists, then mode and value are ignored.
    sem_id1 = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 0);
    is_running=true;
    while(is_running) {
        sem_wait(sem_id1);
	bool isFound=false;
	int channel;
	//Look for an available channel
	for(channel=0; channel<NUM_CHANNELS && !isFound; ++channel) {
            if(ShmPTR->radioChannel[channel].status==READ) {
                isFound=true;
                ShmPTR->radioChannel[channel].status=NOT_READY;
                ShmPTR->radioChannel[channel].source=clientNo;
                for(int i=0; i<BUF_LEN; i+=22) {
                    //This is 22 bytes
                    sprintf(&ShmPTR->radioChannel[channel].message[i], "client %02d message %03d\n", clientNo, i/22);
                }
                ShmPTR->radioChannel[channel].status=WRITTEN;
            }
        }
	sem_post(sem_id1);
	sleep(0.2);
    }

    cout<<"client"<<clientNo<<": DONE"<<endl;

    return 0;
}
