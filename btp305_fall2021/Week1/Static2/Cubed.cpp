//Cubed.cpp - function definition for cubed

#include <iostream>
#include "Cubed.h"

using namespace std;

static int numCalled = 0;

double cubed(double number) {
	++numCalled;
	cout << "cubed has been called " << numCalled << " times." << endl;
	return number * number * number;
}
