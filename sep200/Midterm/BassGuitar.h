//BassGuitar.h - class declaration for a bass guitar instrument

#ifndef _BASSGUITAR_H_
#define _BASSGUITAR_H_

#include <iostream>
#include "Guitar.h"

class BassGuitar : public Guitar {
public:
	static const int DATA_CHUNK_LEN = 25;
	BassGuitar(std::string _name, double _cost) : Guitar(_name, _cost) {
	}
	virtual bool GenerateData() {
		unsigned char data[DATA_CHUNK_LEN];
		for (int i = 0; i < DATA_CHUNK_LEN; ++i) {
			data[i] = ('b' + i) % 256;
		}
		return MusicalItem::SetData(data, DATA_CHUNK_LEN);
	}
	void display(std::ostream& os) const {
		os << "This is a bass guitar instrument." << std::endl;
		MusicalItem::display(os);
	}
};

std::ostream& operator<<(std::ostream& os, BassGuitar& item) {
	item.display(os);
	return os;
}

#endif// _BASSGUITAR_H_