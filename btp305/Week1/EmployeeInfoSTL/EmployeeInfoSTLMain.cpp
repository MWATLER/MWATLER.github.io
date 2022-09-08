//EmployeeInfoMain.cpp - main program for employee information

#include <queue>
#include "EmployeeInfoSTL.h"

using namespace std;

int main() {
	EmployeeInfoSTL empl1("Sarah Smith", "Chief Financial Officer", 212000.00);
	EmployeeInfoSTL empl2("Michal Dabrowski", "Software Developer", 90000.00);
	EmployeeInfoSTL empl3("Jessica Lee", "Design Engineer", 92000.00);
	vector<EmployeeInfoSTL> empl;

	empl.push_back(empl1);
	empl.push_back(empl2);
	empl.push_back(empl3);
/*
	empl.push_back(EmployeeInfoSTL("Sarah Smith", "Chief Financial Officer", 212000.00));
	empl.push_back(EmployeeInfoSTL("Michal Dabrowski", "Software Developer", 90000.00));
	empl.push_back(EmployeeInfoSTL("Jessica Lee", "Design Engineer", 92000.00));
*/

	for (int i = 0; i < empl.size(); ++i) {
		Err_Status ret = empl[i].PrintInfo();//array format
		if (ret == Err_Failure) cout << "Failed to get information for " << empl.at(i).GetName() << endl << endl;//at() format
	}
	cout << endl;

	cout << "The number of employees by static variable is " << EmployeeInfoSTL::numEmployees << endl;
	cout << "The number of employees by vector size is " << empl.size() << endl;
	cout << endl;

    //Add an employee to the front and delete the last employee
	EmployeeInfoSTL empl4("Bill Durnham", "Product Support Specialist", 84000.00);
	empl.front() = empl4;
	empl.pop_back();

	for (int i = 0; i < empl.size(); ++i) {
		Err_Status ret = empl[i].PrintInfo();//array format
		if (ret == Err_Failure) cout << "Failed to get information for " << empl.at(i).GetName() << endl << endl;//at() format
	}
	cout << endl;

	cout << "The number of employees by static variable is " << EmployeeInfoSTL::numEmployees << endl;
	cout << "The number of employees by vector size is " << empl.size() << endl;
	cout << endl;

	return 0;
}