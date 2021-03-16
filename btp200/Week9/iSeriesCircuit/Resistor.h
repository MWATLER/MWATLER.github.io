//Resistor.h - class declaration for the resistor
//
// 15-Feb-21  M. Watler         Created.

#include "Component.h"

class Resistor : public Component {
	double resistance;
	double current;
	double GetVoltage(void);
public:
	Resistor();
	Resistor(double _resistance);
	void SetCurrent(double _current);
	void PrintReport(void);
	~Resistor();
};