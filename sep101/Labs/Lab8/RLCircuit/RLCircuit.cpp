//RLCircuit.cpp - main function for the RL circuit

#include <iomanip>
#include "Resistor.h"
#include "Inductor.h"

using namespace std;

int main() {
	Resistor R1("R1", 100.0);//100 ohms
	Resistor R2("R2", 50.0);//50 ohms
	Inductor L1("L1", 0.01);//0.01 Henries
	const double timestep = 0.001;//1ms
	double current;//current going through the circuit
	double voltage;//voltage drop across the circuit

	//gradually increase the current to 0.1 amps
	cout << "RISING CURRENT" << endl;
	cout << "    CURRENT    VOLTAGE" << endl;
	for (double time = 0.0; time <= 0.1001; time += timestep) {//a timestep of 1ms, run for 100ms
		current = 1.0 * time;//a ramp current
		voltage = R1.GetVoltage(current) + R2.GetVoltage(current) + L1.GetVoltage(current, timestep);
		cout << setw(10) << current << setw(10) << voltage << endl;
	}

	//have the current drop rapidly to 0 amps
	cout << endl;
	cout << "RAPIDLY FALLING CURRENT" << endl;
	cout << "    CURRENT    VOLTAGE" << endl;
	for (double time = 0.1; time < 0.2 && current>0.0; time += timestep) {
		current -= 0.04;
		voltage = R1.GetVoltage(current) + R2.GetVoltage(current) + L1.GetVoltage(current, timestep);
		cout << setw(10) << current << setw(10) << voltage << endl;
	}


	return 0;
}