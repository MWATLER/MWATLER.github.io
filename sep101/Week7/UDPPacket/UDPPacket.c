//UDPPacket.c - parses a UDP packet used in network communications with a text message embedded

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: YYZ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>//for system()
#include "UDPPacket.h"

int main(void)
{
	struct UDPPacket packet;
	unsigned char* dataPtr = NULL;//We will parse the UDP packet using the dataPtr
	unsigned char rawData[] = { 0x04, 0x89, 0x00, 0x35, 0x00, 0xDB, 0xAB, 0xB4,//UDP packet header
		0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x66, 0x72, 0x69, 0x67, 0x68, 0x74,//0x10
		0x65, 0x6e, 0x65, 0x64, 0x20, 0x63, 0x69, 0x74, 0x79, 0x2e, 0x20, 0x4f, 0x76, 0x65, 0x72, 0x20,//0x20
		0x74, 0x68, 0x65, 0x73, 0x65, 0x20, 0x68, 0x6f, 0x75, 0x73, 0x65, 0x73, 0x2c, 0x20, 0x6f, 0x76,//0x30
		0x65, 0x72, 0x20, 0x74, 0x68, 0x65, 0x73, 0x65, 0x20, 0x73, 0x74, 0x72, 0x65, 0x65, 0x74, 0x73,//0x40
		0x20, 0x68, 0x61, 0x6e, 0x67, 0x73, 0x20, 0x61, 0x20, 0x70, 0x61, 0x6c, 0x6c, 0x20, 0x6f, 0x66,//0x50
		0x20, 0x66, 0x65, 0x61, 0x72, 0x2e, 0x20, 0x46, 0x65, 0x61, 0x72, 0x20, 0x6f, 0x66, 0x20, 0x61,//0x60
		0x20, 0x6e, 0x65, 0x77, 0x20, 0x6b, 0x69, 0x6e, 0x64, 0x20, 0x6f, 0x66, 0x20, 0x76, 0x69, 0x6f,//0x70
		0x6c, 0x65, 0x6e, 0x63, 0x65, 0x20, 0x77, 0x68, 0x69, 0x63, 0x68, 0x20, 0x69, 0x73, 0x20, 0x74,//0x80
		0x65, 0x72, 0x72, 0x6f, 0x72, 0x69, 0x7a, 0x69, 0x6e, 0x67, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63,//0x90
		0x69, 0x74, 0x79, 0x2e, 0x20, 0x59, 0x65, 0x73, 0x2c, 0x20, 0x67, 0x61, 0x6e, 0x67, 0x73, 0x20,//0xA0
		0x6f, 0x66, 0x20, 0x6f, 0x6c, 0x64, 0x20, 0x6c, 0x61, 0x64, 0x69, 0x65, 0x73, 0x20, 0x61, 0x74,//0xB0
		0x74, 0x61, 0x63, 0x6b, 0x69, 0x6e, 0x67, 0x20, 0x64, 0x65, 0x66, 0x65, 0x6e, 0x73, 0x65, 0x6c,//0xC0
		0x65, 0x73, 0x73, 0x2c, 0x20, 0x66, 0x69, 0x74, 0x20, 0x79, 0x6f, 0x75, 0x6e, 0x67, 0x20, 0x6d,//0xD0
		0x65, 0x6e, 0x2e };//0xD3                                                                      //UDP packet data

	//0x04, 0x89 -> 0x04 x 0x100 + 89 = 0x0489
//OCTET 1, 2	Source Port
//OCTET 3, 4	Destination Port
//OCTET 5, 6	Length
//OCTET 7, 8 	Checksum
//OCTET 9, 10...Data

	system("cls");//Clear the screen
	printf("UDP Packet Analyzer\n\n");

	//Fill this in
	dataPtr = rawData;//point to the first element in the rawData array
//	dataPtr = &rawData[0];
	packet.sourcePort = (*dataPtr) * 0x0100; //0x04 * 0x0100 = 0x0400
	++dataPtr;//advance the dataPtr to the second element in the rawData array
	packet.sourcePort += *dataPtr;//0x89. We add 0x0400 to 0x89 = 0x0489

	++dataPtr;//advance the dataPtr to the third element in the rawData array
	packet.destPort = (*dataPtr) * 0x0100;
	++dataPtr;//advance the dataPtr to the fourth element in the rawData array
	packet.destPort += *dataPtr;

	++dataPtr;
	packet.length = (*dataPtr) * 0x0100;
	++dataPtr;
	packet.length += *dataPtr;

	++dataPtr;
	packet.checksum = (*dataPtr) * 0x0100;
	++dataPtr;
	packet.checksum += *dataPtr;

	//So far, this is what we have
	printf("source port:      %5u\n", packet.sourcePort);
	printf("destination port: %5u\n", packet.destPort);
	printf("length:           %5u\n", packet.length);
	printf("checksum:         %5u\n\n", packet.checksum);

	//Since we know the length of the packet, we can extract the length of the data portion as
	//packet length minus header length. We can use this information in our for-next loop to extract all the data
	unsigned int i;
	//Fill this in
	for (i = 0; i < packet.length - HEADER_LEN; ++i) {
		++dataPtr;
		packet.data[i] = *dataPtr;
	}
	//Have you seen memcpy()?

	printf("The data is:\n");
	for (i = 0; i < packet.length - HEADER_LEN; ++i) {
		printf("0x%02X ", packet.data[i]);//two digits, zero as filler, hex, capital letters
		if (i % 16 == 15) printf("\n");//Print 16 bytes per line
	}
	printf("\n\n");

	printf("The data as text is:\n");
	for (i = 0; i < packet.length - HEADER_LEN; ++i) {
		printf("%c", packet.data[i]);
		if (i % 64 == 63) printf("\n");//Print 64 characters per line
	}
	printf("\n\n");

	return 0;
}
