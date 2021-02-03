//personalInfo.h - header file for personal information
//
// 26-Jan-21  M. Watler         Created.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class PersonalInfo {
	char* name;
	char* address;
	int age;
public:
	PersonalInfo();//The default constructor
	PersonalInfo(const char* _name, const char* _address, const int _age);
	~PersonalInfo();
	bool setInfo(const char* _name, const char* _address, int _age);
	bool setAddress(const char* _address);
	void displayInfo() const;
};
