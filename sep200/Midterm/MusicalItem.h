//MusicalItem.h - class declaration for a musical instrument

#ifndef _MUSICALITEM_H_
#define _MUSICALITEM_H_

#include <iostream>

class MusicalItem {
	static const int MAX_DATA_SIZE = 4096;
	std::string name = "";
	double cost = 0.0;
	unsigned char data[MAX_DATA_SIZE] = { 0 };
	int dataLen = 0;
protected:
	//QUESTION 8: Why is SetData() protected?
	bool SetData(unsigned char* data, int size) {
		bool retVal = false;
		//QUESTION 9: What happens if the data array overflows?
		if (dataLen + size < MAX_DATA_SIZE) {
			retVal = true;
			//QUESTION 10: What is memcpy() doing here?
			memcpy(&this->data[dataLen], data, size);
			dataLen += size;
		}
		return retVal;
	}
	std::string GetName() const {
		return name;
	}
	double GetCost() const {
		return cost;
	}
public:
	MusicalItem(std::string _name, double _cost) {
		name = _name;
		cost = _cost;
	}
	//QUESTION 11: Why is GenerateData() declared as virtual?
	virtual bool GenerateData() {
		return true;
	}
	const unsigned char* GetData() {
		dataLen = 0;//reset the data
		return data;
	}
	//QUESTION 12: What changes are required if display() was private?
	virtual void display(std::ostream& os) const {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << "This musical item is called " << name << " and costs $" << cost << "." << std::endl;
	}
};

//QUESTION 13: Which display function is called if the << operator is used as follows in main(): cout << *item[0];
std::ostream& operator<<(std::ostream& os, MusicalItem& item) {
	item.display(os);
	return os;
}

#endif// _MUSICALITEM_H_