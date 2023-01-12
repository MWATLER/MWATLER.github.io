//EmployeeInfoMain.cpp - main program for employee information

#include "EmployeeInfo.h"

using namespace std;

int main() {
	EmployeeInfo empl1("Sarah Smith", "Chief Financial Officer", 61);
	cout << "The average age so far is " << empl1.GetAverageAge() << endl << endl;
	EmployeeInfo empl2("Michal Dabrowski", "Software Developer", 33);
	cout << "The average age so far is " << empl1.GetAverageAge() << endl;
	cout << "The average age so far is " << empl2.GetAverageAge() << endl << endl;
	EmployeeInfo empl3("Jessica Lee", "Design Engineer", 42);
	cout << "The average age so far is " << empl1.GetAverageAge() << endl;
	cout << "The average age so far is " << empl2.GetAverageAge() << endl;
	cout << "The average age so far is " << empl3.GetAverageAge() << endl << endl;

	EmployeeInfo::Err_Status ret = empl1.PrintInfo();
	if (ret == EmployeeInfo::Err_Status::Err_Failure) cout << "Failed to get information for " << empl1.GetName() << endl << endl;

	ret = empl2.PrintInfo();
	if (ret == EmployeeInfo::Err_Status::Err_Failure) cout << "Failed to get information for " << empl2.GetName() << endl << endl;

	ret = empl3.PrintInfo();
	if (ret == EmployeeInfo::Err_Status::Err_Failure) cout << "Failed to get information for " << empl3.GetName() << endl << endl;

	cout << "The running total is " << EmployeeInfo::runningTotal << endl;
	cout << "The number of employees is " << EmployeeInfo::numEmployees << endl;

	return 0;
}