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

void Inductor::SetCurrent(double _current) {
	current[1] = current[0];
	current[0] = _current;
}

double Inductor::GetVoltage(void) {
	return inductance * (current[0] - current[1]) / timestep;
}

void Inductor::PrintReport() {
	std::cout << "Inductor voltage:" << GetVoltage() << std::endl;
}

Inductor::~Inductor() {
	std::cout << "Inductor::~Inductor()" << std::endl;
	if (current != nullptr) {
		delete[] current;
		current = nullptr;
	}
}
