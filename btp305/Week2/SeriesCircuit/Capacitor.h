//Capacitor.h - class declaration for the capacitor
//
// 09-Jul-21  M. Watler         Created.

class Capacitor {
	double capacitance;
	double current;
	double* voltage;
	double const timestep = 0.001;
public:
	Capacitor();
	Capacitor(double _capacitance);
	Capacitor(const Capacitor& capacitor);//copy constructor
	Capacitor& operator=(const Capacitor& capacitor);//copy assignment
	Capacitor(Capacitor&& capacitor);//move constructor
	Capacitor& operator=(Capacitor&& capacitor);//move assignment
	void SetCurrent(double _current);
	double GetVoltage(void);
	~Capacitor();
};