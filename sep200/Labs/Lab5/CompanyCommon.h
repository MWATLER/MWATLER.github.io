//CompanyCommon.h - structures and functions for the company database

#ifndef _COMPANYBASE_H_
#define _COMPANYBASE_H_

#include <iostream>
#include <string>

struct StandardEmployee {
	std::string name;
	std::string position;
	double baseSalary;
	double profitSharing;
	double performanceBonus;
	double salary;
};

struct ExecutiveEmployee {
	std::string name;
	std::string position;
	double baseSalary;
	double stockOptionDividend;
	double perquisites;//Executive perquisites or "perks" constitute additional compensation for senior executives which are not available to other salaried employees.
	double salary;
};

const int MAX_SIZE = 1000;

//Implement the functions AddPeronnel(), FindPersonnel() and CalculateSalary() here.
//These should work for either type of database.


#endif// _COMPANYBASE_H_
