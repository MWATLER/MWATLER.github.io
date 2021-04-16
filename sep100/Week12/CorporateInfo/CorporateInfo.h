//CorporateInfo.h - class declaration for corporate information

#ifndef _CORPORATEINFO_H_
#define _CORPORATEINFO_H_

#include <iostream>

const int NUM_EMPLOYEES = 12;
const int INVALID_VALUE = -1;

struct EmployeeInfo {
	std::string name;
	std::string position;
	double salary;
	double age;
};

class CorporateInfo {
	double averageSalary;
	double averageAge;
	double maximumSalary;//the maximum salary
public:
	struct EmployeeInfo employee[NUM_EMPLOYEES];
	bool CalculateAverageSalary();
	bool CalculateAverageAge();
	bool CalculateMaximumSalary();
	//inline getter functions
	double GetAverageSalary() const { return averageSalary;}
	double GetAverageAge() const { return averageAge; }
	double GetMaximumSalary() const { return maximumSalary; }
	//inline setter functions
};
#endif// _CORPORATEINFO_H_