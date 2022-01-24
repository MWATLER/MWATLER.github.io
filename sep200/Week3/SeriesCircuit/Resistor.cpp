//Resistor.cpp - function definitions for the resistor
//
// 09-Jul-21  M. Watler         Created.
#include <iostream>
#include "Resistor.h"

Resistor::Resistor() {
	resistance = 0.0;
	current = 0.0;
}

Resistor::Resistor(double _resistance) {
	resistance = _resistance;
	current = 0.0;
}

Resistor::Resistor(const Resistor& resistor) {//Copy constructor
	*this = resistor;
/*	this->resistance = resistor.resistance;
	this->current = resistor.current;*/
}

Resistor& Resistor::operator=(const Resistor& resistor) {//Copy assignment
	if (this != &resistor) {
		this->resistance = resistor.resistance;
		this->current = resistor.current;
	}
	return *this;
}

Resistor::Resistor(Resistor&& resistor) noexcept {//Move constructor
	*this = std::move(resistor);
/*	this->resistance = resistor.resistance;
	this->current = resistor.current;
	resistor.resistance = 0.0;
	resistor.current = 0.0;*/
}

Resistor& Resistor::operator=(Resistor&& resistor) noexcept {//Move assignment
	if (this != &resistor) {
		this->resistance = resistor.resistance;
		this->current = resistor.current;
		resistor.resistance = 0.0;
		resistor.current = 0.0;
	}
	return *this;
}

void Resistor::SetCurrent(double _current) {
	current = _current;
}

double Resistor::GetVoltage(void) {
	return resistance * current;
}

Resistor::~Resistor() {
//Do nothing
}
