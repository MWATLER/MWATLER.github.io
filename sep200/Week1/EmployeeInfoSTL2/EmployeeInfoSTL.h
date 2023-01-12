//EmployeeInfoSTL.h - class declarations and definitions for an employee

#ifndef _EMPLOYEEINFOSTL_H_
#define _EMPLOYEEINFOSTL_H_

#include <iostream>

enum Err_Status {
	Err_Success,
	Err_Failure
};

class EmployeeInfoSTL {
	std::string name;
	std::string position;
	double salary;
//	EmployeeInfoSTL* next;
//	EmployeeInfoSTL* prev;
public:
	static int numEmployees;
	static double runningTotal;
	EmployeeInfoSTL();
	EmployeeInfoSTL(std::string _name, std::string _position, double _salary);
	std::string GetName();
	double GetAverageSalary();
	Err_Status PrintInfo();
};

#endif// _EMPLOYEEINFOSTL_H_
