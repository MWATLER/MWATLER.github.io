//Student.cpp - function definitions for a student

#include "Student.h"

using namespace std;

Student::Student(std::string _name, double ave) {
	name = _name;
	average = ave;
}

double Student::GetAverage() const {
	return average;
}

void Student::DisplayInfo() const {
	cout << "Name: " << name << " Average:" << average << endl;
}
