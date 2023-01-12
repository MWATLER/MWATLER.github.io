//Component.cpp - function definitions for generating components
//
// 16-Mar-21  M. Watler         Created.

#include <iostream>
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"

using namespace std;

iComponent* CreateComponent() {
	iComponent* comp=nullptr;
	int sel;
	do {
		system("CLS");//clear screen in Windows
		cout << "1. Resistor" << endl;
		cout << "2. Capacitor" << endl;
		cout << "3. Inductor" << endl;
		cout << "Make a selection (8 selections in total): ";
		cin >> sel;
		if (sel == 1) {
			double resistance;
			cout << "Enter the resistance: ";
			cin >> resistance;
			if (resistance > 0) {
				comp = new Resistor(resistance);
			}
		}
		else if (sel == 2) {
			double capacitance;
			cout << "Enter the capacitance: ";
			cin >> capacitance;
			if (capacitance > 0) {
				comp = new Capacitor(capacitance);
			}
		}
		else if (sel == 3) {
			double inductance;
			cout << "Enter the inductance: ";
			cin >> inductance;
			if (inductance > 0) {
				comp = new Inductor(inductance);
			}
		}
	} while (sel<1 || sel>3);//validates the selection

	return comp;
}
