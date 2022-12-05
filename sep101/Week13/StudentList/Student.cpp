//Student.cpp - function definitions for the student

#include "Student.h"

using namespace std;

Student::Student() {
	name = "";
	//If name was defined as follows:
	//char name[64];
	//then name is initialized as follows:
//	name[0] = '\0';

	//If name was defined as follows:
	//char *name;
	//then name is initialized as follows:
//	name = nullptr;

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
/* These can be done inline in the header file, they are so simple
double Student::GetAverage() const {
	return average;
}

void Student::SetName(std::string name) {
	this->name = name;
}

std::string Student::GetName() const {
	return name;
}*/

void Student::SetMarks(double* marks, int num) {
	numMarks = num;
	//reallocation: delete any allocated memory, then
	//              allocate new memory for the new data
	Destroy();
//	this->marks = nullptr;
	this->marks = new double[numMarks];
	for (int i = 0; i < numMarks; ++i) {
		this->marks[i] = marks[i];
	}
}

void Student::Destroy(void) {
	delete[] this->marks;//C++11 and later
	this->marks = nullptr;
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
	Destroy();
}