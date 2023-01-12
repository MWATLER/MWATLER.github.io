//PacketParserMain.cpp - main program for the packet parser

#include <iostream>
#include "UdpPacketParser.h"
#include "TcpPacketParser.h"

using namespace std;

//For TCP and UDP packets, there is usually an IP header at the front of each, indicating
//where the packet came from, and where the packet is going. The IP header is not included
//in these examples. For more information, see https://cs.fit.edu/~mmahoney/cse4232/tcpip.html

//The TCP Packet
//TCP header(20 bytes)
//    Source port, 16 bits(0 - 65535)
//    Destination port, 16 bits(0 - 65535)
//    Sequence number, 32 bits, number of bytes sent
//    Acknowledgment number, 32 bits, number of bytes received
//    Header length, 8 bits = 40 unless options are used - IGNORE
//    Unused, 2 bits - IGNORE
//    URG, 1 bit, unused - IGNORE
//    ACK, 1 bit, 1 = received sequence through acknowledgment number - IGNORE
//    PSH, 1 bit, unused - IGNORE
//    RST, 1 bit - IGNORE
//    SYN, 1 bit, 1 = opening connection - IGNORE
//    FIN, 1 bit, 1 = closing connection - IGNORE
//    Receiver window size, 16 bits(bytes free in buffer, scaled using option in setup) - IGNORE
//    Checksum of header, 16 bits
//    Urgent pointer, 16 bits, unused - IGNORE2
//    Options, variable length(usually 0) - IGNORE2
//    Length, 16 bits
//    Data, variable length(usually 0 - 1500)
//Data (up to 1500 bytes)

//                       source_port  dest_port    sequence_number        ack_number             ignore         checksum     ignore2   length
const char TcpPacket[] = {0x00,0x05,  0x00,0x06, 0x00,0x00,0x00,0x05, 0x00,0x00,0x00,0x04, 0x00,0x00,0x00,0x00, 0x00,0x3d, 0x00,0x00, 0x00,0x29,
//                                                             data[]
                   0x54,0x68,0x65,0x20,0x72,0x61,0x69,0x6e, 0x20,0x69,0x6e,0x20,0x53,0x70,0x61,0x69,
	               0x6e,0x20,0x69,0x73,0x20,0x6d,0x61,0x69, 0x6e,0x6c,0x79,0x20,0x6f,0x6e,0x20,0x74,
	               0x68,0x65,0x20,0x70,0x6c,0x61,0x6e,0x65, 0x2e};

//The UDP Packet
//Header (8 bytes)
//    Source port, 16 bits(0 - 65535)
//    Destination port, 16 bits(0 - 65535)
//    Length in bytes, 16 bits(0 - 65535)
//    Checksum of header, 16 bits
//Data (up to 65535 bytes)

//                       source_port  dest_port     length    checksum
const char UdpPacket[] = {0x00,0x09,  0x00,0x13,  0x00,0x24, 0x00,0x40,
//                                                            data[]
                    0x54,0x68,0x65,0x20,0x54,0x6f,0x72,0x6f, 0x6e,0x74,0x6f,0x20,0x4d,0x61,0x70,0x6c,
	                0x65,0x20,0x4c,0x65,0x61,0x66,0x73,0x20, 0x6c,0x6f,0x73,0x65,0x20,0x61,0x67,0x61,
	                0x69,0x6e,0x21,0x21};

int main() {
	const int NUM = 2;
	PacketParser* parser[NUM];
	parser[0] = new UdpPacketParser();
	parser[1] = new TcpPacketParser();
	const char* Packet[NUM] = { UdpPacket, TcpPacket };

	for (int i = 0; i < NUM; ++i) {
		bool retVal = parser[i]->parse(Packet[i]);//Packet[0]=UdpPacket, Packet[1]=TcpPacket
		if (!retVal) {
			cout << "Problems parsing packet " << (i + 1) << endl;
		}
		else {
			cout << *parser[i];
		}
	}

	for (int i = 0; i < NUM; ++i) {
		delete parser[i];
	}

	return 0;
}