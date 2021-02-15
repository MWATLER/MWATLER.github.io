//Inductor.h - class declaration for the inductor
//
// 15-Feb-21  M. Watler         Created.

class Inductor {
	double inductance;
	double* current;
	double const timestep = 0.001;
public:
	Inductor();
	Inductor(double _inductance);
	Inductor(const Inductor& inductor);//Copy constructor
	Inductor& operator=(const Inductor& inductor);//Copy assignment
	void SetCurrent(double _current);
	double GetVoltage(void);
	~Inductor();
};