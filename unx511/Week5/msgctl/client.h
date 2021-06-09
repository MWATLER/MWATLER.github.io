// client1.h - Header file for Message Queue (Read/Write) 
//
// 26-Mar-19  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H

const int BUF_LEN=64;

typedef struct messageinfo {
    int len;
    char buf[BUF_LEN];
} MsgInfo;
  
// structure for message queue 
typedef struct mymsg {
    long mtype; /* Message type */
    MsgInfo msgInfo;
} Message;

#endif//CLIENT_H
