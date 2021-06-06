// audio.h - header file for the audio packets
//
// 29-Jul-20  M. Watler         Created.
#ifndef AUDIO_H
#define AUDIO_H

const int BUF_LEN=1024;
const int NUM_CHANNELS=6;

typedef enum memStatus {
    WRITTEN=1,
    READ
} MemStatus;

struct Packet {
    MemStatus status;
    int  packetNumber;
    double timeStamp;
    int  len;
    char left[BUF_LEN];
    char right[BUF_LEN];
    char center[BUF_LEN];
    char leftSurround[BUF_LEN];
    char rightSurround[BUF_LEN];
    char lowFrequencyEffects[BUF_LEN];
};

struct AudioDelayInfo {
    int    decoder_number;
    double decoder_delay;
};

void EncryptPacketBuffer(char *buf, int len);
void DecryptPacketBuffer(char *buf, int len);

#endif//AUDIO_H
