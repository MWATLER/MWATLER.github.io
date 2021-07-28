//CompanyMain.cpp - the main function for the company database

#include <iostream>
#include "CompanyEmployee.h"
#include "CompanyExecutive.h"

using namespace std;

int main() {
	const int NUM = 2;
	const int MAX_SIZE = 1000;
	CompanyEmployee standardEmployee;
	CompanyExecutive executiveEmployee;

	cout << "Add three persons to each of your databases." << endl;
	AddPersonnel(standardEmployee, 3);
	AddPersonnel(executiveEmployee, 3);

	string name;
	cout << "Enter a name to search for in both databases: ";
	getline(std::cin, name);

	StandardEmployee sEmpl;
	ExecutiveEmployee eEmpl;
	bool found = FindPersonnel(standardEmployee, name, sEmpl);
	cout.setf(ios::fixed);
	cout.precision(2);
	if (found) {
		cout << sEmpl.name << " works as " << sEmpl.position << " and earned $" << CalculateSalary(standardEmployee, name) << " last year." << endl << endl;
	}
	else {
		found = FindPersonnel(executiveEmployee, name, eEmpl);
		if (found) {
			cout << eEmpl.name << " works as " << eEmpl.position << " and earned $" << CalculateSalary(executiveEmployee, name) << " last year." << endl << endl;
		}
	}

	cout << "Add two more persons to your databases." << endl;
	AddPersonnel(standardEmployee, 2);
	AddPersonnel(executiveEmployee, 2);

	cout << "Enter another name to search for in both databases: ";
	getline(std::cin, name);

	found = FindPersonnel(standardEmployee, name, sEmpl);
	cout.setf(ios::fixed);
	cout.precision(2);
	if (found) {
		cout << sEmpl.name << " works as " << sEmpl.position << " and earned $" << CalculateSalary(standardEmployee, name) << " last year." << endl << endl;
	}
	else {
		found = FindPersonnel(executiveEmployee, name, eEmpl);
		if (found) {
			cout << eEmpl.name << " works as " << eEmpl.position << " and earned $" << CalculateSalary(executiveEmployee, name) << " last year." << endl << endl;
		}
	}

	return 0;
}