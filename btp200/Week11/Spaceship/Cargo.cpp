//Cargo.cpp - function definitions for a cargo ship

#include <iostream>
#include "Cargo.h"

using namespace std;

Cargo::Cargo(const char* _name, int _numPayload) : Spaceship(_name) {
	speed = 0.0;
	distance = 0.0;
	fuel = 10000;//10000kg of antimatter

	numPayload = _numPayload;
	payload = new Payload[numPayload];
	for (int i = 0; i < numPayload; ++i) {
		payload[i].massPassengers = 100000;//1000 people x 100kg each
		payload[i].massPayload = 1000000;//1000kg per person
	}
}

Cargo::Cargo(const Cargo& cg) : Spaceship(cg.GetName()) {
	speed = cg.speed;
	distance = cg.distance;
	fuel = cg.fuel;
	numPayload = cg.numPayload;
	payload = new Payload[numPayload];
	for (int i = 0; i < numPayload; ++i) {
		payload[i].massPassengers = cg.payload[i].massPassengers;
		payload[i].massPayload = cg.payload[i].massPayload;
	}
}

Cargo& Cargo::operator=(const Cargo& rhs) {
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
	}
	return *this;
}

double Cargo::GetMass() {
	double mass = 0;
	for (int i = 0; i < numPayload; ++i) {
		mass += payload[i].massPassengers;
		mass += payload[i].massPayload;
	}
	return mass;
}

bool Cargo::ChangeSpeed(double _speed) {
	double energy = 0.5 * GetMass() * _speed * _speed;//0.5*mass*velocity^2
	double fuelConsumed = energy / (speedOfLight * speedOfLight);//E=mc^2, m=E/c^2
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

void Cargo::Travel(double _time) {
	distance += (speed * _time);
}

void Cargo::PrintReport() {
	cout << GetName() << " has travelled " << distance << "m at a speed of " << speed << "m/s. It has " << fuel << "kg of antimatter left." << endl;
}

Cargo::~Cargo() {
	if (payload != nullptr) {
		delete[] payload;
		payload = nullptr;
	}
}
