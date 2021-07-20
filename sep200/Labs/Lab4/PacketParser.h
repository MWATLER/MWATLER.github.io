//PacketParser.h - class declaration for a packet parser

#ifndef _PACKETPARSER_H_
#define _PACKETPARSER_H_

class PacketParser {
public:
	virtual bool parse(const char* packet) { return false; };
	virtual void Report() {};
	virtual ~PacketParser() {};
};

#endif// _PACKETPARSER_H_
