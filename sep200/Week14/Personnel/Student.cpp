//Student.cpp - function definitions for the Student class

#include <string>
#include "Student.h"

using namespace std;

Student::Student(string _name, Personnel::Role _role, string _address, int number) : Personnel(_name, _role, _address, number) {
	int mark = 0;
	int markNo = 1;
	cout << Personnel::GetName() << ", enter your marks (enter -1 to quit): " << endl;
	do {
		try {
			cout << "Mark " << markNo++ << ": ";
			cin >> mark;
			if (mark < -1 || mark>100) throw "Invalid Mark";
			if (mark != -1)marks.push_back(mark);
		}
		catch (const char* msg) {
			cout << msg << endl;
		}
	} while (mark != -1);
	cout << endl;
}

string Student::GetInfo() const {
	string info = Personnel::GetInfo();
	info += "This student has the following marks: ";
	for (auto e : marks) {
		info += " " + to_string(e);
	}
	info += "\nwith an average of " + to_string(GetAverage()) + "\n\n";
	return info;
}

double Student::GetSalary() const {
	return 0.0;
}


double Student::GetAverage() const {
	double runningTotal = 0.0;
	double average;
	for (auto e : marks) {
		runningTotal += e;
	}
	try {
		if (marks.size() <= 0) throw "Invalid number of marks";
		average = runningTotal / marks.size();
	}
	catch (const char* msg) {
		cout << msg << endl;
	}

	return average;
}

vector<int> Student::GetMarks() const {
	return marks;
}
