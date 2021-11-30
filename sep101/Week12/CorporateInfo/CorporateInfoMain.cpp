//CorporateInfoMain.cpp - main function for corporate information

#include <iostream>
#include <fstream>
#include <string>
#include "CorporateInfo.h"

using namespace std;

int main(void) {
	int retVal = 0;
	ifstream file("EmployeeDB.txt");
	CorporateInfo corporation;

	//fill the corporate information structure from a file
	if (!file) {
		cout << "Unable to open EmployeeDB.txt" << endl;
		retVal = -1;
	}
	if (retVal == 0) {
		for (int i = 0; i < NUM_EMPLOYEES && retVal == 0; ++i) {
			getline(file, corporation.employee[i].name);
			getline(file, corporation.employee[i].position);
			file >> corporation.employee[i].salary;
			file >> corporation.employee[i].age;
			file.ignore(1000, '\n');
		}
		file.close();
		bool ret1 = corporation.CalculateAverageSalary();
		bool ret2 = corporation.CalculateAverageAge();
		bool ret3 = corporation.CalculateMaximumSalary();
		if (!ret1 || !ret2 || !ret3) {
			cout << "Unable to perform calculations" << endl;
			retVal = -2;
		}
		else {
			ofstream fout;
			fout.open("EmployeeData.txt", std::ofstream::out);
			fout.setf(ios::fixed);
			fout.precision(2);
			fout << "The maximum salary is $" << corporation.GetMaximumSalary() << endl;
			fout << "The average salary is $" << corporation.GetAverageSalary() << endl;
			fout << "The average age is " << corporation.GetAverageAge() << endl;
			fout.unsetf(ios::fixed);
			fout.close();
		}
	}

	return retVal;
}