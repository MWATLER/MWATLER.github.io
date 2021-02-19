//CorporateInfo.c - function definitions for corporate information

#include "CorporateInfo.h"

bool GetAverageSalary(struct CorporateInfo* corp) {
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

bool GetAverageAge(struct CorporateInfo* corp) {
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

void clearKeyboard(void) {
	while (getchar() != '\n');
}
void pause(void) {
	printf("(Press Enter to continue)");
	clearKeyboard();
}

int getInt(void)
{
	int val;
	int rc = 0;
	char nextChar = '\n';
	do {
		rc = scanf("%d%c", &val, &nextChar);
		if (rc == 0 || nextChar != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (rc == 0 || nextChar != '\n');
	return val;
}

double getDouble(void) {
	double val;
	int rc = 0;
	char nextChar = '\n';
	do {
		rc = scanf("%lf%c", &val, &nextChar);
		if (rc == 0 || nextChar != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter a double>: ");
		}
	} while (rc == 0 || nextChar != '\n');
	return val;
}

// Implement each of the following functions.
// Be sure to follow each scanf() with clearKeyboard()
// Be sure to make use of getInt() and getDouble() where appropriate

bool FindEmployeeByName(struct CorporateInfo corp, int* index) {
	//prompt the user for a name, then search through the employee array
	//set index to the index of the employee with that name
	//If not found, print "Employee <name> not found"
	//Return true if employee found, false otherwise
}

void PrintEmployeeInfo(struct CorporateInfo corp, int index) {
	//given the index of the employee in the employee array, print the information for that employee
}

void PrintEmployeesInfo(struct CorporateInfo corp) {
    //print employee information for all employees
}

void CorrectEmployeeName(struct CorporateInfo* corp, int index) {
	//given the index of the employee in the employee array, change the name of that employee
}

void CorrectEmployeeAge(struct CorporateInfo* corp, int index) {
	//given the index of the employee in the employee array, change the age of that employee
}

void ChangeEmployeePosition(struct CorporateInfo* corp, int index) {
	//given the index of the employee in the employee array, change the position of that employee
}

void ChangeEmployeeSalary(struct CorporateInfo* corp, int index) {
	//given the index of the employee in the employee array, change the salary of that employee
}

void WriteToDatabase(struct CorporateInfo corp) {
	//Write employee information for all employees to the file EmployeeDB.txt
}
