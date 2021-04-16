//Cars.h - class declaration for car names

#ifndef _CARS_H_
#define _CARS_H_

#include<iostream>
#include<fstream>

class CarName {
	int numNames;
	std::string *carName;
	std::ifstream file;
public:
	CarName() {
		numNames = 0;
		carName = nullptr;
	}
	void GetNumberOfEntries();
	void GetEntries();
	void DisplayEntries();
	~CarName();
};

#endif// _CARS_H_
