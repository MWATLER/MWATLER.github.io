// MathTest.cpp - program to test the math features

#include <iostream>
#include "Math.h"

using namespace std;

int main(void)
{
	auto a = 5;
	auto b = 1.2;
	int num = 4, den = 5;

	int intVal = square(a);
	cout << "The square of " << a << " is " << intVal << endl << endl;

	double doubleVal = square(b);
	cout << "The square of " << b << " is " << doubleVal << endl << endl;

	doubleVal = square(num, den);
	cout << "The square of " << num << "/" << den << " is " << doubleVal << endl << endl;

	return 0;
}