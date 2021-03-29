//SpaceTravel.cpp - main function for the space ships

#include <iostream>
#include "Cargo.h"
#include "Starship.h"
#include "Warbird.h"

using namespace std;

int main(void) {
	const int NUM = 3;
	const double speedOfLight = 299792458.0;//299,792,458 m/s
/*	Spaceship* spaceship[NUM];
	spaceship[0] = new Cargo("Bessel", 5);
	spaceship[1] = new Warbird("Eagle", 1, 10);
	spaceship[2] = new Starship("Enterprise", 2, 5);

	//Accelerate to 0.05 the speed of light
	for (int i = 0; i < NUM; ++i) {
		spaceship[i]->ChangeSpeed(0.05 * speedOfLight);
	}

	//Travel for 1000 hours
	for (int i = 0; i < NUM; ++i) {
		spaceship[i]->Travel(1000.0 * 3600.0);//1000 hours
	}

	//Print a report for each
	for (int i = 0; i < NUM; ++i) {
		spaceship[i]->PrintReport();
	}

	//Fire weapons
	for (int i = 1; i < NUM; ++i) {
		spaceship[i]->FireTorpedos(4);
		spaceship[i]->FireLaserCannons(100);
	}

	//Print a report for each again
	cout << endl;
	for (int i = 0; i < NUM; ++i) {
		spaceship[i]->PrintReport();
	}

	//Delete the spaceships
	for (int i = 0; i < NUM; ++i) {
		delete spaceship[i];
	}

	//Now let us exercise the copy constructor and copy assignment
	Starship starship1("Yamato", 2, 8);
	Starship starship2("Enterprise", 3, 6);
	Starship starship3(starship1);//Copy constructor
	starship3.SetName("Emirates");
	Starship starship4;
	starship4 = starship2;//Copy assignment

	//Accelerate to 0.05 the speed of light
	starship1.ChangeSpeed(0.05 * speedOfLight);
	starship2.ChangeSpeed(0.05 * speedOfLight);
	starship3.ChangeSpeed(0.05 * speedOfLight);
	starship4.ChangeSpeed(0.05 * speedOfLight);

	//Travel for 1000 hours
	starship1.Travel(1000.0 * 3600.0);//1000 hours
	starship2.Travel(1000.0 * 3600.0);//1000 hours
	starship3.Travel(1000.0 * 3600.0);//1000 hours
	starship4.Travel(1000.0 * 3600.0);//1000 hours

	//Print a report for each
	cout << endl;
	starship1.PrintReport();
	starship2.PrintReport();
	starship3.PrintReport();
	starship4.PrintReport();

    //Fire weapons
	starship1.FireTorpedos(4);
	starship1.FireLaserCannons(100);
	starship2.FireTorpedos(4);
	starship2.FireLaserCannons(100);
	starship3.FireTorpedos(4);
	starship3.FireLaserCannons(100);
	starship4.FireTorpedos(4);
	starship4.FireLaserCannons(100);

	//Print a report for each
	cout << endl;
	starship1.PrintReport();
	starship2.PrintReport();
	starship3.PrintReport();
	starship4.PrintReport();
*/
	Spaceship* spaceship2[NUM];
	spaceship2[0] = new Starship("Khan", 3, 6);
	spaceship2[1] = new Starship((Starship &)*spaceship2[0]);//copy constructor
	spaceship2[1]->SetName("Zeus");
	spaceship2[2] = new Starship();
	(Starship&)*spaceship2[2] = (Starship &)(*spaceship2[0]);//copy assignment
	spaceship2[2]->SetName("Apollo");

	//Accelerate to 0.1 the speed of light
	for (int i = 0; i < NUM; ++i) {
		spaceship2[i]->ChangeSpeed(0.1 * speedOfLight);
	}

	//Travel for 1000 hours
	for (int i = 0; i < NUM; ++i) {
		spaceship2[i]->Travel(1000.0 * 3600.0);//1000 hours
	}

	//Print a report for each
	for (int i = 0; i < NUM; ++i) {
		spaceship2[i]->PrintReport();
	}

	//Fire weapons
	for (int i = 0; i < NUM; ++i) {
		spaceship2[i]->FireTorpedos(4);
		spaceship2[i]->FireLaserCannons(100);
	}

	//Print a report for each again
	cout << endl;
	for (int i = 0; i < NUM; ++i) {
		spaceship2[i]->PrintReport();
	}

	//Delete the spaceships
	for (int i = 0; i < NUM; ++i) {
		delete spaceship2[i];
	}


	return 0;
}

