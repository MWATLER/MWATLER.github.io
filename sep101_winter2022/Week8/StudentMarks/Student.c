//Student.c - function definitions for student marks

#include "Student.h"

//const pass by address is faster than pass by value
double CalculateAveragePassByValue(const struct Student* student) {//student = &student[2]
	int runningTotal = 0;
	int num=0;
	for (int i = 0; i < student->numMarks; ++i) {
		runningTotal += student->mark[i];
		++num;
	}
	return (double)runningTotal / num;//returns the average
}

bool CalculateAveragePassByAddress(struct Student* student) {
	int runningTotal = 0;
	int num=0;
	bool retVal = true;
	for (int i = 0; i < student->numMarks && retVal; ++i) {
		if (student->mark[i] < 0 || student->mark[i]>100) retVal = false;//invalid mark
		runningTotal += student->mark[i];
		++num;
	}
	student->average = (double)runningTotal / num;//the average for the student is assigned here
	return retVal;//returns an error status
}

bool CalculateAverages(struct Student* student, int length) {
	bool retVal = true;
	for (int i = 0; i < length && retVal; ++i) {
		retVal = CalculateAveragePassByAddress(&student[i]);
	}
	return retVal;
}

