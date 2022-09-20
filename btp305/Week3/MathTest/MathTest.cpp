// MathTest.cpp - program to test the math features

#include <iostream>
#include "Math.h"

using namespace std;

int main(void)
{
	int a = 5;
	double b = 1.2;
	int num = 11, den = 5;
	float num2 = (float)5.5, den2 = (float)6.2;

	int intVal = square(a);
	cout << "The square of " << a << " is " << intVal << endl << endl;

	double doubleVal = square(b);
	cout << "The square of " << b << " is " << doubleVal << endl << endl;

	intVal = square(num, den);
	cout << "The square of " << num << "/" << den << " is " << intVal << endl << endl;

	float floatVal = square(num2, den2);
	cout << "The square of " << num2 << "/" << den2 << " is " << floatVal << endl << endl;

	return 0;
}