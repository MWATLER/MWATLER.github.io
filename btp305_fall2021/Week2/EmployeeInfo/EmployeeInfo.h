//EmployeeInfo.h - class declarations and definitions for an employee

#ifndef _EMPLOYEEINFO_H_
#define _EMPLOYEEINFO_H_

#include <iostream>

enum Err_Status {
	Err_Success,
	Err_Failure
};

class EmployeeInfo {
	std::string name;
	std::string position;
	int age;
public:
	static double runningTotal;//a running total of the ages of the employees
	static int numEmployees;//number of objects of type EmployeeInfo
	EmployeeInfo();
	EmployeeInfo(std::string _name, std::string _position, int _age);
	std::string GetName();
	double GetAverageAge();
	Err_Status PrintInfo();
};

#endif// _EMPLOYEEINFO_H_
