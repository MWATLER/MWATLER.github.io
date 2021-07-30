//TravelSimulator2.cpp - a travel simulator

#include <iostream>
#include "AmericanAuto.h"
#include "EuropeanAuto.h"

using namespace std;

int main() {
	const int NUM = 4;
	iAutomobile* automobile[NUM];

    //Create your automobiles
	for (int i = 0; i < NUM; ++i) {
		automobile[i] = CreateAutomobile();
	}

	//Have them each travel 100 miles
	cout << "-------------Travelling 100 miles-------------" << endl;
	cout << "All input will be in miles" << endl;
	for (int i = 0; i < NUM; ++i) {
		Travel(automobile[i], 100.0);
	}

	//Get a report
	for (int i = 0; i < NUM; ++i) {
		PrintReport(automobile[i]);
	}

	//Add 5 gallons of gas
	cout << "-------------Adding 5 gallons of gas-------------" << endl;
	cout << "All input will be in gallons" << endl;
	for (int i = 0; i < NUM; ++i) {
		AddFuel(automobile[i], 5.0);
	}

	//Have them each travel 100 miles
	cout << "-------------Travelling 100 miles-------------" << endl;
	cout << "All input will be in miles" << endl;
	for (int i = 0; i < NUM; ++i) {
		Travel(automobile[i], 100.0);
	}

	//Get a report
	for (int i = 0; i < NUM; ++i) {
		PrintReport(automobile[i]);
	}

	//cleanup
	for (int i = 0; i < NUM; ++i) {
		delete automobile[i];
	}

	return 0;
}