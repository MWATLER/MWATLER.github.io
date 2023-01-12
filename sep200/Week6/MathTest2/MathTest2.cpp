//MathTest2.cpp - main function for math test 2

#include <iostream>
#include "MathTest2.h"

using namespace std;

int main() {
	const int NUM_MATH = 2;
	const int NUM = 4;
	MathBase<double>* math[NUM_MATH];//array of pointers of static type MathBase
	math[0] = new MathAdd<double, NUM>();//the first pointer points to a MathAdd object
	math[1] = new MathMultiply<double, NUM>();//the second pointer points to a MathMultiply object

	cout << endl;
	double arr[4] = { 4.4, 5.5, 6.6, 2.2 };
	for (int i = 0; i < NUM_MATH; ++i) {
		double retVal = math[i]->Calculate(arr);
		cout << "Calculate returns " << retVal << endl;
	}

	for(int i=0; i<NUM_MATH; ++i) delete math[i];

	return 0;
}