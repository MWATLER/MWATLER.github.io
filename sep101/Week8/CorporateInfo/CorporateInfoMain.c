//CorporateInfoMain.c - main function for corporate information

#include "CorporateInfo.h"

int main(void) {
	int retVal = 0;
	FILE* fp=NULL;
	struct CorporateInfo corporation;

	//fill the corporate information structure from a file
//	fp = fopen("EmployeeDB.txt", "r");//non-safe version
	fopen_s(&fp, "EmployeeDB.txt", "r");
	if (fp == NULL) {//failed to open the file
		retVal = -1;
	}
	if (retVal == 0) {
		for (int i = 0; i < NUM_EMPLOYEES && retVal == 0; ++i) {
			fscanf_s(fp, "%[^\n]s", corporation.employee[i].name, BUFSIZE);
			while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
			fscanf_s(fp, "%[^\n]s", corporation.employee[i].position, BUFSIZE);
			fscanf_s(fp, "%lf", &corporation.employee[i].salary);
			fscanf_s(fp, "%lf", &corporation.employee[i].age);
			while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
		}
		fclose(fp);
		corporation.averageSalary = INVALID_VALUE;
		corporation.averageAge = INVALID_VALUE;
		corporation.maximumSalary = INVALID_VALUE;
		corporation.indexMaximumSalary = INVALID_VALUE;
		bool result = GetAverageSalary(&corporation);
		if (!result) {
			retVal = -2;
		}
		else {
			printf("The average salary is $%.2lf\n", corporation.averageSalary);
		}

		result = GetAverageAge(&corporation);
		if (!result) {
			retVal = -3;
		}
		else {
			printf("The average age is %.2lf years\n", corporation.averageAge);
		}

		result = GetMaximumSalary(&corporation);
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