//MathMain.cpp - main function for square and cubed

#include "Squared.h"
#include "Cubed.h"

using namespace std;

int main() {
	int intNum;
	float floatNum;

	for (int i = 0; i < 3; ++i) {
		intNum = squared(i);
		cout << "The square of " << i << " is " << intNum << endl;
	}
	cout << endl;

	for (float i = 0.0; i < 3.0; ++i) {
		floatNum = cubed(i);
		cout << "The cube of " << i << " is " << floatNum << endl;
	}

	return 0;
}