//personalInfo.h - header file for personal information
//
// 26-Jan-21  M. Watler         Created.

#include <iostream>

class PersonalInfo2 {
	std::string name;
	std::string address;
	int age;
public:
	PersonalInfo2();//The no-argument constructor
	PersonalInfo2(const std::string _name, const std::string _address, const int _age);
	~PersonalInfo2();
	bool setInfo(const std::string _name, const std::string _address, int _age);
	bool setAddress(const std::string _address);
	void displayInfo();
};