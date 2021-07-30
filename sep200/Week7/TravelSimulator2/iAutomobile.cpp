//iAutomobile.cpp - function definition for the automobile interface

#include "AmericanAuto.h"
#include "EuropeanAuto.h"

using namespace std;

iAutomobile* CreateAutomobile() {
	iAutomobile* automobile = nullptr;
	int sel;
	do {
		system("CLS");//clear screen in Windows
		cout << "1. American car" << endl;
		cout << "2. European car" << endl;
		cout << "Make a selection (4 in total): ";
		cin >> sel;
		if (sel == 1) {
			automobile = new AmericanAuto();
			SetInformation(automobile);
		}
		else if (sel == 2) {
			automobile = new EuropeanAuto();
			SetInformation(automobile);
		}
	} while (sel < 1 || sel>2);

	return automobile;
}