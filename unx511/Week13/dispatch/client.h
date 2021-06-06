// client.h - Header file for shared memory
//
// 01-Apr-20  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H

const char SEMNAME[]="SemDispatch";
const char MEMNAME[]="MemDispatch";
const mode_t SEM_PERMS=(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
const int BUF_LEN=1024;

struct Memory {
    int            packet_no;
    unsigned short sourceIP[4];
    unsigned short sourcePort;
    unsigned short destIP[4];
    unsigned short destPort;
    char           message[BUF_LEN];
};
#endif//CLIENT_H
