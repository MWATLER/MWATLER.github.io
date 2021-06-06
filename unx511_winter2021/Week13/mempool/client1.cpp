// client1.cpp - An exercise with named semaphores and a memory pool
//
// 02-Apr-19  M. Watler         Created.
//
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include "client.h"

using namespace std;

int main(void) {
    sem_t *sem_id1;
    int ret=mkfifo(FIFO, 0666);
    int fd=open(FIFO, O_WRONLY);
    char memPoolStr[64];
    
    memPool = new char32_t[1024];
    //Pass the address of the memory pool to client2
    int len=sprintf(memPoolStr, "%p", memPool);
    write(fd, memPoolStr, len);
    close(fd);
    unlink(FIFO);

    // initialize named semaphore, can be used between processes
    sem_id1 = sem_open(SEMNAME, O_CREAT, SEM_PERMS, 0);
    printf("client1: memPool:%p\n", memPool);

    printf("client1: sem_wait()\n");
    sem_wait(sem_id1);
    char32_t *memPoolPtr=memPool;
    for(int i=0; i<32; ++i) {
        *memPoolPtr=0x100+i;
	++memPoolPtr;
    }
    memPoolPtr=memPool;
    //Fill the memory pool with some values
    printf("\nThe Memory Pool written by client1:\n");
    for(int i=0; i<32; ++i) {
        if(i%8==0) printf("%p:", memPoolPtr);
	printf(" %X", *memPoolPtr);
	if(i%8==3) printf(" ");
	if(i%8==7) printf("\n");
	++memPoolPtr;
    }
    sleep(5);
    printf("client1: sem_post()\n");
    sem_post(sem_id1);
    sleep(1);
    printf("client1: sem_wait()\n");
    sem_wait(sem_id1);
    printf("client1: sem_close() sem_unlink()\n");
    sem_close(sem_id1);
    sem_unlink(SEMNAME);
    delete[] memPool;

    return 0;
}
