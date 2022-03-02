//Student.c - function definitions for student marks

#include "Student.h"

bool Student::CalculateAverage() {
	bool ret = true;
	int runningTotal = 0;
	int num=0;
	for (int i = 0; i < numMarks && ret; ++i) {
		if (mark[i] < 0 || mark[i]>100) {
			ret = false;
		}
		else {
			runningTotal += mark[i];
			++num;
		}
	}
	if(ret)	average = (double)runningTotal / num;
	return ret;
}

double CalculateOverallAverage(Student *student, int length) {
	double runningTotal = 0;
	for (int i = 0; i < length; ++i) {//assumes CalculateAverage has been called for all students
		runningTotal += student[i].average;
	}
	return runningTotal / length;
}

