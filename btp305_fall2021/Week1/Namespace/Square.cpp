//Square.cpp - function definition for square

#include <iostream>
#include "Squared.h"

using namespace std;

namespace square {

	int numCalled = 0;

	double squared(double number) {
		++numCalled;
		cout << "squared has been called " << numCalled << " times." << endl;
		return number * number;
	}
}
