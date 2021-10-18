//InsertMain.cpp - main function for testing insert at the end of an array

#include <iostream>
#include "insertAtEnd.h"

using namespace std;

int main() {
	InsertAtEnd<double> insertAtEnd;
	insertAtEnd(3.3);
	insertAtEnd(5.5);
	insertAtEnd(7.7);

	double* dPtr = insertAtEnd.getArray();
	for (int i = 0; i < insertAtEnd.getSize(); ++i) cout << " " << dPtr[i];
	cout << endl << endl;

	InsertAtEnd<int> insertAtEnd2;
	insertAtEnd2(45);
	insertAtEnd2(78);
	insertAtEnd2(99);
	insertAtEnd2(55);

	int* iPtr = insertAtEnd2.getArray();
	for (int i = 0; i < insertAtEnd2.getSize(); ++i) cout << " " << iPtr[i];
	cout << endl << endl;

	return 0;
}