//UDPPacket.c - parses a UDP packet used in network communications

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
	unsigned char *dataPtr = NULL;//We will parse the UDP packet using the dataPtr
	unsigned char rawData[] = {0x04, 0x89, 0x00, 0x35, 0x00, 0x2C, 0xAB, 0xB4,//UDP packet header
		                       0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00,//UDP packet data
		                       0x00, 0x00, 0x00, 0x00, 0x04, 0x70, 0x6F, 0x70,//UDP packet data
		                       0x64, 0x02, 0x69, 0x78, 0x06, 0x6E, 0x65, 0x74,//UDP packet data
		                       0x63, 0x6F, 0x6D, 0x03, 0x63, 0x6F, 0x6D, 0x00,//UDP packet data
		                       0x00, 0x01, 0x00, 0x01};                       //UDP packet data

//OCTET 1, 2	Source Port
//OCTET 3, 4	Destination Port
//OCTET 5, 6	Length
//OCTET 7, 8 	Checksum
//OCTET 9, 10...Data

	system("cls");//Clear the screen
	printf("UDP Packet Analyzer\n\n");

    //Set dataPtr to point to the top of rawData
	dataPtr = rawData;
//	dataPtr = &rawData[0];//This is the same thing

	//The first two octets are the source port.
	packet.sourcePort = (*dataPtr) * 0x100;//The high byte
	++dataPtr;
	packet.sourcePort += *dataPtr;//The low byte

    //Advance dataPtr to point to the destination port
	++dataPtr;
	packet.destPort = (*dataPtr) * 0x100;//high byte
	++dataPtr;
	packet.destPort += *dataPtr;//low byte

	//Advance dataPtr to point to the length of the packet
	++dataPtr;
	packet.length = (*dataPtr) * 0x100;//high byte
	++dataPtr;
	packet.length += *dataPtr;//low byte

	//Advance dataPtr to point to the checksum
	++dataPtr;
	packet.checksum = (*dataPtr) * 0x100;//high byte
	++dataPtr;
	packet.checksum += *dataPtr;//low byte

	//So far, this is what we have
	printf("source port:      %5u\n", packet.sourcePort);
	printf("destination port: %5u\n", packet.destPort);
	printf("length:           %5u\n", packet.length);
	printf("checksum:         %5u\n\n", packet.checksum);

	//Since we know the length of the packet, we can extract the length of the data portion as
	//packet length minus header length. We can use this information in our for-next loop to extract all the data
	unsigned int i;
	for (i = 0; i < packet.length-HEADER_LEN; ++i) {
		//Advance dataPtr and copy each byte into packet.data[]
		++dataPtr;
		packet.data[i] = *dataPtr;
	}

	printf("The data is:\n");
	for (i = 0; i < packet.length - HEADER_LEN; ++i) {
		printf("0x%02X ", packet.data[i]);
		if (i % 8 == 7) printf("\n");//Print 8 bytes per line
	}
	printf("\n\n");

	return 0;
}