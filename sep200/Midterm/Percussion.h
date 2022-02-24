//Percussion.h - class declaration for a percussion instrument

#ifndef _PERCUSSION_H_
#define _PERCUSSION_H_

#include <iostream>
#include "MusicalItem.h"

//QUESTION 14: Should the functions for the class Percussion be implemented in a header file?
class Percussion : public MusicalItem {
public:
	//QUESTION 15: Does there have to be an object of type Percussion for the variable DATA_CHUNK_LEN to exist?
	static const int DATA_CHUNK_LEN = 100;
	Percussion(std::string _name, double _cost) : MusicalItem(_name, _cost) {
	}
	//QUESTION 16: Does GenerateData() have to be declared as virtual?
	virtual bool GenerateData() {
		unsigned char data[DATA_CHUNK_LEN];
		for (int i = 0; i < DATA_CHUNK_LEN; ++i) {
			data[i] = ('p' + i) % 256;
		}
		return MusicalItem::SetData(data, DATA_CHUNK_LEN);
	}
	void display(std::ostream& os) const {
		os << "This is a percussion instrument." << std::endl;
		MusicalItem::display(os);
	}
};

std::ostream& operator<<(std::ostream& os, Percussion& item) {
	item.display(os);
	return os;
}
#endif// _PERCUSSION_H_