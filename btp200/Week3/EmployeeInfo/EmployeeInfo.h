//EmployeeInfo.h - header file for employment information
//
// 26-Jan-21  M. Watler         Created.

#include <iostream>
class EmployeeInfo {
	std::string name;
	double salary=0;
	int emplNum=0;
public:
	bool setInfo();
	bool setInfo(std::string _name, double _salary, int _emplNum);
	bool changeName(std::string _name);
	bool changeSalary(double _salary);
	bool changeEmployeeNum(int _emplNum);
	void displayInfo() const;
};
