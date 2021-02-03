//personalData.cpp - main code for personal information
//
// 26-Jan-21  M. Watler         Created.

#include <string>//std::getline()
#include "personalInfo.h"//includes iostream

using namespace std;

const int NUM = 10;

int main(void) {
	PersonalInfo *personal[NUM];
	bool success = true;

	personal[0] = new PersonalInfo("Babych", "34 Cedarwood Crescent", 18);
	personal[1] = new PersonalInfo("Yakabowich", "17 Tack Drive", 21);
	personal[2] = new PersonalInfo("Park", "22-2617 Windwood Drive", 34);
	personal[3] = new PersonalInfo("Ali", "3467 Sunlight Drive", 54);
	personal[4] = new PersonalInfo("Van Boxmeer", "1282 Bell Harbour Way", 36);

	for (int i = 5; i < NUM; ++i) personal[i] = new PersonalInfo();
	success = personal[5]->setInfo("Chin", "1801-299 Mill Road", 24);
	if (success) success = personal[6]->setInfo("Morris", "15 Saltcoats Court", 55);
	if (success) success = personal[7]->setInfo("Persic", "1212 Saskatchewan Road", 17);
	if (success) success = personal[8]->setInfo("Patel", "19 Yonge Street", 23);
	if (success) success = personal[9]->setInfo("Mulepe", "100 Escada Road", 70);

	if (success) {
		for (int i = 0; i < NUM; ++i) {
			personal[i]->displayInfo();
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
			success = personal[person - 1]->setAddress(newAddress.c_str());
			cout << endl;
			if (success) {
				for (int i = 0; i < NUM; ++i) {
					personal[i]->displayInfo();
				}
			}
		}
	}

	for (int i = 0; i < NUM; ++i) {
		delete personal[i];
		personal[i] = nullptr;
	}
	return (success ? 1 : 0);
}