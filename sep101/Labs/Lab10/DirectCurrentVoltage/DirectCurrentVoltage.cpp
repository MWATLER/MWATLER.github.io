//DirectCurrentVoltage.cpp - main function for a direct current voltage applied to an inductor

#include <fstream>
#include <iomanip>
#include "Inductor.h"

using namespace std;

int main() {
	Inductor inductor(0.1);//Inductance of 0.1 Henries
	const double delta = 0.0001;//timestep of 0.1ms
	const double voltage = 10.0;//DC voltage of 10Volts
	ofstream file("L.dat");

	file << setw(8) << "TIME" << setw(8) << "VOLTAGE" << setw(8) << "CURRENT" << endl;
	for (double time = 0.0; time < 0.1; time += delta) {//run for 0.1 seconds
		double current = inductor.GetCurrent(voltage, delta);
		file << setw(8) << time << setw(8) << voltage << setw(8) << current << endl;
	}
	file.close();

	return 0;
}