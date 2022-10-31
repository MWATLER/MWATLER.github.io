//PacketInfoMain.cpp - main program for packet information

#include <stdio.h>
#include "PacketInfo.h"

int main() {
/*	struct PacketInfo {
		int number;
		int len;
		int data[MAX_LEN];
	};*/
	struct PacketInfo packetInfo1;
	int packet[] = { 1, 5, 10,11,12,13,14, 2, 4, 17,18,19,20 };

	//parse the first packet
	int* dataPtr = packet;//&packet[0]
/*	int index = 0;
	packetInfo1.number = packet[index++];
	packetInfo1.len = packet[index++];//slower than by pointer
	for (int i = 0; i < packetInfo1.len; ++i) {
		packetInfo1.data[i] = packet[index++];
	}*/

	packetInfo1.number = *dataPtr++;//post-increment. Return the data then increment the pointer to the next data
	packetInfo1.len = *dataPtr++;
	for (int i = 0; i < packetInfo1.len; ++i) {
		packetInfo1.data[i] = *dataPtr++;
	}

	//print packet information
	printf("packet1 data:");
	for (int i = 0; i < packetInfo1.len; ++i) {
		printf(" %d", packetInfo1.data[i]);
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
//int packet[BIG_NUMBER];
//packetInfo1.number=packet[index++];
//packetInfo1.len=packet[index++];
//etc...
//Because parsing with an array/index will cause more machine cycles than with a pointer.
//The program counter has to first go to the top of the array and then jump to the desired element in the array.
//Also, with a large packet, the index can become quite large.
