//personalMain.cpp - main code for personal information
//
// 26-Jan-21  M. Watler         Created.

#include <string>//std::getline()
#include "personalInfo.h"//includes iostream

using namespace std;

const int NUM = 10;

int main(void) {
	PersonalInfo personal1, personal2;
	PersonalInfo personal3("Babych", "34 Cedarwood Crescent", 18);
	PersonalInfo personal4("Ali", "3467 Sunlight Drive", 54);
	bool success = true;

	success = personal1.setInfo("Chin", "1801-299 Mill Road", 24);
	if (success) success = personal2.setInfo("Patel", "19 Yonge Street", 23);
	
	if (success) {
		personal1.displayInfo();
		personal2.displayInfo();
		personal3.displayInfo();
		personal4.displayInfo();
		cout << endl;

		char yesNo;
		int person;
		string newAddress;
		cout << "Would you like to change the address for any of the persons? ";
		cin >> yesNo;
		if (yesNo == 'Y' || yesNo == 'y') {
			do {
			cout << "Which person (1-4)? ";
			cin >> person;
			} while (person < 1 || person>4);
			cout << "Enter the new address: ";
			cin.ignore(1000, '\n');//get rid of extra characters until the carriage return
			getline(cin, newAddress);

			if (person == 1) success = personal1.setAddress(newAddress);
			else if (person == 2) success = personal2.setAddress(newAddress);
			else if (person == 3) success = personal3.setAddress(newAddress);
			else if (person == 4) success = personal4.setAddress(newAddress);

			cout << endl;
			if (success) {
				personal1.displayInfo();
				personal2.displayInfo();
				personal3.displayInfo();
				personal4.displayInfo();
			}
		}
	}

	return (success ? 1 : 0);
}