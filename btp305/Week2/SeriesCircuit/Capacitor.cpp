//Capacitor.cpp - function definitions for the capacitor
//
// 09-Jul-21  M. Watler         Created.
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
	this->capacitance = capacitor.capacitance;
	this->current = capacitor.current;
	this->voltage = new double[2];
	if (capacitor.voltage != nullptr) {
		this->voltage[0] = capacitor.voltage[0];
		this->voltage[1] = capacitor.voltage[1];
	}
	else {
		this->voltage[0] = 0.0;
		this->voltage[1] = 0.0;
	}
}

Capacitor& Capacitor::operator=(const Capacitor& capacitor) {//Copy assignment
	if (this != &capacitor) {
		this->capacitance = capacitor.capacitance;
		this->current = capacitor.current;
		if (capacitor.voltage != nullptr) {
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

Capacitor::Capacitor(Capacitor&& capacitor) {//Move constructor
	this->capacitance = capacitor.capacitance;
	this->current = capacitor.current;
	delete[] this->voltage;
	this->voltage = capacitor.voltage;
	capacitor.capacitance = 0;
	capacitor.current = 0;
	capacitor.voltage = nullptr;
}
/*class Capacitor {
	double capacitance;
	double current;
	double* voltage;*/
Capacitor& Capacitor::operator=(Capacitor&& capacitor) {//Move assignment
	if (this != &capacitor) {
		this->capacitance = capacitor.capacitance;
		this->current = capacitor.current;
		delete[] this->voltage;
		this->voltage = capacitor.voltage;
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
