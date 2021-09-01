//Faculty.cpp - function definitions for the Faculty class

#include <string>
#include "Faculty.h"

using namespace std;

Faculty::Faculty(string _name, Personnel::Role _role, string _address, int number) : Personnel(_name, _role, _address, number) {
	try {
		cout << "Enter your salary: $";
		cin >> salary;
		if (salary < 0) throw "Invalid salary";
		cout << endl;
	}
	catch (const char* msg) {
		cout << msg << endl;
		salary = 0.0;
	}
}

string Faculty::GetInfo() const {
	string info = Personnel::GetInfo();
	info += "This faculty earns $" + to_string(salary) + " per year\n\n";
	return info;
}

double Faculty::GetSalary() const {
	return salary;
}

double Faculty::GetAverage() const {
	return 0.0;
}

vector<int> Faculty::GetMarks() const {
	vector<int> marks;
	marks.push_back(0);
	return marks;
}