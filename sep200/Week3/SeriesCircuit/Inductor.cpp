//Inductor.cpp - function definitions for the inductor
//
// 09-Jul-21  M. Watler         Created.
#include <iostream>
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
	*this = inductor;
/*	this->inductance = inductor.inductance;
	this->current = new double[2];
	if (inductor.current != nullptr) {
		this->current[0] = inductor.current[0];
		this->current[1] = inductor.current[1];
	}
	else {
		this->current[0] = 0.0;
		this->current[1] = 0.0;
	}*/
}

Inductor& Inductor::operator=(const Inductor& inductor) {//Copy assignment
	if (this != &inductor) {
		this->inductance = inductor.inductance;
		delete[] this->current;
		this->current = new double[2];
		if (inductor.current != nullptr) {
			this->current[0] = inductor.current[0];
			this->current[1] = inductor.current[1];
		}
		else {
			this->current[0] = 0.0;
			this->current[1] = 0.0;
		}
	}
	return *this;
}

Inductor::Inductor(Inductor&& inductor) noexcept {//Move constructor
	*this = std::move(inductor);
/*	this->inductance = inductor.inductance;
	delete[] this->current;
	this->current = inductor.current;
	inductor.inductance = 0.0;
	inductor.current = nullptr;*/
}

Inductor& Inductor::operator=(Inductor&& inductor) noexcept {//Move assignment
	if (this != &inductor) {
		this->inductance = inductor.inductance;
		delete[] this->current;
		this->current = inductor.current;
		inductor.inductance = 0.0;
		inductor.current = nullptr;
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
