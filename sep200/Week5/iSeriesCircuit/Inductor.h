//Inductor.h - class declaration for the inductor
//
// 15-Feb-21  M. Watler         Created.

#include "Component.h"

class Inductor : public Component { 
	double inductance;
	double* current;
	double const timestep = 0.001;
	double GetVoltage(void);
public:
	Inductor();
	Inductor(double _inductance);
	void SetCurrent(double _current);
	void PrintReport(void);
	~Inductor();
//  void Print(){std::cout<<"Inductor::Print()"<<std::endl;}
};