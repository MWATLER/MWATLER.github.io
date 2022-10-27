//ServerMain.cpp - main function for the server

#include <iostream>
#include "Server.h"

int main() {
/*
struct ClientInfo {
	int clientNumber;
	int clientIpAddress[4];
	int clientPort;
};
*/
	ClientInfo clientList[] = {
		{1, 128,16,32,1, 1024},  //client 1  has IP address 128.16.21.1:1024
		{2, 128,16,32,2, 1024},  //client 2  has IP address 128.16.21.2:1024
		{3, 128,16,32,3, 1024},  //client 3  has IP address 128.16.21.3:1024
		{4, 128,16,32,4, 1024},  //client 4  has IP address 128.16.21.4:1024
		{5, 128,16,32,5, 1024},  //client 5  has IP address 128.16.21.5:1024
		{6, 128,16,32,6, 1024},  //client 6  has IP address 128.16.21.6:1024
		{7, 128,16,32,7, 1024},  //client 7  has IP address 128.16.21.7:1024
		{8, 128,16,32,8, 1024},  //client 8  has IP address 128.16.21.8:1024
		{9, 128,16,32,9, 1024},  //client 9  has IP address 128.16.21.9:1024
		{10, 128,16,32,10, 1024},//client 10 has IP address 128.16.21.10:1024
	};

/*
struct ReceivePacket {
	int srcClientNumber;
	int dstClientNumber;
	int len;//length of the data
	unsigned char data[MAX_LEN];
};
*/
	unsigned char dataStream[] = {
		4, 8, 14, 'H','e','l','l','o',' ','C','l','i','e','n','t',' ','8',
		2, 10, 15,'H','e','l','l','o',' ','C','l','i','e','n','t',' ','1','0',
		6, 1, 14, 'H','e','l','l','o',' ','C','l','i','e','n','t',' ','1',
		5, 9, 14, 'H','e','l','l','o',' ','C','l','i','e','n','t',' ','9',
		8, 4, 18, 'G','r','e','e','t','i','n','g','s',' ','C','l','i','e','n','t',' ','4',
		10, 2, 18, 'G','r','e','e','t','i','n','g','s',' ','C','l','i','e','n','t',' ','2',
		1, 6, 18,  'G','r','e','e','t','i','n','g','s',' ','C','l','i','e','n','t',' ','6',
		9, 5, 18,  'G','r','e','e','t','i','n','g','s',' ','C','l','i','e','n','t',' ','5',
		0//end of data stream
	};

/*
struct SendPacket {
	int srcClientNumber;
	int dstIpAddress[4];
	int dstPort;
	int len;
	unsigned char data[MAX_LEN];
};
*/
    ReceivePacket receivePacket;
	SendPacket sendPacket;

	//What normally happens on a server is one thread receives packets, parses it into a structure,
	//then puts that structure on a queue.
	//Another thread pulls the structure off the queue, processes it, then sends it out.
	unsigned char* packetPtr = dataStream;//&dataStream[0]
	while (*packetPtr != 0) {
		//parse the data
		receivePacket.srcClientNumber = *packetPtr++;
		receivePacket.dstClientNumber = *packetPtr++;
		receivePacket.len = *packetPtr++;
		for (int i = 0; i < receivePacket.len; ++i) {
			receivePacket.data[i] = *packetPtr++;
		}

		//put the data into the send packet
		sendPacket.srcClientNumber = receivePacket.srcClientNumber;
		for (int i = 0; i < 4; ++i) {
			sendPacket.dstIpAddress[i] = clientList[receivePacket.dstClientNumber-1].clientIpAddress[i];
		}
		sendPacket.dstPort = clientList[receivePacket.dstClientNumber-1].clientPort;
		sendPacket.len = receivePacket.len;
		for (int i = 0; i < sendPacket.len; ++i) {
			sendPacket.data[i] = receivePacket.data[i];
		}

		//let's print out what is in our sendPacket
		printf("source:%d destination:%d.%d.%d.%d:%d data:", sendPacket.srcClientNumber, 
			sendPacket.dstIpAddress[0], sendPacket.dstIpAddress[1], sendPacket.dstIpAddress[2], sendPacket.dstIpAddress[3], sendPacket.dstPort);
		for (int i = 0; i < sendPacket.len; ++i) {
			printf("%c", sendPacket.data[i]);
		}
		printf("\n\n");

	}

	return 0;
}