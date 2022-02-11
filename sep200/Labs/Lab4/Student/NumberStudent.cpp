//NumberStudent.cpp - function definitions for a number student

#include "NumberStudent.h"

using namespace std;

NumberStudent::NumberStudent(std::string _name, int _number, const int* _marks, int _numMarks) :
	Student(_name, _number, _marks, _numMarks) {

}

int NumberStudent::GetNumberGrade(const double mark) const {
	int numberGrade;
	if (mark >= 90.0) numberGrade = 5;
	else if (mark >= 80.0) numberGrade = 4;
	else if (mark >= 70.0) numberGrade = 3;
	else if (mark >= 60.0) numberGrade = 2;
	else if (mark >= 50.0) numberGrade = 1;
	else numberGrade = 0;

	return numberGrade;
}

double NumberStudent::GetAverage() const {
	int runningTotal = 0;
	int* marks = Student::GetMarks();
	int numMarks = Student::GetNumMarks();
	for (int i = 0; i < numMarks; ++i) {
		runningTotal += GetNumberGrade((double)marks[i]);
	}

	double numberAverage = 0.0;
	if (numMarks > 0) numberAverage = (double)runningTotal / numMarks;

	return numberAverage;
}

void NumberStudent::display(std::ostream& os) const {
	int* marks = Student::GetMarks();
	int numMarks = Student::GetNumMarks();
	Student::display(os);
	os << "In terms of number grades, the marks are:";
	for (int i = 0; i < numMarks; ++i) {
		int numberGrade = GetNumberGrade((double)marks[i]);
		os << " " << numberGrade;
	}
	os << endl;
	os << Student::GetName() << " has an average of " << GetAverage() << "." << endl;
}

NumberStudent::~NumberStudent() {

}

std::ostream& operator<<(std::ostream& os, NumberStudent& student) {
	student.display(os);
	return os;
}
