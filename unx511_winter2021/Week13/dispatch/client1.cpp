// client1.cpp - An exercise with named semaphores and shared memory
//
// 01-Apr-20  M. Watler         Created.
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

    // initialize named semaphore, can be used between processes
    sem_id1 = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 0);
    sem_wait(sem_id1);
    cout<<endl<<"client1: Writing to shared memory"<<endl;
    ShmPTR->packet_no=1;
    ShmPTR->sourceIP[0]=192;
    ShmPTR->sourceIP[1]=168;
    ShmPTR->sourceIP[2]=239;
    ShmPTR->sourceIP[3]=132;
    ShmPTR->sourcePort=1153;
    ShmPTR->destIP[0]=192;
    ShmPTR->destIP[1]=168;
    ShmPTR->destIP[2]=6;
    ShmPTR->destIP[3]=130;
    ShmPTR->destPort=1154;
    sprintf(ShmPTR->message, "This man is Ernest Scribbler... writer of jokes. \
In a few moments, he win have written the funniest joke in \
the world... and, as a consequence, he will die ... laughing.\n");
    sleep(1);
    sem_post(sem_id1);
    sleep(1);

    sem_wait(sem_id1);
    cout<<endl<<"client1: Writing to shared memory"<<endl;
    ShmPTR->packet_no++;
    ShmPTR->sourceIP[0]=192;
    ShmPTR->sourceIP[1]=168;
    ShmPTR->sourceIP[2]=239;
    ShmPTR->sourceIP[3]=132;
    ShmPTR->sourcePort=1153;
    ShmPTR->destIP[0]=192;
    ShmPTR->destIP[1]=168;
    ShmPTR->destIP[2]=6;
    ShmPTR->destIP[3]=130;
    ShmPTR->destPort=1154;
    sprintf(ShmPTR->message, "This morning, shortly after eleven o'clock, comedy struck\
this little house in Dibley Road. Sudden ...violent ... comedy. \
Police have sealed off the area, and Scotland Yard's crack inspector is with me now.\n");
    sleep(1);
    sem_post(sem_id1);
    sleep(1);

    sem_wait(sem_id1);
    cout<<endl<<"client1: Reading from shared memory"<<endl;
    cout<<"client1 received the following:"<<endl;
    cout<<"packet_no:"<<ShmPTR->packet_no<<endl;
    cout<<"source IP:"<<ShmPTR->sourceIP[0]<<"."<<ShmPTR->sourceIP[1]<<"."<<ShmPTR->sourceIP[2]<<"."<<ShmPTR->sourceIP[3]<<":"<<ShmPTR->sourcePort<<endl;
    cout<<"dest   IP:"<<ShmPTR->destIP[0]<<"."<<ShmPTR->destIP[1]<<"."<<ShmPTR->destIP[2]<<"."<<ShmPTR->destIP[3]<<":"<<ShmPTR->destPort<<endl;
    cout<<"message:"<<ShmPTR->message;
    sem_post(sem_id1);

    sem_close(sem_id1);
    sem_unlink(SEMNAME);

    shmdt((void *)ShmPTR);
    shmctl(ShmID, IPC_RMID, NULL);

    cout<<"client1: DONE"<<endl;

    return 0;
}
