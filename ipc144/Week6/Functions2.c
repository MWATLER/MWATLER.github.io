// Functions.c : This program demonstrates functions
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Functions2.h"//structure declarations, function declarations

int main(void)
{
	int exp;
	double answer;
	double base;

	printf("Enter base : ");
	scanf("%lf", &base);
	printf("Enter exponent : ");
	scanf("%d", &exp);

	answer = power(base, exp);
	printf("%lf^%d = %lf\n", base, exp, answer);
	printf("%lf squared = %lf\n", base, square(base));

	return 0;
}

//power(): raises a number to an power
//Parameters:
//  base - the base
//  exponent - the exponent
//
//RETURNS:
//  base to the power exponent
double power(double base, int exponent)
{
	int i;
	double result;

	result = 1;
	for (i = 0; i < exponent; i++)
		result = result * base;

	return result;
}

//square(): squares a number
//Parameters:
//  base - the base
//
//RETURNS:
//  The square of base
double square(double base) {
	double result = base * base;
	return result;
}
