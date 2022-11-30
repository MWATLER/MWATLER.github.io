//ACVoltage.cpp - main function for an alternating current voltage applied to an inductor

#define _USE_MATH_DEFINES
#include <fstream>
#include <iomanip>
#include <math.h>//M_PI
#include "Inductor.h"

using namespace std;

int main() {
	Inductor inductor(0.01);//Inductance of 0.01 Henries
	const double delta = 0.0001;//timestep of 0.1ms
	const double frequency = 50.0;//50Hz
	ofstream file("L.dat");//over-writes an existing file

	file << setw(16) << "TIME" << setw(16) << "VOLTAGE" << setw(16) << "CURRENT" << endl;
	for (double time = 0.0; time < 0.1; time += delta) {//run for 0.1 seconds
		double voltage = 10.0*sin(2 * M_PI * frequency * time);
		double current = inductor.GetCurrent(voltage, delta);
		file << setw(16) << time << setw(16) << voltage << setw(16) << current << endl;
	}
	//clean-up
	file.close();

	return 0;
}