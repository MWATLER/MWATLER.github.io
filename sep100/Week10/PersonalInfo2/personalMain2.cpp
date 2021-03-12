//personalMain2.cpp - main code for personal information
//
// 26-Jan-21  M. Watler         Created.

#include <string>//std::getline()
#include "personalInfo2.h"//includes iostream

using namespace std;

int main(void) {
	const int NUM = 10;
	PersonalInfo2* personal[NUM];
	PersonalInfo2 personal1("Babych", "34 Cedarwood Crescent", 18);
	PersonalInfo2 personal2("Yakabowich", "17 Tack Drive", 21);
	PersonalInfo2 personal3("Park", "22-2617 Windwood Drive", 34);
	PersonalInfo2 personal4("Ali", "3467 Sunlight Drive", 54);
	PersonalInfo2 personal5("Van Boxmeer", "1282 Bell Harbour Way", 36);
	PersonalInfo2 personal6, personal7, personal8, personal9, personal10;

	personal[0] = &personal1;
	personal[1] = &personal2;
	personal[2] = &personal3;
	personal[3] = &personal4;
	personal[4] = &personal5;
	personal[5] = &personal6;
	personal[6] = &personal7;
	personal[7] = &personal8;
	personal[8] = &personal9;
	personal[9] = &personal10;

	bool success = true;

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

	return (success ? 1 : 0);
}