//CorporateInfoMain.c - main function for corporate information

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CorporateInfo.h"

int main(void) {
	int retVal = 0;
	FILE* fp;
	CorporateInfo corporation;

	//fill the corporate information structure from a file
	fp = fopen("EmployeeDB.txt", "r");
	if (fp == NULL) {
		retVal = -1;
	}
	if (retVal == 0) {
		for (int i = 0; i < NUM_EMPLOYEES && retVal == 0; ++i) {
			fscanf(fp, "%[^\n]s", corporation.employee[i].name);
			while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
			fscanf(fp, "%[^\n]s", corporation.employee[i].position);
			fscanf(fp, "%lf", &corporation.employee[i].salary);
			fscanf(fp, "%lf", &corporation.employee[i].age);
			while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
		}
		fclose(fp);
		corporation.averageSalary = INVALID_VALUE;
		corporation.averageAge = INVALID_VALUE;
		corporation.maximumSalary = INVALID_VALUE;
		corporation.indexMaximumSalary = INVALID_VALUE;
		bool result = corporation.GetAverageSalary();
		if (!result) {
			retVal = -2;
		}
		else {
			printf("The average salary is $%.2lf\n", corporation.averageSalary);
		}

		result = corporation.GetAverageAge();
		if (!result) {
			retVal = -3;
		}
		else {
			printf("The average age is %.2lf years\n", corporation.averageAge);
		}

		result = corporation.GetMaximumSalary();
		if (!result) {
			retVal = -4;
		}
		else {
			printf("The maximum salary is $%.2lf.\n", corporation.maximumSalary);
			printf("This salary belongs to %s, %s, age %.2lf.\n", corporation.employee[corporation.indexMaximumSalary].name,
				corporation.employee[corporation.indexMaximumSalary].position, corporation.employee[corporation.indexMaximumSalary].age);
		}
	}

	return retVal;
}