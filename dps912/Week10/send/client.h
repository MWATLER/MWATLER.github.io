// client1.h - Header file for Message Queue (Read/Write) 
//
// 26-Mar-19  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H

const int BUF_LEN=64;
const char pathname[]="client1client2";
  
// structure for message queue 
typedef struct mymsg {
    long mtype; /* Message type */
    char buf[BUF_LEN]; 
} Message;

#endif//CLIENT_H
