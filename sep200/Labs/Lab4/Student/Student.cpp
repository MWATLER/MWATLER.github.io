//Student.cpp - function definitions for the student class

#include "Student.h"

using namespace std;

Student::Student(std::string _name, int _number, const int* _marks, int _numMarks) {
	name = _name;
	number = _number;
	numMarks = _numMarks;
	if (numMarks > 0) {
		marks = new int[numMarks];
		for (int i = 0; i < numMarks; ++i) {
			marks[i] = _marks[i];
		}
	}
	else {
		marks = nullptr;
	}
}

std::string Student::GetName() const {
	return name;
}

int* Student::GetMarks() const {
	return marks;
}

int Student::GetNumMarks() const {
	return numMarks;
}

double Student::GetAverage() const {
	int runningTotal = 0;
	for (int i = 0; i < numMarks; ++i) {
		runningTotal += marks[i];
	}
	double average = 0.0;
	if (numMarks > 0) average = (double)runningTotal / numMarks;
	return average;
}

void Student::display(std::ostream& os) const {
	os << endl << endl;
	os << name << " with student number " << number << " has the following marks:";
	for (int i = 0; i < numMarks; ++i) {
		os << " " << marks[i];
	}
	os << "." << endl;
	os << name << " has an average of " << GetAverage() << endl;
}

Student::~Student() {
	delete[] marks;//no need to test if(marks!=nullptr)
	marks = nullptr;
}

std::ostream& operator<<(std::ostream& os, Student& student) {
	student.display(os);
	return os;
}