//EmployeeInfo.cpp - class definitions for an employee

#include "EmployeeInfo.h"

double EmployeeInfo::runningTotal = 0.0;
int EmployeeInfo::numEmployees = 0;

using namespace std;

EmployeeInfo::EmployeeInfo() {
	name = "";
	position = "";
	age = 0;
	++numEmployees;
}

EmployeeInfo::EmployeeInfo(std::string _name, std::string _position, int _age) {
	name = _name;
	position = _position;
	age = _age;
	runningTotal += (double)age;
	++numEmployees;
}

std::string EmployeeInfo::GetName() const {
	return name;
}

double EmployeeInfo::GetAverageAge() const {
	return (double)runningTotal / numEmployees;
}

EmployeeInfo::Err_Status EmployeeInfo::PrintInfo() const {
	Err_Status retVal = Err_Status::Err_Success;
	if (name == "" || position == "" || age <= 0 || numEmployees == 0) retVal = Err_Status::Err_Failure;
	else {
		std::cout << name << " is " << age << " years old and has position " << position << "." << std::endl;
		std::cout << "The average age in this company is " << GetAverageAge() << std::endl << std::endl;
	}
	return retVal;
}