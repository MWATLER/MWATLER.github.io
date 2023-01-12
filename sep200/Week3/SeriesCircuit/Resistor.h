//Resistor.h - class declaration for the resistor
//
// 09-Jul-21  M. Watler         Created.

class Resistor {
	double resistance;
	double current;
public:
	Resistor();
	Resistor(double _resistance);
	Resistor(const Resistor& resistor);//Copy constructor
	Resistor& operator=(const Resistor& resistor);//Copy assignment
	Resistor(Resistor&& resistor) noexcept;//Move constructor
	Resistor& operator=(Resistor&& resistor) noexcept;//Move assignment
	void SetCurrent(double _current);
	double GetVoltage(void);
	~Resistor();
};