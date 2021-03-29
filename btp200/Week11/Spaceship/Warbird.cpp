//Warbird.cpp - function definitions for a warbird ship

#include <iostream>
#include "Warbird.h"

using namespace std;

Warbird::Warbird(const char* _name, int _numPayload, int _numWeapons) : Spaceship(_name) {
	speed = 0.0;
	distance = 0.0;
	fuel = 10000;//10000kg of antimatter

	numPayload = _numPayload;
	payload = new Payload[numPayload];
	for (int i = 0; i < numPayload; ++i) {
		payload[i].massPassengers = 30000;//300 people x 100kg each
		payload[i].massPayload = 3000;//10kg per person
	}

	numWeapons = _numWeapons;
	weapons = new Weapons[numWeapons];
	for (int i = 0; i < numWeapons; ++i) {
		weapons[i].numLaserCannons = 1;
		weapons[i].numTorpedos = 100;
	}
}

Warbird::Warbird(const Warbird& wb) : Spaceship(wb.GetName()) {
	speed = wb.speed;
	distance = wb.distance;
	fuel = wb.fuel;
	numPayload = wb.numPayload;
	payload = new Payload[numPayload];
	for (int i = 0; i < numPayload; ++i) {
		payload[i].massPassengers = wb.payload[i].massPassengers;
		payload[i].massPayload = wb.payload[i].massPayload;
	}

	numWeapons = wb.numWeapons;
	weapons = new Weapons[numWeapons];
	for (int i = 0; i < numWeapons; ++i) {
		weapons[i].numLaserCannons = wb.weapons[i].numLaserCannons;
		weapons[i].numTorpedos = wb.weapons[i].numTorpedos;
	}
}

Warbird& Warbird::operator=(const Warbird& rhs) {
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

double Warbird::GetMass() {
	double mass = 0;
	for (int i = 0; i < numPayload; ++i) {
		mass += payload[i].massPassengers;
		mass += payload[i].massPayload;
	}
	return mass;
}

bool Warbird::ChangeSpeed(double _speed) {
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

void Warbird::Travel(double _time) {
	distance += (speed * _time);
}

bool Warbird::FireTorpedos(int _num) {
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

bool Warbird::FireLaserCannons(double _time) {
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

void Warbird::PrintReport() {
	cout << GetName() << " has travelled " << distance << "m at a speed of " << speed << "m/s. It has " << fuel << "kg of antimatter left." << endl;
	cout << GetName() << " has " << weapons[0].numTorpedos * numWeapons << " torpedos left." << endl;
}

Warbird::~Warbird() {
	if (payload != nullptr) {
		delete[] payload;
		payload = nullptr;
	}
	if (weapons != nullptr) {
		delete[] weapons;
		weapons = nullptr;
	}
}
