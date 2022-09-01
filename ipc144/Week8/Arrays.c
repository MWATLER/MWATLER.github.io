// Arrays.c : This file contains functions to manipulate arrays
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY
//
// 31-Oct-2018  M Watler: Created.
// 29-Oct-2019  M Watler: Added personal information to header comments.
// 29-Oct-2019  M Watler: Moved function prototypes into a header file.
// 29-Oct-2019  M Watler: Added the validation of a second set of marks.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Arrays.h"

#define SIZE 10

int main()
{
	int grade[SIZE] = { 66,72,45,50,23, 36,46,61,38,52 };
	int runningTotal = 0;
	int count = 0;
	double curveFactor;
	for (int i = 0; i < SIZE; ++i) {
		runningTotal += grade[i];
		++count;
	}
	printf("The average grade is %.2lf\n", (double)runningTotal / count);
	printf("\n");
	printf("This average is too low. Let's curve the marks.\n");
	printf("By what factor do you want to curve the marks: ");
	scanf("%lf", &curveFactor);
	printf("\n");

	//grade[0] is a value
	//but grade is an address
	//grade and &grade[0] point to the same memory location
	int ret = CurveGenerator(grade, SIZE, curveFactor);
	//In CurveGenerator: int marks[] = grade;//pass by address
	//                   int size = SIZE;//pass by value, not needed. Why? because SIZE has file scope
	//                   double factor = curveFactor;//pass by value

	if (ret == 0) {
		runningTotal = 0;
		count = 0;
		printf("The marks are now:");
		for (int i = 0; i < SIZE; ++i) {
			printf(" %d", grade[i]);
			runningTotal += grade[i];
			++count;
		}
		printf("\n");
		printf("The average grade is now %.2lf\n", (double)runningTotal / count);
	}
	else {
		printf("These marks are uncurveable\n");
	}

    //Run the results through a marks validator
	ret = MarksValidator(grade, SIZE);
	//In MarksValidator: const int marks[] = grade;//pass by address. Why constant? Because,
	//                                                                we can only pass arrays by address, and
	//                                                                we don't want the values in grade[] to change
	//                   int size = SIZE;//pass by value. Not needed. Why? Because SIZE has file scope (it is visible within the entire file).
	if (ret == 0) {
		printf("The marks are valid\n");
	}
	else if (ret == -1) {
		printf("One of the marks is out of range\n");
	}
	else if (ret == -2) {
		printf("Too many perfect marks, these marks are probably not correct\n");
	}
	printf("\n");

	//Let's test a second set of marks
	printf("Let's test a second set of marks\n");
	int grade2[SIZE] = { 66,72,45,50,103, 36,46,61,38,52 };
	ret = MarksValidator(grade2, SIZE);
	if (ret == 0) {
		printf("The marks are valid\n");
	}
	else if (ret == -1) {
		printf("One of the marks is out of range\n");
	}
	else if (ret == -2) {
		printf("Too many perfect marks, these marks are probably not correct\n");
	}
	return 0;
}
