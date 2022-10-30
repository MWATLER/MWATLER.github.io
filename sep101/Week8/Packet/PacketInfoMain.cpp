//PacketInfoMain.cpp - main program for packet information

#include <stdio.h>
#include "PacketInfo.h"

int main() {
/*	struct PacketInfo {
		int number;
		int len;
		int data[MAX_LEN];
	};*/
	struct PacketInfo packetInfo;
	int packet[] = { 1, 5, 10,11,12,13,14, 2, 4, 17,18,19,20 };

	//parse the first packet
	int* dataPtr = packet;//&packet[0]
	packetInfo.number = *dataPtr++;
	packetInfo.len = *dataPtr++;
	for (int i = 0; i < packetInfo.len; ++i) {
		packetInfo.data[i] = *dataPtr++;
	}

	//print packet information
	printf("packet1 data:");
	for (int i = 0; i < packetInfo.len; ++i) {
		printf(" %d", packetInfo.data[i]);
	}
	printf("\n");

	//parse the second packet
	struct PacketInfo packetInfo2;
	packetInfo2.number = *dataPtr++;
	packetInfo2.len = *dataPtr++;
	for (int i = 0; i < packetInfo2.len; ++i) {
		packetInfo2.data[i] = *dataPtr++;
	}

	//print packet information
	printf("packet2 data:");
	for (int i = 0; i < packetInfo2.len; ++i) {
		printf(" %d", packetInfo2.data[i]);
	}
	printf("\n");
	return 0;
}
//Why didn't we use the following format:
//int index=0;
//int dataPtr[BIG_NUMBER];
//packetInfo1.number=dataPtr[index++];
//packetInfo1.len=dataPtr[index++];
//etc...
//Because parsing with an array/index will cause more machine cycles than with a pointer.
//The program counter has to first go to the top of the array and then jump to the desired element in the array.
//Also, with a large packet, the index can become quite large.
