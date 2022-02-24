//Keyboard.h - class declaration for a keyboard instrument

#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <iostream>
#include "MusicalItem.h"

class Keyboard : public MusicalItem {
public:
	static const int DATA_CHUNK_LEN = 150;
	Keyboard(std::string _name, double _cost) : MusicalItem(_name, _cost) {
	}
	virtual bool GenerateData() {
		unsigned char data[DATA_CHUNK_LEN];
		for (int i = 0; i < DATA_CHUNK_LEN; ++i) {
			data[i] = ('k' + i) % 256;
		}
		return MusicalItem::SetData(data, DATA_CHUNK_LEN);
	}
	void display(std::ostream& os) const {
		os << "This is a keyboard instrument." << std::endl;
		MusicalItem::display(os);
	}
};

std::ostream& operator<<(std::ostream& os, Keyboard& item) {
	item.display(os);
	return os;
}

#endif// _KEYBOARD_H_