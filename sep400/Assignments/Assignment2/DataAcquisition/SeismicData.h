//SeismicData.h - header file for seismic data
//
// History:
// 03-May-22  M. Watler         Created.

#ifndef SEISMICDATA_H_
#define SEISMICDATA_H_

const char SEMNAME[]="SemSeismic";
const char MEMNAME[]="MemSeismic";
const mode_t SEM_PERMS=(S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
const int PACKET_NO_MAX=65536;
const int BUF_LEN=256;
const int BUF2_LEN=32;
const int NUM_DATA=2096;

typedef enum memStatus {
    NOT_READY,
    WRITTEN,
    READ
} MemStatus;

struct SeismicData {
    MemStatus      status;
    unsigned short packetLen;
    char           data[BUF_LEN];
};

struct SeismicMemory {
    unsigned int   packetNo;
    struct SeismicData seismicData[NUM_DATA];
};

#endif//SEISMICDATA_H_
