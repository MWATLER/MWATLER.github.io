// ScanfFormatting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "EmplInfo.h"

int main()
{
	struct EmplInfo empl;

	GetEmployeeInformation(&empl);//Pass the address of empl to the function
	printf("%s is %d years old and earns $%.2lf annually\n", empl.name, empl.age, empl.salary);//print the results
	return 0;
}

int GetEmployeeInformation(struct EmplInfo* employee) {//The address is received in the pointer employee
	//We want to pass the addresses of name, age and salary to scanf() so scanf() can alter them
	printf("Enter the last name: ");
	scanf("%s", employee->name);//name is an array. It is already an address.
	printf("Enter the age: ");
	scanf("%d", &(employee->age));//age is an integer. Pass the address to scanf.
	printf("Enter the salary: ");
	scanf("%lf", &(employee->salary));//salary is a double. Pass the address to scanf.
	return 0;
}