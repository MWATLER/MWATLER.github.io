//SeriesCircuit.cpp - Simulator for a series electrical circuit
//
// 15-Feb-21  M. Watler         Created.
#include<iostream>
#include "Inductor.h"
#include "Resistor.h"
#include "Capacitor.h"

using namespace std;

int main(void) {
/*
	Inductor inductor1(0.01), inductor2(0.001);
	Inductor inductor3(inductor1);
	Inductor inductor4;
	inductor4 = inductor2;

	Resistor resistor1(100);
	Resistor resistor2(resistor1);

	Capacitor capacitor1(0.0001);
	Capacitor capacitor2;
	capacitor2 = capacitor1;
*/
	const int NUM = 8;
	Component *component[NUM];
	component[0] = new Inductor(0.01);
	component[1] = new Inductor(0.005);
	component[2] = new Inductor(0.001);
	component[3] = new Inductor(0.0005);

	component[4] = new Resistor(100);
	component[5] = new Resistor(200);

	component[6] = new Capacitor(0.0001);
	component[7] = new Capacitor(0.00005);

//	component[0]->Print();

	for (double current = 0; current < 1; current += 0.1) {
		cout << "Current:" << current << endl;
		for (int i = 0; i < NUM; ++i) {
			component[i]->SetCurrent(current);
			component[i]->PrintReport();
		}
	}

	for (int i = 0; i < NUM; ++i) {
		delete component[i];
	}

	return 0;
}