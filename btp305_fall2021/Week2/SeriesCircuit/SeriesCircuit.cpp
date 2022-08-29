//SeriesCircuit.cpp - Simulator for a series electrical circuit
//
// 09-Jul-21  M. Watler         Created.
#include<iostream>
#include "Inductor.h"
#include "Resistor.h"
#include "Capacitor.h"

using namespace std;

int main(void) {
	Inductor inductor1(0.01), inductor2(0.001);
	Inductor inductor3(inductor1);
	Inductor inductor4;
	inductor4 = inductor2;

	Resistor resistor1(100);
	Resistor resistor2(resistor1);

	Capacitor capacitor1(0.0001);
	Capacitor capacitor2;
	capacitor2 = capacitor1;

	for (double current = 0; current < 1; current += 0.1) {
		inductor1.SetCurrent(current);
		inductor2.SetCurrent(current);
		inductor3.SetCurrent(current);
		inductor4.SetCurrent(current);
		resistor1.SetCurrent(current);
		resistor2.SetCurrent(current);
		capacitor1.SetCurrent(current);
		capacitor2.SetCurrent(current);
		cout << "Current:" << current << endl;
		cout << "inductor1 voltage:" << inductor1.GetVoltage() << " inductor2 voltage:" << inductor2.GetVoltage() << endl;
		cout << "inductor3 voltage:" << inductor3.GetVoltage() << " inductor4 voltage:" << inductor4.GetVoltage() << endl;
		cout << "resistor1 voltage:" << resistor1.GetVoltage() << " resistor2 voltage:" << resistor2.GetVoltage() << endl;
		cout << "capacitor1 voltage:" << capacitor1.GetVoltage() << " capacitor2 voltage:" << capacitor2.GetVoltage() << endl << endl;
	}


	Inductor inductor5(std::move(inductor1));
	Capacitor capacitor3;
	capacitor3 = std::move(capacitor1);

	cout << endl << endl;

	for (double current = 1; current < 2; current += 0.1) {
		inductor2.SetCurrent(current);
		inductor3.SetCurrent(current);
		inductor4.SetCurrent(current);
		inductor5.SetCurrent(current);
		resistor1.SetCurrent(current);
		resistor2.SetCurrent(current);
		capacitor2.SetCurrent(current);
		capacitor3.SetCurrent(current);
		cout << "Current:" << current << endl;
		cout << "inductor2 voltage:" << inductor2.GetVoltage() << endl;
		cout << "inductor3 voltage:" << inductor3.GetVoltage() << " inductor4 voltage:" << inductor4.GetVoltage() << endl;
		cout << "inductor5 voltage:" << inductor5.GetVoltage() << endl;
		cout << "resistor1 voltage:" << resistor1.GetVoltage() << " resistor2 voltage:" << resistor2.GetVoltage() << endl;
		cout << "capacitor2 voltage:" << capacitor2.GetVoltage() << endl;
		cout << "capacitor3 voltage:" << capacitor3.GetVoltage() << endl << endl;
	}

}