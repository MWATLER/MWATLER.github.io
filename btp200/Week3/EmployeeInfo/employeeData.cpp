//employeeData.cpp - main code for employee information
//
// 26-Jan-21  M. Watler         Created.

#include <iostream>//not needed, this is included in EmployeeInfo.h
#include "EmployeeInfo.h"

using namespace std;

const int NUM = 3;

int main(void) {
	EmployeeInfo empl[NUM];
	bool success = true;
	//Have the user enter data for all employees except the last
	for (int i = 0; i < NUM - 1 && success; ++i) {
		do {
			success = empl[i].setInfo();
		} while (!success);
	}
	//Enter the information for the last employee programmatically (assume valid data)
	success = empl[NUM - 1].setInfo("Swiff", 98000.00, 333);

	//Display the information
	for (int i = 0; i < NUM; ++i)empl[i].displayInfo();
	cout << endl;

	//Make any necessary changes to employee information
	char yesNo;
	string newName;
	double newSalary;
	int newEmplNum;
	for (int i = 0; i < NUM; ++i) {
		cout << "Would you like to change the information for employee " << (i + 1) << "? (Y or N) ";
		cin >> yesNo;
		if (yesNo == 'Y' || yesNo == 'y') {
			cout << "Would you like to change the name for employee " << (i + 1) << "? (Y or N) ";
			cin >> yesNo;
			if (yesNo == 'Y' || yesNo == 'y') {//change the employee's name
				do {
					cout << "What is the new name? ";
					cin >> newName;
					success = empl[i].changeName(newName);
				} while (!success);
			}
			cout << "Would you like to change the salary for employee " << (i + 1) << "? (Y or N) ";
			cin >> yesNo;
			if (yesNo == 'Y' || yesNo == 'y') {//change the employee's salary
				do {
					cout << "What is the new salary? $";
					cin >> newSalary;
					success = empl[i].changeSalary(newSalary);
				} while (!success);
			}
			cout << "Would you like to change the employee number for employee " << (i + 1) << "? (Y or N) ";
			cin >> yesNo;
			if (yesNo == 'Y' || yesNo == 'y') {//change the employee's number
				do {
					cout << "What is the new employee number? ";
					cin >> newEmplNum;
					success = empl[i].changeEmployeeNum(newEmplNum);
				} while (!success);
			}
		}
	}

	//display the information again
	cout << endl;
	for (int i = 0; i < NUM; ++i)empl[i].displayInfo();

	return 0;
}
