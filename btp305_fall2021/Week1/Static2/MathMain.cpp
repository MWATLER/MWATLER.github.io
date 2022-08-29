//MathMain.cpp - main function for square and cubed

#include <iostream>
#include "Squared.h"
#include "Cubed.h"

using namespace std;

int main() {
	double num;

	for (double i = 0.0; i < 3.0; ++i) {
		num = squared(i);
		cout << "The square of " << i << " is " << num << endl;
	}
	cout << endl;

	for (double i = 0.0; i < 3.0; ++i) {
		num = cubed(i);
		cout << "The cube of " << i << " is " << num << endl;
	}

	return 0;
}