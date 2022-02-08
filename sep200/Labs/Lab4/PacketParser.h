//PacketParser.h - class declaration for a packet parser

#ifndef _PACKETPARSER_H_
#define _PACKETPARSER_H_

#include <iostream>

class PacketParser {
public:
	virtual bool parse(const char* packet) { return false; };
	virtual void display(std::ostream& os) const {};
	virtual ~PacketParser() {};
};

std::ostream& operator<<(std::ostream& os, PacketParser& parser);

#endif// _PACKETPARSER_H_
