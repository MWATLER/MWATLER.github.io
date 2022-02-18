//CompanyMain.cpp - the main function for the company database

#include <iostream>
#include "CompanyEmployee.h"
#include "CompanyExecutive.h"

using namespace std;

int main() {
	const int NUM = 2;
	const int MAX_SIZE = 1000;
	CompanyEmployee standardEmployeeDB;
	CompanyExecutive executiveEmployeeDB;

	cout << "Add three persons to each of your databases." << endl;
	AddPersonnel(standardEmployeeDB, 3);
	AddPersonnel(executiveEmployeeDB, 3);

	string name;
	cout << "Enter a name to search for in both databases: ";
	getline(std::cin, name);

	StandardEmployee sEmpl;
	ExecutiveEmployee eEmpl;
	bool found = FindPersonnel(standardEmployeeDB, name, sEmpl);
	cout.setf(ios::fixed);
	cout.precision(2);
	if (found) {
		cout << sEmpl.name << " works as " << sEmpl.position << " and earned $" << CalculateSalary(standardEmployeeDB, name) << " last year." << endl << endl;
	}
	else {
		found = FindPersonnel(executiveEmployeeDB, name, eEmpl);
		if (found) {
			cout << eEmpl.name << " works as " << eEmpl.position << " and earned $" << CalculateSalary(executiveEmployeeDB, name) << " last year." << endl << endl;
		}
	}

	cout << "Add two more persons to your databases." << endl;
	AddPersonnel(standardEmployeeDB, 2);
	AddPersonnel(executiveEmployeeDB, 2);

	cout << "Enter another name to search for in both databases: ";
	getline(std::cin, name);

	found = FindPersonnel(standardEmployeeDB, name, sEmpl);
	cout.setf(ios::fixed);
	cout.precision(2);
	if (found) {
		cout << sEmpl.name << " works as " << sEmpl.position << " and earned $" << CalculateSalary(standardEmployeeDB, name) << " last year." << endl << endl;
	}
	else {
		found = FindPersonnel(executiveEmployeeDB, name, eEmpl);
		if (found) {
			cout << eEmpl.name << " works as " << eEmpl.position << " and earned $" << CalculateSalary(executiveEmployeeDB, name) << " last year." << endl << endl;
		}
	}

	return 0;
}