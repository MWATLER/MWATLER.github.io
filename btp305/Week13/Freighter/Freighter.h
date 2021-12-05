//Freighter.h - class declaration for a freighter

#ifndef _FREIGHTER_H_
#define _FREIGHTER_H_

#include <vector>
#include "Cargo.h"

class Freighter {
	std::vector<Cargo> cargo;
	const double limit = 10000.00;
	double worth;
public:
	Freighter& operator+=(const Cargo& investment);
	Cargo* operator[](const std::string& name_);
	void display(void (*disp)(std::ostream&, const Cargo& cargo));
};

double calcTotalWorth(std::vector<Cargo>::iterator begin, std::vector<Cargo>::iterator end);

#endif// _FREIGHTER_H_