// Template Specialization
// Maximum.cpp

#include <iostream>
#include "Maximum.h"

using namespace std;

int main(void) {
	double num1, num2;
	const int LEN = 32;
	char str1[LEN], str2[LEN];

	cout << "Enter a number: ";
	cin >> num1;
	cout << "Enter another number: ";
	cin >> num2;

	double max = maximum(num1, num2);
	cout << "The greater of " << num1 << ", " << num2 << " is " << max << endl << endl;

	cout << "Enter a string: ";
	cin >> str1;
	cout << "Enter another string: ";
	cin >> str2;
	
	char* maxStr = maximum(str1, str2);

	cout << "The greater of " << str1 << ", " << str2 << " is " << maxStr << endl;

	return 0;
}