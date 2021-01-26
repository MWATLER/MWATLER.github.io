//personalInfo.cpp - get and set personal information
//
// 26-Jan-21  M. Watler         Created.

#include "personalInfo.h"//includes iostream

using namespace std;

bool PersonalInfo::setInfo(string _name, string _address, int _age) {
	bool retVal = true;
	if (_name.size() <= 0 || _address.size() <=0 || _age<0) {
		retVal = false;
		cout << "Invalid information" << endl;
	}
	else {
		name = _name;
		address = _address;
		age = _age;
	}
	return retVal;
}

bool PersonalInfo::setAddress(std::string _address) {
	bool retVal = true;
	if (_address.size() <= 0) {
		retVal = false;
		cout << "Invalid address" << endl;
	}
	else {
		address = _address;
	}
	return retVal;
}

void PersonalInfo::displayInfo() const {
	cout.width(20);
//	cout.fill('0');
	cout.setf(ios::left);
	cout << name << ", " << age << ", " << address << endl;
	cout.unsetf(ios::left);
}


/*
std::string name;
std::string address;
int age;
*/