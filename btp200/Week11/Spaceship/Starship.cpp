//Starship.cpp - function definitions for a starship ship

#include <iostream>
#include "Starship.h"

using namespace std;

Starship::Starship() {
	speed = 0.0;
	distance = 0.0;
	fuel = 10000;//10000kg of antimatter
}


Starship::Starship(const char* _name, int _numPayload, int _numWeapons) : Spaceship(_name) {
	speed = 0.0;
	distance = 0.0;
	fuel = 10000;//10000kg of antimatter*/

	numPayload = _numPayload;
	payload = new Payload[numPayload];
	for (int i = 0; i < numPayload; ++i) {
		payload[i].massPassengers = 100000;//1000 people x 100kg each
		payload[i].massPayload = 100000;//100kg per person
	}

	numWeapons = _numWeapons;
	weapons = new Weapons[numWeapons];
	for (int i = 0; i < numWeapons; ++i) {
		weapons[i].numLaserCannons = 2;
		weapons[i].numTorpedos = 100;
	}
}

Starship::Starship(const Starship& st) : Spaceship(st.GetName()){
	speed = st.speed;
	distance = st.distance;
	fuel = st.fuel;
	numPayload = st.numPayload;
	payload = new Payload[numPayload];
	for (int i = 0; i < numPayload; ++i) {
		payload[i].massPassengers = st.payload[i].massPassengers;
		payload[i].massPayload = st.payload[i].massPayload;
	}

	numWeapons = st.numWeapons;
	weapons = new Weapons[numWeapons];
	for (int i = 0; i < numWeapons; ++i) {
		weapons[i].numLaserCannons = st.weapons[i].numLaserCannons;
		weapons[i].numTorpedos = st.weapons[i].numTorpedos;
	}
}

Starship& Starship::operator=(const Starship& rhs) {
	if (this != &rhs) {
		//Call base class assignment operator
		(Spaceship&)*this = rhs;
		speed = rhs.speed;
		distance = rhs.distance;
		fuel = rhs.fuel;
		numPayload = rhs.numPayload;
		if (payload != nullptr) {
			delete[] payload;
		}
		payload = new Payload[numPayload];
		for (int i = 0; i < numPayload; ++i) {
			payload[i].massPassengers = rhs.payload[i].massPassengers;
			payload[i].massPayload = rhs.payload[i].massPayload;
		}

		numWeapons = rhs.numWeapons;
		if (weapons != nullptr) {
			delete[] weapons;
		}
		weapons = new Weapons[numWeapons];
		for (int i = 0; i < numWeapons; ++i) {
			weapons[i].numLaserCannons = rhs.weapons[i].numLaserCannons;
			weapons[i].numTorpedos = rhs.weapons[i].numTorpedos;
		}
	}
	return *this;
}

void Starship::SetName(const char* _name) {
	Spaceship::SetName(_name);
}

double Starship::GetMass() {
	double mass = 0;
	for (int i = 0; i < numPayload; ++i) {
		mass += payload[i].massPassengers;
		mass += payload[i].massPayload;
	}
	return mass;
}

bool Starship::ChangeSpeed(double _speed) {
	double energy = 0.5 * GetMass() * _speed * _speed;
	double fuelConsumed = energy / (speedOfLight * speedOfLight);
	bool ret = true;
	if (fuelConsumed > fuel) {
		ret = false;
	}
	else {
		fuel -= fuelConsumed;
		speed += _speed;
	}
	return ret;
}

void Starship::Travel(double _time) {
	distance += (speed * _time);
}

bool Starship::FireTorpedos(int _num) {
	bool ret = true;
	if (weapons[0].numTorpedos < _num) {
		ret = false;
	}
	else {
		for (int i = 0; i < numWeapons; ++i) {
			--weapons[i].numTorpedos;
		}
	}
	return ret;
}

bool Starship::FireLaserCannons(double _time) {
	const double energyPerSecond = 1000000000000000;//1 trillion megawatts
	double energy = energyPerSecond * _time * numWeapons;
	double fuelRequired = energy / (speedOfLight * speedOfLight);
	bool ret = true;
	if (fuel < fuelRequired) {
		ret = false;
	}
	else {
		fuel -= fuelRequired;
	}
	return ret;
}

void Starship::PrintReport() {
	cout << GetName() << " has travelled " << distance << "m at a speed of " << speed << "m/s. It has " << fuel << "kg of antimatter left." << endl;
	cout << GetName() << " has " << weapons[0].numTorpedos * numWeapons << " torpedos left." << endl;
}

Starship::~Starship() {
	if (payload != nullptr) {
		delete[] payload;
		payload = nullptr;
	}
	if (weapons != nullptr) {
		delete[] weapons;
		weapons = nullptr;
	}
}
