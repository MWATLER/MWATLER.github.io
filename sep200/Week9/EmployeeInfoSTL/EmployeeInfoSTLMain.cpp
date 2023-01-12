//EmployeeInfoMain.cpp - main program for employee information

#include <vector>
#include "EmployeeInfoSTL.h"

using namespace std;

int main() {
	EmployeeInfoSTL empl1("Sarah Smith", "Chief Financial Officer", 212000.00);
	EmployeeInfoSTL empl2("Michal Dabrowski", "Software Developer", 90000.00);
	EmployeeInfoSTL empl3("Jessica Lee", "Design Engineer", 92000.00);
	vector<EmployeeInfoSTL> empl;

//	vector<double>* vPointer = new vector<double>;//you can allocate memory for vectors!!!!

	empl.push_back(empl1);
	empl.push_back(empl2);
	empl.push_back(empl3);
//	cout << "The capacity of our vector is " << empl.capacity() << ", but the size is " << empl.size() << endl << endl;

	for (size_t i = 0; i < empl.size(); ++i) {
		EmployeeInfoSTL::Err_Status ret = empl[i].PrintInfo();//array format
		if (ret == EmployeeInfoSTL::Err_Status::Err_Failure) cout << "Failed to get information for " << empl.at(i).GetName() << endl << endl;//at() format
	}
	cout << endl;

	cout << "The number of employees by static variable is " << EmployeeInfoSTL::numEmployees << endl;
	cout << "The number of employees by vector size is " << empl.size() << endl;
	cout << endl;

	//Do the same using iterators
	cout << "print information using an iterator" << endl;
	vector<EmployeeInfoSTL>::iterator i;
	for (i = empl.begin(); i != empl.end(); ++i) {
		EmployeeInfoSTL::Err_Status ret = i->PrintInfo();//array format
		if (ret == EmployeeInfoSTL::Err_Status::Err_Failure) cout << "Failed to get information for " << i->GetName() << endl << endl;//at() format
	}
	cout << endl;

	//Do the same using iterators II
	cout << "print information using an auto iterator" << endl;
	for (auto j = empl.begin(); j != empl.end(); ++j) {
		EmployeeInfoSTL::Err_Status ret = j->PrintInfo();//array format
		if (ret == EmployeeInfoSTL::Err_Status::Err_Failure) cout << "Failed to get information for " << j->GetName() << endl << endl;//at() format
	}
	cout << endl;

    //Add an employee to the front and delete the last employee
	EmployeeInfoSTL empl4("Bill Durnham", "Product Support Specialist", 84000.00);
	empl.front() = empl4;//replaces Sarah Smith
	empl.pop_back();//removes Jessica Lee

	for (size_t i = 0; i < empl.size(); ++i) {
		EmployeeInfoSTL::Err_Status ret = empl[i].PrintInfo();//array format
		if (ret == EmployeeInfoSTL::Err_Status::Err_Failure) cout << "Failed to get information for " << empl.at(i).GetName() << endl << endl;//at() format
	}
	cout << endl;

	cout << "The number of employees by static variable is " << EmployeeInfoSTL::numEmployees << endl;
	cout << "The number of employees by vector size is " << empl.size() << endl;
	cout << endl;

	return 0;
}