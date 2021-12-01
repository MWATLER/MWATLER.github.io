//DirectCurrentVoltage.cpp - main function for a direct current voltage applied to an inductor

#include <fstream>
#include <iomanip>
#include "Inductor.h"

using namespace std;

int main() {
	Inductor inductor(0.1);
	const double delta = 0.0001;
	const double voltage = 10.0;
	ofstream file("L.dat");

	file << setw(8) << "TIME" << setw(8) << "VOLTAGE" << setw(8) << "CURRENT" << endl;
	for (double time = 0.0; time < 0.1; time += delta) {
		double current = inductor.GetCurrent(voltage, delta);
		file << setw(8) << time << setw(8) << voltage << setw(8) << current << endl;
	}
	file.close();

	return 0;
}