//personalData.cpp - main code for personal information
//
// 26-Jan-21  M. Watler         Created.

#include <string>//std::getline()
#include "personalInfo.h"//includes iostream

using namespace std;

const int NUM = 10;

int main(void) {
	PersonalInfo personal[NUM];
	bool success = true;

	success=personal[0].setInfo("Babych", "34 Cedarwood Crescent", 18);
	if (success) success = personal[1].setInfo("Yakabowich", "17 Tack Drive", 21);
	if (success) success = personal[2].setInfo("Park", "22-2617 Windwood Drive", 34);
	if (success) success = personal[3].setInfo("Ali", "3467 Sunlight Drive", 54);
	if (success) success = personal[4].setInfo("Van Boxmeer", "1282 Bell Harbour Way", 36);
	if (success) success = personal[5].setInfo("Chin", "1801-299 Mill Road", 24);
	if (success) success = personal[6].setInfo("Morris", "15 Saltcoats Court", 55);
	if (success) success = personal[7].setInfo("Persic", "1212 Saskatchewan Road", 17);
	if (success) success = personal[8].setInfo("Patel", "19 Yonge Street", 23);
	if (success) success = personal[9].setInfo("Mulepe", "100 Escada Road", 70);

	if (success) {
		for (int i = 0; i < NUM; ++i) {
			personal[i].displayInfo();
		}
		cout << endl;

		char yesNo;
		int person;
		string newAddress;
		cout << "Would you like to change the address for any of the persons? ";
		cin >> yesNo;
		if (yesNo == 'Y' || yesNo == 'y') {
			cout << "Which person (1-10)? ";
			cin >> person;
			cout << "Enter the new address: ";
			cin.ignore(1000, '\n');//get rid of extra characters until the carriage return
			getline(cin, newAddress);
			success = personal[person - 1].setAddress(newAddress);
			cout << endl;
			if (success) {
				for (int i = 0; i < NUM; ++i) {
					personal[i].displayInfo();
				}
			}
		}
	}
	return (success ? 1: 0);
}