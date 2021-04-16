//CorporateInfo.cpp - function definitions for corporate information

#include "CorporateInfo.h"

bool CorporateInfo::CalculateAverageSalary() {
	bool retVal = true;
	double runningTotal = 0;
	int num = 0;
	for (int i = 0; i < NUM_EMPLOYEES && retVal; ++i) {
		if (employee[i].salary < 0) {
			retVal = false;
		}
		else {
			runningTotal += employee[i].salary;
			++num;
		}
	}
	if (retVal) {
		averageSalary = (double)runningTotal / num;
	}
	else {
		averageSalary = INVALID_VALUE;
	}
	return retVal;
}

bool CorporateInfo::CalculateAverageAge() {
	bool retVal = true;
	double runningTotal = 0;
	int num = 0;
	for (int i = 0; i < NUM_EMPLOYEES && retVal; ++i) {
		if (employee[i].age < 0) {
			retVal = false;
		}
		else {
			runningTotal += employee[i].age;
			++num;
		}
	}
	if (retVal) {
		averageAge = (double)runningTotal / num;
	}
	else {
		averageAge = INVALID_VALUE;
	}
	return retVal;
}

bool CorporateInfo::CalculateMaximumSalary() {
	bool retVal = true;
	maximumSalary = 0;
	for (int i = 0; i < NUM_EMPLOYEES && retVal; ++i) {
		if (employee[i].salary < 0) {
			retVal = false;
		}
		else {
			if (employee[i].salary > maximumSalary) {
				maximumSalary = employee[i].salary;
			}
		}
	}
	if (!retVal) {
		maximumSalary = INVALID_VALUE;
	}
	return retVal;
}
