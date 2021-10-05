//CatToy.h - class declaration for a cat toy

#ifndef _CATTOY_H_
#define _CATTOY_H_

#include <iostream>

class CatToy {
	std::string name = "";
	std::string colour = "";
	double cost = 0.00;
public:
	CatToy() = default;
	CatToy(const std::string& toy);//NAME:COLOUR:COST
	std::string GetName() const { return name; }
	std::string GetColour() const { return colour; }
	double GetCost() const { return cost; }

	friend std::ostream& operator<<(std::ostream& out, const CatToy& toy);
};

#endif// _CATTOY_H_
