//Cars.cpp - function definitions for CarName
#include<string>
#include "Cars.h"

using namespace std;

void CarName::GetNumberOfEntries() {
	file.open("Cars.csv");
	numNames = 0;
    while (file) {//read to the end of the file
		if (file.get() == ',') {
			++numNames;
		}
	}
/*  while (file) {
		std::string temp;
		getline(file, temp, ',');
		if(temp!="") ++numNames;
	}*/
	++numNames;//there is no comma after the last entry
	file.close();
}

void CarName::GetEntries() {
	file.open("Cars.csv");
	if (carName != nullptr) {
		delete[] carName;
	}
	carName = new string[numNames];
	for (int i = 0; i < numNames; ++i) {
		getline(file, carName[i], ',');//the comma is the delimiter
	}
	file.close();
}

void CarName::DisplayEntries() {
	for (int i = 0; i < numNames; ++i) {
		int len = carName[i].length();
		if (i == numNames - 1) --len;//The last entry will have a carriage return appended
		cout.width(len);
		cout.fill('*');
		cout << '*' << endl;
		if (i == numNames - 1) cout << carName[i];//The last entry will have a carriage return appended
		else cout << carName[i] << endl;
		cout.width(len);
		cout.fill('*');
		cout << '*' << endl;
		cout << endl << endl;
	}
}

CarName::~CarName() {
	if (carName != nullptr) {
		delete[] carName;
		carName = nullptr;
	}
}
