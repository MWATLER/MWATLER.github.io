// Math.c : This program demonstrates two math functions
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>
#include "Math.h"//function declarations

int main(void)
{
	int exp;
	double answer;
	double base;

	printf("Enter base : ");
	scanf_s("%lf", &base);
	printf("Enter exponent : ");
	scanf_s("%d", &exp);

	answer = power(base, exp);//power(2.5,3);
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
double power(double base, int exponent)//base=2.5, exponent=3
{
	int i;
	double result;

	result = 1;
	for (i = 0; i < exponent; i++)
		result = result * base;//exponent=3, base=3: 1*3=3, 3*3=9, 9*3=27

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
