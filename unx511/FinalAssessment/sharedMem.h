// sharedMem.h - header file for the shared memory
//
// 29-Jul-21  M. Watler         Created.
#ifndef SHAREDMEM_H
#define SHAREDMEM_H

#include "audio.h"

const int MAX_PACKET_NUMBER=100000;
const int NUM_PACKETS=16384;
const char MEMNAME[]="MemTransfer";
const char SEMNAME[]="FileSem";
const mode_t SEM_PERMS=(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

struct Memory {
    struct Packet packet[NUM_PACKETS];
};

#endif//SHAREDMEM_H
