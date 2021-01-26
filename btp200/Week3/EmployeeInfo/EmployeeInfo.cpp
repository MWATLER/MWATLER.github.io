//EmployeeInfo.cpp - set and retrieve employee information
//
// 26-Jan-21  M. Watler         Created.

#include <iostream>//not needed, this is included in EmployeeInfo.h
#include "EmployeeInfo.h"
using namespace std;

//Prompts the user for information
bool EmployeeInfo::setInfo() {
	bool retVal = true;
	string _name;
	int _emplNum;
	double _salary;
	cout << "What is your last name: ";
	cin >> _name;
	retVal = changeName(_name);
	if (retVal) {
		cout << "What is your annual salary: $";
		cin >> _salary;
		retVal = changeSalary(_salary);
	}
	if (retVal) {
		cout << "What is your employee number: ";
		cin >> _emplNum;
		retVal = changeEmployeeNum(_emplNum);
	}
	if (!retVal) {
		cout << "You have entered invalid information" << endl;
	}
	cout << endl;
	return retVal;
}

//Enter the information programmatically
bool EmployeeInfo::setInfo(std::string _name, double _salary, int _emplNum) {
	bool retVal = true;
	retVal = changeName(_name);
	if (retVal) retVal = changeSalary(_salary);
	if (retVal) retVal = changeEmployeeNum(_emplNum);
	return retVal;
}

//Change the employee name
bool EmployeeInfo::changeName(std::string _name) {
	bool retVal = true;
	if (_name.size() < 0) {//perform validation
		cout << "Invalid name: no name given" << endl;
		retVal = false;
	}
	else {
		name = _name;
	}
	return retVal;
}

//Change the employee salary
bool EmployeeInfo::changeSalary(double _salary) {
	bool retVal = true;
	if (_salary < 0) {//perform validation
		cout << "Invalid salary: salary cannot be negative" << endl;
		retVal = false;
	}
	else {
		salary = _salary;
	}
	return retVal;
}

//Change the employee number
bool EmployeeInfo::changeEmployeeNum(int _emplNum) {
	bool retVal = true;
	if (_emplNum < 0) {//perform validation
		cout << "Invalid employee number: the employee number cannot be negative" << endl;
		retVal = false;
	}
	else {
		emplNum = _emplNum;
	}
	return retVal;
}

void EmployeeInfo::displayInfo() const {
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << name << "(" << emplNum << ") has a salary of $" << salary << endl;
}