//CorporateInfo.c - function definitions for corporate information

#include "CorporateInfo.h"

bool CorporateInfo::GetAverageSalary() {
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

bool CorporateInfo::GetAverageAge() {
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

bool CorporateInfo::GetMaximumSalary() {
	bool retVal = true;
	maximumSalary = 0;
	indexMaximumSalary = 0;
	for (int i = 0; i < NUM_EMPLOYEES && retVal; ++i) {
		if (employee[i].salary < 0) {
			retVal = false;
		}
		else {
			if (employee[i].salary > maximumSalary) {
				maximumSalary = employee[i].salary;
				indexMaximumSalary = i;
			}
		}
	}
	if (!retVal) {
		maximumSalary = INVALID_VALUE;
		indexMaximumSalary = INVALID_VALUE;
	}
	return retVal;
}
