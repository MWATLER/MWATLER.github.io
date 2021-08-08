// client.h - Header file for shared memory
//
// 06-Aug-20  M. Watler         Created.
//
#ifndef CLIENT_H
#define CLIENT_H

//Processes on a different machine sending to the radio through IP
//Radio IP address
const int RADIO_PORT=1143;
const char RADIO_ADDR[]="192.168.8.130";

//Processes on the same machine sending to the radio through shared memory
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

//The destination IP address of the radio transmissions
const int DEST_PORT=1180;
const char DEST_ADDR[]="192.168.8.130";
struct DestPacket {
    unsigned short source;
    unsigned short packetNo;
    char           message[BUF_LEN];
};

#endif//CLIENT_H
