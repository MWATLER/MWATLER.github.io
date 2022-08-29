//CorporateInfoMain.c - main function for corporate information

#include "CorporateInfo.h"

int main(void) {
	int retVal = 0;
	FILE* fp;
	struct CorporateInfo corporation;

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

	pause();

	if (retVal == 0) {
		int index;
		bool valid;
		int choice = 0;
		do {//Complete these for lab 6
			system("CLS");
			printf("1. Get Employee Information\n");//find the employee by name, then print out the employee's position, salary and age.
			printf("2. Get All Employee Information\n");//print out the name, position, salary and age for each employee.
			printf("3. Correct Employee Name\n");//find the employee by name, then change the name.
			printf("4. Correct Employee Age\n");//find the employee by name, then change the age.
			printf("5. Change Employee Position\n");//find the employee by name, then change the position.
			printf("6. Change Employee Salary\n");//find the employee by name, then change the salary
			printf("7. Commit to database\n");//Write all changes to the file EmployeeDB.txt
			printf("0. Exit\n\n");
			printf("choice (0-7): ");
			choice = getInt();
			switch (choice) {
			case 1:
				valid = FindEmployeeByName(corporation, &index);
				if (valid) PrintEmployeeInfo(corporation, index);
				break;
			case 2:
				PrintEmployeesInfo(corporation);
				break;
			case 3:
				valid = FindEmployeeByName(corporation, &index);
				if (valid) CorrectEmployeeName(&corporation, index);
				break;
			case 4:
				valid = FindEmployeeByName(corporation, &index);
				if(valid) CorrectEmployeeAge(&corporation, index);
				break;
			case 5:
				valid = FindEmployeeByName(corporation, &index);
				if (valid) ChangeEmployeePosition(&corporation, index);
				break;
			case 6:
				valid = FindEmployeeByName(corporation, &index);
				if (valid) ChangeEmployeeSalary(&corporation, index);
				break;
			case 7:
				WriteToDatabase(corporation);
				break;
			case 0:
				printf("Goodbye\n");
				break;
			default:
				printf("Invalid choice, try again\n");
			}
			pause();
		} while (choice != 0);
	}

	return retVal;
}