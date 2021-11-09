//Student.cpp - function definitions for the student class

#include "Student.h"

using namespace std;
/*
class Student {
	std::string name;
	int year;
	int mark[MAX_MARKS];
	int numMarks;
	double average;
public:
*/
//Setter functions, values can be validated before setting
bool Student::SetName(std::string _name) {
	bool ret = true;
	if (_name.size() == 0) {
		ret = false;
	}
	else {
		name = _name;
	}
	return ret;
}

bool Student::SetYear(int _year) {
	bool ret = true;
	if (_year < 1) {
		ret = false;
	}
	else {
		year = _year;
	}

	return ret;
}

bool Student::SetMarks(int* _mark, int num) {
	bool ret = true;
	//validate the number of marks first
	if (num<0 || num>MAX_MARKS) {
		ret = false;
	}
	else {
		numMarks = num;
	}
	for (int i = 0; i < numMarks && ret; ++i) {
		if (_mark[i] < 0 || _mark[i]>100) {
			ret = false;
		}
		else {
			mark[i] = _mark[i];
		}
	}

	return ret;
}

//Getter functions, a value is returned without being changed. 
//To enforce this, we declare these functions as const.
string Student::GetName() const {
	return name;
}

double Student::GetAverage() const {
	return average;
}

//These have access to all the private variables inside class Student
void Student::CalculateAverage() {
	int runningTotal = 0;
	for (int i = 0; i < numMarks; ++i) {
		runningTotal += mark[i];
	}
	average = (double)runningTotal / numMarks;
}

void Student::PrintReport() {
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "The average for " << name << " in year " << year << " is " << average << endl;
}
