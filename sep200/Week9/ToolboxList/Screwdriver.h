//Screwdriver.h - the screwdriver class

#ifndef _SCREWDRIVERIF_H_
#define _SCREWDRIVERIF_H_

#include "ToolIf.h"

class Screwdriver : public ToolIf {
	std::string name;
	double cost;
public:
	Screwdriver(std::string name, double cost) {
		this->name = name;
		this->cost = cost;
	}
	std::string GetName() const {
		return name;
	}
	double GetCost() const {
		return cost;
	}
	void display(std::ostream& os) {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << name << " is a screwdriver and costs $" << cost << "." << std::endl;
	}
};

#endif _SCREWDRIVERIF_H_