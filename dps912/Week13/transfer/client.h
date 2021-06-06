// client.h - Header file for named semaphores
//
// 02-Apr-19  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H

const char SEMNAME[]="SemTransfer";
const char MEMNAME[]="MemTransfer";
const mode_t SEM_PERMS=(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
const int BUF_LEN=1024;

typedef enum memStatus {
    NOT_READY,
    WRITTEN,
    READ
} MemStatus;

struct Memory {
    MemStatus status;
    int       data[BUF_LEN];
};
#endif//CLIENT_H
