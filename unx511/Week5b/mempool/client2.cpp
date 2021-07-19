// client2.cpp - An exercise with named semaphores and a memory pool
//
// 02-Apr-19  M. Watler         Created.
//
#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include "client.h"

using namespace std;

const int BUF_LEN=64;

int main(void) {
    sem_t *sem_id1;
    int ret=mkfifo(FIFO, 0666);
    int fd=open(FIFO, O_RDONLY);
    char memPoolStr[BUF_LEN];
    unsigned long long memPoolAddr;
    
    //Read the address of the memory pool passed from client1.
    read(fd, memPoolStr, BUF_LEN);
    close(fd);
    unlink(FIFO);
    memPoolAddr=strtoul(memPoolStr,NULL,16);
    memPool = (char32_t *)memPoolAddr;

    // initialize named semaphore, can be used between processes
    sem_id1 = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 0);
    printf("client2: sem_post()\n");
    sem_post(sem_id1);
    printf("client2: memPoolAddr:%llx\n", memPoolAddr);
    printf("client2: memPool:%p\n", memPool);

    sleep(1);
    printf("client2: sem_wait()\n");
    sem_wait(sem_id1);
    char32_t *memPoolPtr=memPool;
    //Client1 fills the memory pool with some values, and passes the address
    //of the memory pool to client2.
    printf("\nThe Memory Pool read by client2:\n");
    for(int i=0; i<32; ++i) {
        if(i%8==0) printf("%p:", memPoolPtr);
        printf(" %X", *memPoolPtr);
        if(i%8==3) printf(" ");
        if(i%8==7) printf("\n");
        ++memPoolPtr;
    }
    //The above gives a segmentation fault. The address of the memory pool of client1
    //has been passed to client2, therefore it should be possible to read the contents
    //of the memory pool in client2. However, each process has its own virtual address
    //space, so the address passed by client1 will not be the same address when read
    //by client2. THIS DOES NOT WORK.
    //
    //Linux has its own shared memory utilities. It is better to use those.

    printf("client2: sem_post()\n");
    sem_post(sem_id1);
    printf("client2: sem_close() sem_unlink()\n");
    sem_close(sem_id1);
    sem_unlink(SEMNAME);
//  delete[] memPool;

    return 0;
}
