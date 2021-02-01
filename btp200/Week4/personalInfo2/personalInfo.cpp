//personalInfo.cpp - get and set personal information
//
// 26-Jan-21  M. Watler         Created.

#include "personalInfo.h"//includes iostream

using namespace std;

PersonalInfo::PersonalInfo() {
	name = nullptr;
	address = nullptr;
	age = 0;
}

PersonalInfo::PersonalInfo(const char* _name, const char* _address, const int _age) {
	setInfo(_name, _address, _age);
}

bool PersonalInfo::setInfo(const char* name, const char* address, const int age) {
	bool retVal = true;
	if (strlen(name) <= 0 || strlen(address) <= 0 || age < 0) {
		retVal = false;
		cout << "Invalid information" << endl;
	}
	else {
		int len = strlen(name);
		if (this->name != nullptr) delete this->name;
		this->name = new char[len + 1];
		strcpy(this->name, name);

		len = strlen(address);
		if (this->address != nullptr) delete this->address;
		this->address = new char[len + 1];
		strcpy(this->address, address);

		this->age = age;
	}
	return retVal;
}

bool PersonalInfo::setAddress(const char* address) {
	bool retVal = true;
	if (strlen(address) <= 0) {
		retVal = false;
		cout << "Invalid address" << endl;
	}
	else {
		int len = strlen(address);
		if (this->address != nullptr) delete this->address;
		this->address = new char[len + 1];
		strcpy(this->address, address);
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

PersonalInfo::~PersonalInfo() {
	if (name != nullptr) {
		cout << name << " exiting..." << endl;
		delete name;
		name = nullptr;
	}
	if (address != nullptr) {
		delete address;
		address = nullptr;
	}
}

/*
std::char* name;
std::char* address;
int age;
*/