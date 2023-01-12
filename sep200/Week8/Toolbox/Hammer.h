//Hammer.h - the hammer class

#ifndef _HAMMERIF_H_
#define _HAMMERIF_H_

#include "ToolIf.h"

class Hammer : public ToolIf { 
	std::string name;
	double cost;
public:
	Hammer(std::string name, double cost) {
		this->name = name;
		this->cost = cost;
	}
	double GetCost() const {
		return cost;
	}
	void display(std::ostream& os) {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << name << " is a hammer and costs $" << cost << "." << std::endl;
	}
};

#endif _HAMMERIF_H_