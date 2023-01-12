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
	bool ret = true;
	if (student1.GetAverage() < student2.GetAverage()) {//this is normally less to greater
		ret = false;//this effectively inverses the criteria of the sort, becoming greater to less
	}
//	return (student1.GetAverage() > student2.GetAverage());
	return ret;
}