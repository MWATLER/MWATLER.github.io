//CorporateInfo.c - function definitions for corporate information

#include "CorporateInfo.h"

bool GetAverageSalary(struct CorporateInfo* corp) {//corp = &corporation
	bool retVal = true;
	double runningTotal = 0;
	int num = 0;
	for (int i = 0; i < NUM_EMPLOYEES && retVal; ++i) {
		if (corp->employee[i].salary < 0) {
			retVal = false;
		}
		else {
			runningTotal += corp->employee[i].salary;
			++num;
		}
	}
	if (retVal) {
		corp->averageSalary = (double)runningTotal / num;
	}
	else {
		corp->averageSalary = INVALID_VALUE;
	}
	return retVal;
}

bool GetAverageAge(struct CorporateInfo* corp) {//corp = &corporation
	bool retVal = true;
	double runningTotal = 0;
	int num = 0;
	for (int i = 0; i < NUM_EMPLOYEES && retVal; ++i) {
		if (corp->employee[i].age < 0) {
			retVal = false;
		}
		else {
			runningTotal += corp->employee[i].age;
			++num;
		}
	}
	if (retVal) {
		corp->averageAge = (double)runningTotal / num;
	}
	else {
		corp->averageAge = INVALID_VALUE;
	}
	return retVal;
}

bool GetMaximumSalary(struct CorporateInfo* corp) {
	bool retVal = true;
	corp->maximumSalary = 0;
	corp->indexMaximumSalary = 0;
	for (int i = 0; i < NUM_EMPLOYEES && retVal; ++i) {
		if (corp->employee[i].salary < 0) {
			retVal = false;
		}
		else {
			if (corp->employee[i].salary > corp->maximumSalary) {
				corp->maximumSalary = corp->employee[i].salary;
				corp->indexMaximumSalary = i;
			}
		}
	}
	if (!retVal) {
		corp->maximumSalary = INVALID_VALUE;
		corp->indexMaximumSalary = INVALID_VALUE;
	}
	return retVal;
}
