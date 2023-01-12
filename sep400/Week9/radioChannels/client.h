// client.h - Header file for shared memory
//
// 06-Aug-20  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H

const char SEMNAME[]="SemRadio";
const char MEMNAME[]="MemRadio";
const mode_t SEM_PERMS=(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
const int BUF_LEN=220;
const int NUM_CHANNELS=4;

typedef enum memStatus {
    NOT_READY,
    WRITTEN,
    READ
} MemStatus;

struct Channel {
    MemStatus      status;
    unsigned short source;
    char           message[BUF_LEN];
};

struct Memory {
    struct Channel radioChannel[NUM_CHANNELS];
};
#endif//CLIENT_H
