//Resistor.h - class declaration for the resistor
//
// 15-Feb-21  M. Watler         Created.

class Resistor {
	double resistance;
	double current;
public:
	Resistor();
	Resistor(double _resistance);
	Resistor(const Resistor& resistor);//Copy constructor
	Resistor& operator=(const Resistor& resistor);//Copy assignment
	void SetCurrent(double _current);
	double GetVoltage(void);
	~Resistor();
};