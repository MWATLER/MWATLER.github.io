//Freighter.h - class declaration for a freighter

#ifndef _FREIGHTER_H_
#define _FREIGHTER_H_

#include <vector>
#include "Cargo.h"

class Freighter {
	std::vector<Cargo> cargo;
public:
	Freighter& operator+=(const Cargo& investment);
	Freighter& operator-=(const std::string& _name);
	Cargo* operator[](const double& value);
	Cargo* operator[](const int& index);
	void display(void (*disp)(std::ostream&, const Cargo& cargo));
};

double calcTotalWorth(std::vector<Cargo>::iterator begin, std::vector<Cargo>::iterator end);

#endif// _FREIGHTER_H_