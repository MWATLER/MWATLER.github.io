//Capacitor.cpp - function definitions for the capacitor
//
// 15-Feb-21  M. Watler         Created.
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

void Capacitor::SetCurrent(double _current) {
	current = _current;
	voltage[1] = voltage[0];
	voltage[0] += (current / capacitance) * timestep;
}

double Capacitor::GetVoltage(void) {
	return voltage[0];
}

void Capacitor::PrintReport() {
	std::cout << "Capacitor voltage:" << GetVoltage() << std::endl;
}

Capacitor::~Capacitor() {
	std::cout << "Capacitor::~Capacitor()" << std::endl;
	if (voltage != nullptr) {
		delete[] voltage;
		voltage = nullptr;
	}
}
