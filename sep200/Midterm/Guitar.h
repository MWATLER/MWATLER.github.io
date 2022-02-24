//Guitar.h - class declaration for a guitar instrument

#ifndef _GUITAR_H_
#define _GUITAR_H_

#include <iostream>
#include "MusicalItem.h"

class Guitar : public MusicalItem {
public:
	static const int DATA_CHUNK_LEN = 200;
	Guitar(std::string _name, double _cost) : MusicalItem(_name, _cost) {
	}
	virtual bool GenerateData() {
		unsigned char data[DATA_CHUNK_LEN];
		for (int i = 0; i < DATA_CHUNK_LEN; ++i) {
			data[i] = ('g' + i) % 256;
		}
		return MusicalItem::SetData(data, DATA_CHUNK_LEN);
	}
	void display(std::ostream& os) const {
		os << "This is a guitar instrument." << std::endl;
		MusicalItem::display(os);
	}
};

std::ostream& operator<<(std::ostream& os, Guitar& item) {
	item.display(os);
	return os;
}

#endif// _GUITAR_H_