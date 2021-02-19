//CorporateInfo.h - header file for corporate information

#define NUM_EMPLOYEES 12
#define INVALID_VALUE -1
#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>//for system()
#include <string.h>//for strcmp()
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

void clearKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);

bool FindEmployeeByName(struct CorporateInfo corp, int* index);
void PrintEmployeeInfo(struct CorporateInfo corp, int index);
void PrintEmployeesInfo(struct CorporateInfo corp);
void CorrectEmployeeName(struct CorporateInfo* corp, int index);
void CorrectEmployeeAge(struct CorporateInfo* corp, int index);
void ChangeEmployeePosition(struct CorporateInfo* corp, int index);
void ChangeEmployeeSalary(struct CorporateInfo* corp, int index);
void WriteToDatabase(struct CorporateInfo corp);
