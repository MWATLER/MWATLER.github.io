//MathTest2.cpp - main function for math test 2

#include <iostream>
#include "MathTest2.h"

using namespace std;

int main() {
	const int NUM_MATH = 2;
	const int NUM = 4;
	MathBase<double>* math[NUM_MATH];
	math[0] = new MathAdd<double, NUM>();
	math[1] = new MathMultiply<double, NUM>();

	cout << endl;
	double arr[4] = { 4.4, 5.5, 6.6, 2.2 };
	double retVal = math[0]->AddSeries(arr);
	cout << "AddSeries returns " << retVal << endl;

	retVal = math[1]->MultiplySeries(arr);
	cout << "MultiplySeries returns " << retVal << endl;

	for(int i=0; i<NUM_MATH; ++i) delete math[i];

	return 0;
}