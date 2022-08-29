//StarFleet.cpp - the main program for space travel

// 25-Mar-21  M. Watler         Created.

#include <iostream>
#include "Warbird.h"
#include "Starship.h"
#include "Cargo.h"

using namespace std;

int main() {
	Warbird warbird(1000, 0.1, 30000, 100000, 3000, 100, 5);
	Starship starship(1000, 0.1, 100000, 300000, 10000, 100, 5);
	Cargo cargo1(1000, 0.1, 1000000, 5000000, 10000);
	Cargo cargo2(1000, 0.1, 1500000, 7500000, 15000);
	const double speedOfLight = 299792458.0;

	//Accelerate to 0.01 the speed of light
	double velocity = 0.01 * speedOfLight;

	bool ret = warbird.ChangeSpeed(velocity);
	if (!ret) cout << "The warbird cannot keep up" << endl;
	ret = starship.ChangeSpeed(velocity);
	if (!ret) cout << "The starship cannot keep up" << endl;
	ret = cargo1.ChangeSpeed(velocity);
	if (!ret) cout << "The cargo1 ship cannot keep up" << endl;
	ret = cargo2.ChangeSpeed(velocity);
	if (!ret) cout << "The cargo2 ship cannot keep up" << endl;

	cout << "ACCELERATION REPORT 1:" << endl;
	warbird.GenerateReport();
	starship.GenerateReport();
	cargo1.GenerateReport();
	cargo2.GenerateReport();

    //Generate some fuel while travelling
	warbird.Travel(36000, 0.01);
	starship.Travel(36000, 0.01);
	cargo1.Travel(36000, 0.01);
	cargo2.Travel(36000, 0.01);

	cout << "TRAVEL REPORT 1:" << endl;
	warbird.GenerateReport();
	starship.GenerateReport();
	cargo1.GenerateReport();
	cargo2.GenerateReport();

	//Accelerate to 0.015 the speed of light
	double changeVelocity = 0.005 * speedOfLight;

	cout << "ACCELERATION REPORT 2:" << endl;
	ret = warbird.ChangeSpeed(changeVelocity);
	if (!ret) cout << "The warbird cannot keep up" << endl;
	ret = starship.ChangeSpeed(changeVelocity);
	if (!ret) cout << "The starship cannot keep up" << endl;
	ret = cargo1.ChangeSpeed(changeVelocity);
	if (!ret) cout << "The cargo1 ship cannot keep up" << endl;
	ret = cargo2.ChangeSpeed(changeVelocity);
	if (!ret) cout << "The cargo2 ship cannot keep up" << endl;

	warbird.GenerateReport();
	starship.GenerateReport();
	cargo1.GenerateReport();
	cargo2.GenerateReport();

	//Generate some fuel while travelling
	warbird.Travel(36000, 0.01);
	starship.Travel(36000, 0.01);
	cargo1.Travel(36000, 0.01);
	cargo2.Travel(36000, 0.01);

	cout << "TRAVEL REPORT 2:" << endl;
	warbird.GenerateReport();
	starship.GenerateReport();
	cargo1.GenerateReport();
	cargo2.GenerateReport();

	//Accelerate to 0.02 the speed of light
	changeVelocity = 0.005 * speedOfLight;

	cout << "ACCELERATION REPORT 3:" << endl;
	ret = warbird.ChangeSpeed(changeVelocity);
	if (!ret) cout << "The warbird cannot keep up" << endl;
	ret = starship.ChangeSpeed(changeVelocity);
	if (!ret) cout << "The starship cannot keep up" << endl;
	ret = cargo1.ChangeSpeed(changeVelocity);
	if (!ret) cout << "The cargo1 ship cannot keep up" << endl;
	ret = cargo2.ChangeSpeed(changeVelocity);
	if (!ret) cout << "The cargo2 ship cannot keep up" << endl;

	warbird.GenerateReport();
	starship.GenerateReport();
	cargo1.GenerateReport();
	cargo2.GenerateReport();

	cout << "COMBAT REPORT 1:" << endl;
	//Fire lasers and torpedoes
	ret = warbird.FireLaser(100);
	if (!ret) cout << "Warbird unable to fire lasers" << endl;
	warbird.FireTorpedo(10);
	ret = starship.FireLaser(100);
	if (!ret) cout << "Starship unable to fire lasers" << endl;
	warbird.GenerateReport();
	starship.GenerateReport();
	cargo1.GenerateReport();
	cargo2.GenerateReport();

	return 0;
}