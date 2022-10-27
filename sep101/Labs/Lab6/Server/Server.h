//Server.h - header file for the server

#ifndef _SERVER_H_
#define _SERVER_H_

const int MAX_LEN = 2048;

struct ClientInfo {
	int clientNumber;
	int clientIpAddress[4];
	int clientPort;
};

struct ReceivePacket {
	int srcClientNumber;
	int dstClientNumber;
	int len;//length of the data
	unsigned char data[MAX_LEN];
};

struct SendPacket {
	int srcClientNumber;
	int dstIpAddress[4];
	int dstPort;
	int len;
	unsigned char data[MAX_LEN];
};

#endif//_SERVER_H_