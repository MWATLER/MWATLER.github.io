//personalInfo.cpp - get and set personal information
//
// 26-Jan-21  M. Watler         Created.

#include "personalInfo2.h"//includes iostream

using namespace std;

PersonalInfo2::PersonalInfo2() {
	cout << "PersonalInfo2::PersonalInfo2:" << endl;
	name = "";
	address = "";
	age = 0;
}

PersonalInfo2::PersonalInfo2(const std::string _name, const std::string _address, const int _age) {
	cout << "PersonalInfo2::PersonalInfo2(" << _name << ", " << _address << ", " << _age << "):" << endl;
	name = "";
	address = "";
	age = 0;
	setInfo(_name, _address, _age);
}

bool PersonalInfo2::setInfo(const std::string _name, const std::string _address, const int _age) {
	bool retVal = true;
	if (_name.size() <= 0 || _address.size() <= 0 || age < 0) {
		retVal = false;
		cout << "Invalid information" << endl;
	}
	else {
		name = _name;
		address = _address;
		age = _age;

		this->age = age;
	}
	return retVal;
}

bool PersonalInfo2::setAddress(const std::string _address) {
	bool retVal = true;
	if (address.size() <= 0) {
		retVal = false;
		cout << "Invalid address" << endl;
	}
	else {
		address = _address;
	}
	return retVal;
}

void PersonalInfo2::displayInfo() {
	cout.width(20);
	//	cout.fill('0');
	cout.setf(ios::left);
	cout << name << ", " << age << ", " << address << endl;
	cout.unsetf(ios::left);
}

PersonalInfo2::~PersonalInfo2() {
	cout << "PersonalInfo2::~PersonalInfo2: " << name << endl;
}

/*
std::std::string name;
std::std::string address;
int age;
*/