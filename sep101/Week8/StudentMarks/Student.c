//Student.c - function definitions for student marks

#include "Student.h"

double CalculateAveragePassByValue(struct Student student) {
	int runningTotal = 0;
	int num=0;
	for (int i = 0; i < student.numMarks; ++i) {
		runningTotal += student.mark[i];
		++num;
	}
	return (double)runningTotal / num;
}

bool CalculateAveragePassByAddress(struct Student* student) {
	int runningTotal = 0;
	int num=0;
	bool retVal = true;
	for (int i = 0; i < student->numMarks && retVal; ++i) {
		if (student->mark[i] < 0) retVal = false;//invalid mark
		runningTotal += student->mark[i];
		++num;
	}
	student->average = (double)runningTotal / num;
	return retVal;
}

bool CalculateAverages(struct Student *student, int length) {
	bool retVal = true;
	for (int i = 0; i < length && retVal; ++i) {
		retVal = CalculateAveragePassByAddress(&student[i]);
	}
	return retVal;
}

