// client.h - Header file for shared memory
//
// 04-Apr-19  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H

const char MEMNAME[]="AudioMem";
const int BUF_LEN=32;

typedef enum {
    NOT_READY=0,
    WRITTEN,
    READ
} STATUS;

struct Memory {
    STATUS status;
    int data[BUF_LEN];
};
#endif//CLIENT_H
