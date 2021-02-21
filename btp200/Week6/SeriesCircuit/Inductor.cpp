//Inductor.cpp - function definitions for the inductor
//
// 15-Feb-21  M. Watler         Created.
#include "Inductor.h"

Inductor::Inductor() {
	inductance = 0.0;
	current = new double[2];
	current[0] = 0.0;
	current[1] = 0.0;
}

Inductor::Inductor(double _inductance) {
	inductance = _inductance;
	current = new double[2];
	current[0] = 0.0;
	current[1] = 0.0;
}

Inductor::Inductor(const Inductor& inductor) {//Copy constructor
	this->inductance = inductor.inductance;
	this->current = new double[2];
	this->current[0] = inductor.current[0];
	this->current[1] = inductor.current[1];
}

Inductor& Inductor::operator=(const Inductor& inductor) {//Copy assignment
	if (this != &inductor) {
		this->inductance = inductor.inductance;
		delete [] this->current;
		if (inductor.current != nullptr) {
			this->current = new double[2];
			this->current[0] = inductor.current[0];
			this->current[1] = inductor.current[1];
		}
	}
	return *this;
}

void Inductor::SetCurrent(double _current) {
	current[1] = current[0];
	current[0] = _current;
}

double Inductor::GetVoltage(void) {
	return inductance * (current[0] - current[1]) / timestep;
}

Inductor::~Inductor() {
	if (current != nullptr) {
		delete[] current;
		current = nullptr;
	}
}
