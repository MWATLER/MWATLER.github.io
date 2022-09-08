//EmployeeInfoSTL.cpp - function definitions for an employee

#include "EmployeeInfoSTL.h"

int EmployeeInfoSTL::numEmployees = 0;
double EmployeeInfoSTL::runningTotal = 0.0;

using namespace std;

EmployeeInfoSTL::EmployeeInfoSTL() {
	name = "";
	position = "";
	salary = 0.0;
	++numEmployees;
}

EmployeeInfoSTL::EmployeeInfoSTL(std::string _name, std::string _position, double _salary) {
	name = _name;
	position = _position;
	salary = _salary;
	++numEmployees;
	runningTotal += salary;
}

std::string EmployeeInfoSTL::GetName() {
	return name;
}

double EmployeeInfoSTL::GetAverageSalary() {
	double retVal = 0.0;
	if (numEmployees > 0) retVal = (double)runningTotal / numEmployees;
	return retVal;
}

Err_Status EmployeeInfoSTL::PrintInfo() {
	Err_Status retVal = Err_Success;
	if (name == "" || position == "" || salary <= 0.0 || numEmployees == 0) retVal = Err_Failure;
	else {
		std::cout << name << " earns " << salary << " per year and has position " << position << "." << std::endl;
		std::cout << "The average salary in this company is " << GetAverageSalary() << std::endl << std::endl;
	}
	return retVal;
}
