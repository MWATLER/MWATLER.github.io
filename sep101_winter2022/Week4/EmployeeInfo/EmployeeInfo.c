// EmployeeInfo.c : Demo program to demonstrate structures
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "EmployeeInfo.h"
#define CURRENT_YEAR 2022
#define NUM_EMPLOYEES 3
int main(void)
{
	struct EmployeeInformation employee[NUM_EMPLOYEES];
	//	struct EmployeeInformation {
	//		char firstName[30], lastName[30];
	//		int age;
	//		float salary;//annual salary
	//		int yearEmployed;
	//	};
	for (int i = 0; i < NUM_EMPLOYEES; ++i) {
		printf("\nEnter the employee's first name and last name: ");
		scanf("%s %s", employee[i].firstName, employee[i].lastName);
		printf("Enter the employee's age: ");
		scanf("%d", &employee[i].age);
		printf("Enter the employee's salary: $");
		scanf("%f", &employee[i].salary);
		printf("What year was this employee hired: ");
		scanf("%d", &employee[i].yearEmployed);
	}
	printf("\n");

	printf("We have the following employees:\n");
	for (int i = 0; i < NUM_EMPLOYEES; ++i) {
		printf("%s %s is %d years old and earns $%.2f per year\n",
			employee[i].firstName,
			employee[i].lastName,
			employee[i].age,
			employee[i].salary);
		printf("%s %s was hired in %d.\n",
			employee[i].firstName,
			employee[i].lastName,
			employee[i].yearEmployed);
		int yearsAgo = CURRENT_YEAR - employee[i].yearEmployed;
		printf("This was %d year(s) ago.\n\n", yearsAgo);
	}
	return 0;
}

