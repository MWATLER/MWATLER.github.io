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

bool compare(Student& student1, Student& student2) {
	static int count = 0;
	++count;
	bool ret = true;
	if (student1.GetAverage() < student2.GetAverage()) {
		ret = false;
	}
	cout << "compare: count:" << count << endl;
	return ret;
}