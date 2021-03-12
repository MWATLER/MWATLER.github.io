// MathTest.cpp - program to test the math features

#include <iostream>
#include "Math.h"

using namespace std;

int main(void)
{
	auto a = 5;//a should become an int
	auto b = 1.2;//b should become a float/double
	int num = 4, den = 5;
	float num2 = 5.5, den2 = 6.2;
	Math math;

	int intVal = math.square(a);
	cout << "The square of " << a << " is " << intVal << endl << endl;

	double doubleVal = math.square(b);
	cout << "The square of " << b << " is " << doubleVal << endl << endl;

	doubleVal = math.square(num, den);
	cout << "The square of " << num << "/" << den << " is " << doubleVal << endl << endl;

	doubleVal = math.square(num2, den2);
	cout << "The square of " << num2 << "/" << den2 << " is " << doubleVal << endl << endl;

	return 0;
}