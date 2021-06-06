// client1.cpp - An exercise with named semaphores and shared memory
//
// 02-Apr-19  M. Watler         Created.
//
#include <errno.h>
#include <iostream>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "client.h"

using namespace std;

int audioWav[]={
    0x5249, 0x4646, 0x3a60, 0x1000, 0x5741, 0x5645, 0x666d, 0x7420,
    0x1000, 0x0000, 0x0100, 0x0200, 0x401f, 0x0000, 0x007d, 0x0000,
    0x0400, 0x1000, 0x6461, 0x7461, 0x345f, 0x1000, 0x8eff, 0x1700,
    0x0fff, 0x0300, 0xe3fe, 0xe3ff, 0x93ff, 0x2c00, 0xceff, 0x0c00
};

int main(void) {
    sem_t *sem_id1;
    key_t          ShmKey;
    int            ShmID;
    struct Memory *ShmPTR;

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
    ShmPTR->status=NOT_READY;

    // Fill the shared memory
    cout<<endl<<"client1: Writing to shared memory"<<endl;
    for(int i=0; i<BUF_LEN; ++i) {
        ShmPTR->data[i]=audioWav[i];
	printf("client1: ShmPTR->data[%02d]: 0x%08X\n", i, ShmPTR->data[i]);
	usleep(10000);
    }
    ShmPTR->status=WRITTEN;
    while(ShmPTR->status!=READ) sleep(1);

    shmdt((void *)ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);
    cout<<"client1: DONE"<<endl;

    return 0;
}
