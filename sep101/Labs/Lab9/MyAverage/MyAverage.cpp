//MyAverage.cpp - demo code for calculating an average from an array of unknown size

#include <iostream>

using namespace std;

int main() {
	string name;
	int* mark;//an array of marks, the size of the array is not known at compile time
	int numMarks;

	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter the number of marks: ";
	cin >> numMarks;
	mark = new int[numMarks];//mark now points to an array of 'numMarks' integers

	int runningTotal = 0;
	//I can now use mark as an array
	for (int i = 0; i < numMarks; ++i) {
		cout << "Enter mark " << (i + 1) << " : ";
		cin >> mark[i];
		runningTotal += mark[i];
	}

	double average = (double)runningTotal / numMarks;
	cout << name << ", your average is " << average << "." << endl;

	delete mark;//delete the memory we allocated for ourselves
	return 0;
}