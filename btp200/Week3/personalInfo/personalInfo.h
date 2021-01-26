//personalInfo.h - header file for personal information
//
// 26-Jan-21  M. Watler         Created.

#include <iostream>
class PersonalInfo {
	std::string name;
	std::string address;
	int age;
public:
	bool setInfo(std::string _name, std::string _address, int _age);
	bool setAddress(std::string _address);
	void displayInfo() const;
};
