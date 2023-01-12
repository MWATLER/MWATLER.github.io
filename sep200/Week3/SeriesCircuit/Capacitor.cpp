//Capacitor.cpp - function definitions for the capacitor
//
// 09-Jul-21  M. Watler         Created.
#include <iostream>
#include "Capacitor.h"

Capacitor::Capacitor() {
	capacitance = 0.0;
	current = 0;
	voltage = new double[2];
	voltage[0] = 0.0;
	voltage[1] = 0.0;
}

Capacitor::Capacitor(double _capacitance) {
	capacitance = _capacitance;
	current = 0;
	voltage = new double[2];
	voltage[0] = 0.0;
	voltage[1] = 0.0;
}

Capacitor::Capacitor(const Capacitor& capacitor) {//Copy constructor
	*this = capacitor;//invokes the copy assignment
}

Capacitor& Capacitor::operator=(const Capacitor& capacitor) {//Copy assignment
	if (this != &capacitor) {
		//shallow copy of variables
		this->capacitance = capacitor.capacitance;
		this->current = capacitor.current;
		//deep copy of resources
		delete[] this->voltage;//delete the resource of the current object
		this->voltage = new double[2];//reallocate memory for the resource
		if (capacitor.voltage != nullptr) {//copy values over
			this->voltage[0] = capacitor.voltage[0];
			this->voltage[1] = capacitor.voltage[1];
		}
		else {
			this->voltage[0] = 0.0;
			this->voltage[1] = 0.0;
		}
	}
	return *this;
}

Capacitor::Capacitor(Capacitor&& capacitor) noexcept {//Move constructor
	*this = std::move(capacitor);//invoke the move assignment
}

Capacitor& Capacitor::operator=(Capacitor&& capacitor) noexcept {//Move assignment
	if (this != &capacitor) {//don't move to ourself
		//shallow copy
		this->capacitance = capacitor.capacitance;
		this->current = capacitor.current;
		//delete our resource
		delete[] this->voltage;
		//take over the resource of the rhs
		this->voltage = capacitor.voltage;
		//set the rhs to an empty state
		capacitor.capacitance = 0;
		capacitor.current = 0;
		capacitor.voltage = nullptr;
	}
	return *this;
}

void Capacitor::SetCurrent(double _current) {
	current = _current;
	voltage[1] = voltage[0];
	voltage[0] += (current / capacitance) * timestep;
}

double Capacitor::GetVoltage(void) {
	return voltage[0];
}

Capacitor::~Capacitor() {
	if (voltage != nullptr) {
		delete[] voltage;
		voltage = nullptr;
	}
}
