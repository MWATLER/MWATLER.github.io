//MathTest3.cpp - main function for math test 3

#include <iostream>
#include "MathCommon.h"
#include "MathAdd.h"
#include "MathMultiply.h"

using namespace std;

int main() {
	const int NUM = 4;
	MathAdd<double> add;
	MathMultiply<int> mult;

	cout << endl;
	double arrAdd[4] = { 4.4, 5.5, 6.6, 2.2 };
	int arrMult[4] = { 5,4,6,2 };

	double dVal = Calculate(add, arrAdd, NUM);
	cout << "Math Add returns " << dVal << endl;

	double iVal = Calculate(mult, arrMult, NUM);
	cout << "Math Multiply returns " << iVal << endl;

	return 0;
}