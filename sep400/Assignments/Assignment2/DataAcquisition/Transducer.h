//Transducer.h - Class declaration for the transducer
//
// History:
// 03-May-22  M. Watler         Created.

#ifndef _TRANSDUCER_H_
#define _TRANSDUCER_H_

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
#include "SeismicData.h"

static void interruptHandler(int signum);

class Transducer {
    bool is_running;
    sem_t *sem_id1;
    key_t  ShmKey;
    int    ShmID;
    struct SeismicMemory *ShmPTR;
    struct sigaction action;

    void createRandByteArray(unsigned char *buf, int size);
public:
    Transducer();
    int run();
    void shutdown();
    static Transducer* instance;
};

#endif// _TRANSDUCER_H_
