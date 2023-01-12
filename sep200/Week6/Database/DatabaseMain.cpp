//DatabaseMain.cpp - main function for the database

#include <iostream>
#include <string>
#include "Database.h"

using namespace std;

int main(void) {
	Database<Database1, 3>dbase1;
	Database<Database2, 2>dbase2;

	string name;
	int age;
	double salary;
	string position;
	int yearsWithCompany;

	for (int i = 0; i < 3; ++i) {
		cout << "Enter the name: ";
		getline(cin, name);
		cout << "Enter the age: ";
		cin >> age;
		cout << "Enter the salary: ";
		cin >> salary;
		cin.ignore(1000, '\n');
		dbase1.data[i].name = name;
		dbase1.data[i].age = age;
		dbase1.data[i].salary = salary;
		cout << endl;
	}
	for (int i = 0; i < 2; ++i) {
		cout << "Enter the name: ";
		getline(cin, name);
		cout << "Enter the position: ";
		getline(cin, position);
		cout << "Enter the years with the company: ";
		cin >> yearsWithCompany;
		cin.ignore(1000, '\n');
		dbase2.data[i].name = name;
		dbase2.data[i].position = position;
		dbase2.data[i].yearsWithCompany = yearsWithCompany;
		cout << endl;
	}

	cout << "The data elements of database 1 are:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << dbase1.data[i].name << ", " << dbase1.data[i].age << " years old, earns $" << dbase1.data[i].salary << "." << endl;
	}
	cout << endl;

	cout << "The data elements of database 2 are:" << endl;
	for (int i = 0; i < 2; ++i) {
		cout << dbase2.data[i].name << ", " << dbase2.data[i].position << ", has " << dbase2.data[i].yearsWithCompany<<" years with the company." << endl;
	}
	cout << endl;

	bool ret1, ret2;
	Database1 firstElement1;
	Database1 lastElement1;
	ret1 = dbase1.GetFirstDataElement(firstElement1);
	ret2 = dbase1.GetLastDataElement(lastElement1);
	if (ret1) {
		cout << "The first element of database 1 is " << firstElement1.name << endl;
	}
	if (ret2) {
		cout << "The last element of database 1 is " << lastElement1.name << endl;
	}

	Database2 firstElement2;
	Database2 lastElement2;
	ret1 = dbase2.GetFirstDataElement(firstElement2);
	ret2 = dbase2.GetLastDataElement(lastElement2);
	if (ret1) {
		cout << "The first element of database 2 is " << firstElement2.name << endl;
	}
	if (ret2) {
		cout << "The last element of database 2 is " << lastElement2.name << endl;
	}

	name = "Paul Stastny";
	Database1 findElement;
	bool ret = dbase1.FindDataElement(name, findElement);
	if (ret) {
		cout << "Database 1 has an employee called " << name << endl;
	}
	else {
		cout << "Database 1 does not have an employee called " << name << endl;
	}

	return 0;
}