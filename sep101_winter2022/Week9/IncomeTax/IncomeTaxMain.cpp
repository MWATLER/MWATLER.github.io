//IncomeTaxMain.cpp - program for income taxes

#define NUM_CLIENTS 3
#include <iostream>//std::cout, std::cin
#include <string>//std::getline()
#include "IncomeTax.h"

using namespace std;

int main(void) {
	Person person[NUM_CLIENTS];//three objects of type Person.
	//Person is the blueprint; person[0], person[1], person[2] are the objects of type Person

    //Prompt for user input
	for (int i = 0; i < NUM_CLIENTS; ++i) {
		string name;
		float fValue;
		int iValue;
		bool ret;
		cout << endl;
		do {
			cout << "Enter the name for person " << i + 1 << ": ";
			getline(cin, name);
			ret = person[i].SetName(name);
		} while (!ret);
		do {
			cout << "Enter " << name << "'s social insurance number: ";
			cin >> iValue;
			ret = person[i].SetSin(iValue);
		} while (!ret);
		do {
			cout << "Enter " << name << "'s annual income: $";
			cin >> fValue;
			ret = person[i].SetAnnualIncome(fValue);
		} while (!ret);
		do {
			cout << "Enter " << name << "'s charitable donations: $";
			cin >> fValue;
			ret = person[i].SetDonations(fValue);
		} while (!ret);
		do {
			cout << "Enter " << name << "'s dependencies (children under 18): ";
			cin >> iValue;
			ret = person[i].SetDependencies(iValue);
		} while (!ret);
		do {
			cout << "Enter " << name << "'s RRSP contributions: $";
			cin >> fValue;
			ret = person[i].SetRrspContributions(fValue);
		} while (!ret);
		cin.ignore(1000, '\n');//get rid of extra characters until the carriage return for the next getline()
		person[i].CalculateDeductible();
		person[i].CalculateIncomeTax();
	}

	//Print a report for all the clients
	for (int i = 0; i < NUM_CLIENTS; ++i) {
		cout << endl;
		person[i].PrintReport();
	}

	return 0;
}
