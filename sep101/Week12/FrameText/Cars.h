//Cars.h - class declaration for car names

#ifndef _CARS_H_
#define _CARS_H_

#include<iostream>
#include<fstream>

class CarName {
	int numNames;//the size of our list
	std::string *carName;//a list of car names
	std::ifstream file;
public:
	CarName() {
		numNames = 0;
		carName = nullptr;
	}
	void GetNumberOfEntries();//not a const because it changes file and numNames
	void GetEntries();
	void DisplayEntries();
	~CarName();//clean up memory allocation
};

#endif// _CARS_H_
