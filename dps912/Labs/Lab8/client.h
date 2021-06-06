// client1.h - Header file for Message Queue (Read/Write) 
//
// 19-Mar-19  M. Watler         Created.
//
#ifndef CLIENT1_H
#define CLIENT1_H

const int BUF_LEN=64;
  
// structure for message queue 
typedef struct mesg_buffer { 
    long source; 
    long dest; 
    char buf[BUF_LEN]; 
} MesgBuffer;

typedef struct mymsg {
    long mtype; /* Message type */
    MesgBuffer msgBuf;
} Message;

#endif//CLIENT1_H
