//EmployeeInfoMain.cpp - main program for employee information

#include <list>
#include "EmployeeInfoSTL.h"

using namespace std;

int main() {
	EmployeeInfoSTL empl1("Sarah Smith", "Chief Financial Officer", 212000.00);
	EmployeeInfoSTL empl2("Michal Dabrowski", "Software Developer", 90000.00);
	EmployeeInfoSTL empl3("Jessica Lee", "Design Engineer", 92000.00);
	list<EmployeeInfoSTL> empl;

	empl.push_back(empl1);
	empl.push_back(empl2);
	empl.push_back(empl3);
/*
	empl.push_back(EmployeeInfoSTL("Sarah Smith", "Chief Financial Officer", 212000.00));
	empl.push_back(EmployeeInfoSTL("Michal Dabrowski", "Software Developer", 90000.00));
	empl.push_back(EmployeeInfoSTL("Jessica Lee", "Design Engineer", 92000.00));
*/
	std::list<EmployeeInfoSTL>::iterator it;
	for (it = empl.begin(); it != empl.end(); ++it) {
		Err_Status ret = it->PrintInfo();//array format
		if (ret == Err_Failure) cout << "Failed to get information for " << it->GetName() << endl << endl;//at() format
	}
	cout << endl;

	cout << "The number of employees by static variable is " << EmployeeInfoSTL::numEmployees << endl;
	cout << "The number of employees by list size is " << empl.size() << endl;
	cout << endl;

    //Add an employee to the front of the list
	EmployeeInfoSTL empl4("Bill Durnham", "Product Support Specialist", 84000.00);
	empl.insert(empl.begin(), empl4);
	
	//Add an employee to the third position of the list
	EmployeeInfoSTL empl5("Carl Austman", "Security Guard", 64000.00);
	it = empl.begin();
	it++;
	it++;
	empl.insert(it, empl5);

	for (it = empl.begin(); it != empl.end(); ++it) {
		Err_Status ret = it->PrintInfo();//array format
		if (ret == Err_Failure) cout << "Failed to get information for " << it->GetName() << endl << endl;//at() format
	}
	cout << endl;

	cout << "The number of employees by static variable is " << EmployeeInfoSTL::numEmployees << endl;
	cout << "The number of employees by list size is " << empl.size() << endl;
	cout << endl;

	return 0;
}