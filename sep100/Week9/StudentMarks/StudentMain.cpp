//StudentMain.cpp - main function for student marks

#define NUM_STUDENTS 3
#include <iostream>//std::cout, std::cin
#include <string>//std::getline()
#include "Student.h"

using namespace std;

int main(void) {
	Student student[NUM_STUDENTS];

	//gather information
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		string sValue;
		int iValue;
		int iValueArray[MAX_MARKS];
		bool ret;

		do {
			cout << "Student's name: ";
			getline(cin, sValue);
			ret = student[i].SetName(sValue);
		} while (!ret);

		do {
			cout << "Student's year: ";
			cin >> iValue;
			ret = student[i].SetYear(iValue);
		} while (!ret);

		do {
			cout << "Number of courses: ";
			cin >> iValue;
			for (int j = 0; j < iValue; ++j) {
				cout << "Enter the mark for course " << j + 1 << ": ";
				cin >> iValueArray[j];
			}
			ret = student[i].SetMarks(iValueArray, iValue);
		} while (!ret);
		student[i].CalculateAverage();
		cout << student[i].GetName() << " has an average of " << student[i].GetAverage() << endl << endl;
		cin.ignore(1000, '\n');//get rid of extra characters until the carriage return for the next getline()
	}

	for (int i = 0; i < NUM_STUDENTS; ++i) {
		student[i].PrintReport();
	}

	return 0;
}
