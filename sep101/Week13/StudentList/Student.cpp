//Student.cpp - function definitions for the student

#include "Student.h"

using namespace std;

Student::Student() {
	name = "";
	marks = nullptr;
	numMarks = 0;
	average = 0.0;
	rank = 1;//assume this is the best student
}

bool Student::CalculateAverage() {
	bool ret = true;
	double runningTotal = 0.0;
	if (numMarks <= 0) ret = false;
	for (int i = 0; i < numMarks && ret; ++i) {
		if (marks[i] < 0) {
			ret = false;
		}
		else {
			runningTotal += marks[i];
		}
	}
	if (ret) average = runningTotal / numMarks;
	return ret;
}

double Student::GetAverage() const {
	return average;
}

void Student::SetName(std::string name) {
	this->name = name;
}

std::string Student::GetName() const {
	return name;
}

void Student::SetMarks(double* marks, int num) {
	numMarks = num;
	if (this->marks != nullptr) {
		delete[] this->marks;
		this->marks = nullptr;
	}
	this->marks = new double[numMarks];
	for (int i = 0; i < numMarks; ++i) {
		this->marks[i] = marks[i];
	}
}

double* Student::GetMarks() const {
	return marks;
}

int Student::GetNumMarks() const {
	return numMarks;
}

void Student::IncrementRank() {
	++rank;
}

int Student::GetRank() const {
	return rank;
}

Student::~Student() {
	if (this->marks != nullptr) {
		delete[] this->marks;
		this->marks = nullptr;
	}
}