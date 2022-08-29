//personalInfo.cpp - get and set personal information
//
// 26-Jan-21  M. Watler         Created.

#include "personalInfo.h"//includes iostream

using namespace std;

PersonalInfo::PersonalInfo() {
	cout << "PersonalInfo::PersonalInfo:" << endl;
	//initializes all variables to an empty state
	cout << name << " " << address << " " << age << endl;
	name = "";
	address = "";
	age = 0;
}

PersonalInfo::PersonalInfo(const std::string _name, const std::string _address, const int _age) {
	cout << "PersonalInfo::PersonalInfo(" << _name << ", " << _address << ", " << _age << "):" << endl;
	name = "";
	address = "";
	age = 0;
	bool ret = setInfo(_name, _address, _age);
	if (!ret) cout << "PersonalInfo::PersonalInfo failed to initialize the variables" << endl;
}

bool PersonalInfo::setInfo(const std::string _name, const std::string _address, const int _age) {
	bool retVal = true;
	if (_name.size() <= 0 || _address.size() <= 0 || age < 0) {
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

bool PersonalInfo::setAddress(const std::string _address) {
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

void PersonalInfo::displayInfo() {
	cout.width(20);
	//	cout.fill('0');
	cout.setf(ios::left);
	cout << name << ", " << age << ", " << address << endl;
	cout.unsetf(ios::left);
}

PersonalInfo::~PersonalInfo() {
	cout << "PersonalInfo::~PersonalInfo: " << name << endl;
	//This is done in companies that are concerned about security,
	//so these values won't remain in RAM after your program terminates.
	name = "";
	address = "";
	age = 0;
}

/*
std::std::string name;
std::std::string address;
int age;
*/