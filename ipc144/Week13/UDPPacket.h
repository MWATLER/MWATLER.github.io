//UDPPacket.h - header file for UDPPacket.c

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: YYZ

//User Datagram Protocol is utilized to send data that doesn't necessarily need to be very 
//reliable.The UDP packet is encapsulated in an IP packet which in turn is encapsulated in
//a PPP packet.Both UDP and IP have checksums octets and the PPP packet has its FCS octets
//however this can only guarantee that the data and the destination are correct.However,
//there is a possibility that this data does not belong to an expected message sequence but
//is rather part of another message that just happened to have the same destination.This issue
//is addressed by the TCP protocol.
//
//UDP is a simple to implement protocol because it does not require to keep track of every
//packet sent or received and it does not need to initiate or end a transmission.Because of
//this it is mainly designed for communications where you either don't care what the response 
//will be or you pretty much know it.UDP messages are generally faster than TCP provided that
//the communication link functions properly.UDP is widely utilized to send DNS(Domain Name Search)
//requests, to exchange chat messages, or to access telephone numbers via Internet.
//
//UDP HEADER FORMAT
//
//OCTET 1, 2	Source Port
//OCTET 3, 4	Destination Port
//OCTET 5, 6	Length
//OCTET 7, 8 	Checksum
//OCTET 9, 10...Data
//
//UDP PACKET(Example)
//
//04 89 00 35 00 2C AB B4 00 01 01 00 00 01 00 00 00 00 00 00 04 70 6F 70 64 02 69 78 06 6E
//65 74 63 6F 6D 03 63 6F 6D 00 00 01 00 01
//
//UDP Header	04 89 00 35 00 2C AB B4
//Data		00 01 01 00 00 01 00 00 00 00 00 00 04 70 6F 70 64 02 69 78 06 6E 65
//          74 63 6F 6D 03 63 6F 6D 00 00 01 00 01
//
//Source Port		04 89
//Destination Port	00 35
//Length			00 2C
//Checksum		    AB B4
//Data			    DNS Message

#define MAX_LEN 2056//The maximum length of a UDP packet could be up to 65535 bytes
#define HEADER_LEN 8//The length of the packet header

struct UDPPacket {
	unsigned int sourcePort;
	unsigned int destPort;
	unsigned int length;
	unsigned int checksum;
	unsigned char data[MAX_LEN-HEADER_LEN];
};