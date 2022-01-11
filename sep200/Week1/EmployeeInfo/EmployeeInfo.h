//EmployeeInfo.h - class declarations and definitions for an employee

#ifndef _EMPLOYEEINFO_H_
#define _EMPLOYEEINFO_H_

#include <iostream>

/*
enum Err_Status {
	Err_Success,
	Err_Failure
};
*/

class EmployeeInfo {
	std::string name;
	std::string position;
	int age;
public:
	enum class Err_Status {
		Err_Success,//0
		Err_Failure//1
	};
	static double runningTotal;
	static int numEmployees;
	EmployeeInfo();
	EmployeeInfo(std::string _name, std::string _position, int _age);
	std::string GetName() const;
	double GetAverageAge() const;
	Err_Status PrintInfo() const;
};

#endif// _EMPLOYEEINFO_H_
