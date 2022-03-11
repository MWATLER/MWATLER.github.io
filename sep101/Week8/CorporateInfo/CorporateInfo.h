//CorporateInfo.h - header file for corporate information

#define NUM_EMPLOYEES 12
#define INVALID_VALUE -1
#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include "EmployeeInfo.h"

struct CorporateInfo {
	struct EmployeeInfo employee[NUM_EMPLOYEES];
	double averageSalary;
	double averageAge;
	double maximumSalary;//the maximum salary
	int indexMaximumSalary;//index to the Employee with the maximum salary
};

bool GetAverageSalary(struct CorporateInfo* corp);
bool GetAverageAge(struct CorporateInfo* corp);
bool GetMaximumSalary(struct CorporateInfo* corp);
