//AirForceMain.cpp - main function for the air force

#include <iostream>
#include "Plane.h"

using namespace std;

int main(void) {
	Plane* plane;
	int numPlanes;
	int numPilots;
	string* pilot;

	cout << "How many planes in your air force? ";
	cin >> numPlanes;
	plane = new Plane[numPlanes];

	cout << endl;
	for (int i = 0; i < numPlanes; ++i) {
		cout << "How many pilots in plane " << (i + 1) << "? ";
		cin >> numPilots;
		pilot = new string[numPilots];
		for (int j = 0; j < numPilots; ++j) {
			cout << "What is the name of pilot " << (j + 1) << "? ";
			cin >> pilot[j];
		}
		plane[i].SetName(pilot, numPilots);
		plane[i].AddFuel(3000);
		delete[] pilot;
		cout << endl;
	}
	cout << endl;

	//Travel 5000km
	for (int i = 0; i < numPlanes; ++i) {
		bool ret = plane[i].Travel(5000);
		if (!ret) cout << "Plane " << (i + 1) << " unable to travel 5000km" << endl;
	}

	//Give a report
	for (int i = 0; i < numPlanes; ++i) {
		plane[i].Report();
	}

	//Delete the planes
	if (plane != nullptr) {
		delete[] plane;
		plane = nullptr;
	}

	return 0;
}

