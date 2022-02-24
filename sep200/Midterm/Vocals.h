//Vocals.h - class declaration for vocals

#ifndef _VOCALS_H_
#define _VOCALS_H_

#include <iostream>
#include "MusicalItem.h"

class Vocals : public MusicalItem {
public:
	static const int DATA_CHUNK_LEN = 50;
	Vocals(std::string _name, double _cost) : MusicalItem(_name, _cost) {
	}
	virtual bool GenerateData() {
		unsigned char data[DATA_CHUNK_LEN];
		for (int i = 0; i < DATA_CHUNK_LEN; ++i) {
			data[i] = ('v' + i) % 256;
		}
		return MusicalItem::SetData(data, DATA_CHUNK_LEN);
	}
	void display(std::ostream& os) const {
		os << "This is a vocal." << std::endl;
		MusicalItem::display(os);
	}
};

std::ostream& operator<<(std::ostream& os, Vocals& item) {
	item.display(os);
	return os;
}

#endif// _VOCALS_H_