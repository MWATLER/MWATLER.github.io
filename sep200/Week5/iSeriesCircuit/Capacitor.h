//Capacitor.h - class declaration for the capacitor
//
// 15-Feb-21  M. Watler         Created.

#include "Component.h"

class Capacitor : public Component {
	double capacitance;
	double current;
	double* voltage;
	double const timestep = 0.001;
	double GetVoltage(void);
public:
	Capacitor();
	Capacitor(double _capacitance);
	void SetCurrent(double _current);
	void PrintReport(void);
	~Capacitor();
};