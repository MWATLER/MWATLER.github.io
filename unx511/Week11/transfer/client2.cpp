// client2.cpp - An exercise with named semaphores and shared memory
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
#include <unistd.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "client.h"

using namespace std;

int main(void) {
    sem_t *sem_id1;
    key_t          ShmKey;
    int            ShmID;
    struct Memory  *ShmPTR;

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
        cout<<"client2: shmget() error"<<endl;
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
        cout<<"client2: shmat() error"<<endl;
        return -1;
    }

    // initialize named semaphore, can be used between processes
    sem_id1 = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 0);
    sem_post(sem_id1);
    sleep(1);
    sem_wait(sem_id1);
    cout<<endl<<"client2: Reading from shared memory"<<endl;
    while(ShmPTR->status!=WRITTEN) sleep(1);
    for(int i=0; i<BUF_LEN; ++i) {
        printf("client2: ShmPTR->data[%04d]: %08X\n", i, ShmPTR->data[i]);
	usleep(10000);
    }
    ShmPTR->status=READ;
    sem_post(sem_id1);
    sem_close(sem_id1);
    sem_unlink(SEMNAME);

    cout<<endl<<"client2: Writing to shared memory without semaphores"<<endl<<endl;
    ShmPTR->status=NOT_READY;
    sleep(5);
    cout<<endl<<"client2: Writing to shared memory"<<endl;
    for(int i=0; i<BUF_LEN; ++i) {
        ShmPTR->data[i]=0x2000+i;
        printf("client2: ShmPTR->data[%04d]: %08X\n", i, ShmPTR->data[i]);
        usleep(10000);
    }
    ShmPTR->status=WRITTEN;
    //Now wait for client1 to read the memory
    while(ShmPTR->status!=READ) sleep(1);

    shmdt((void *)ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);

    cout<<"client2: DONE"<<endl;

    return 0;
}
