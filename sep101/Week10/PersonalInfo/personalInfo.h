//personalInfo.h - header file for personal information
//
// 26-Jan-21  M. Watler         Created.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class PersonalInfo {
	std::string name;
	std::string address;
	int age;
public:
	PersonalInfo();//The default constructor
	PersonalInfo(const std::string _name, const std::string _address, const int _age);
	~PersonalInfo();
	bool setInfo(const std::string _name, const std::string _address, int _age);
	bool setAddress(const std::string _address);
	void displayInfo();
};