//PacketInfo.h - the packet information structure

#ifndef _PACKETINFO_H_
#define _PACKETINFO_H_

#define MAX_LEN 1024

struct PacketInfo {
	int number;
	int len;
	int data[MAX_LEN];
};

#endif//_PACKETINFO_H_