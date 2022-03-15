//EmployeeInfoSTL.h - class declarations and definitions for an employee

#ifndef _EMPLOYEEINFOSTL_H_
#define _EMPLOYEEINFOSTL_H_

#include <iostream>

class EmployeeInfoSTL {
	std::string name;
	std::string position;
	double salary;
public:
	enum class Err_Status {
		Err_Success,
		Err_Failure
	};
	static int numEmployees;//the number of objects of type EmployeeInfoSTL
	static double runningTotal;//a running total of the salaries
	EmployeeInfoSTL();
	EmployeeInfoSTL(std::string _name, std::string _position, double _salary);
	std::string GetName() const;
	double GetAverageSalary();
	Err_Status PrintInfo();
};

#endif// _EMPLOYEEINFOSTL_H_
