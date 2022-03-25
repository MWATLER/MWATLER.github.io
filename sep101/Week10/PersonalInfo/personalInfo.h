//personalInfo.h - header file for personal information
//
// 26-Jan-21  M. Watler         Created.

#include <iostream>

class PersonalInfo {
	std::string name;
	std::string address;
	int age;
public:
	PersonalInfo();//The function name for a constructor is the same as the name of
	               //the class. There is no return type!
	PersonalInfo(const std::string _name, const std::string _address, const int _age);
	~PersonalInfo();//The function name for a destructor is the same as the name of
	                //the class, but it has a tilde (~) in front. There is no return type!
	                //The destructor cannot be overloaded. It always takes no arguments.
	bool setInfo(const std::string _name, const std::string _address, int _age);
	bool setAddress(const std::string _address);
	void displayInfo();
};