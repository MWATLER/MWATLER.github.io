//Freighter.h - class declaration for a freighter

#ifndef _FREIGHTER_H_
#define _FREIGHTER_H_

#include <vector>
#include "Cargo.h"

class Freighter {
	std::vector<Cargo> cargo;
public:
	Freighter();
	Freighter(const Freighter& rhs);
	Freighter& operator=(const Freighter& rhs);
	Freighter(Freighter&& rhs) noexcept;
	Freighter& operator=(Freighter&& rhs) noexcept;
	Freighter& operator+=(const Cargo& rhs);
	Freighter& operator-=(const std::string name);
	Cargo* operator[](const double& value);
	Cargo* operator[](const int& index);
	void display(void (*cargoDisp)(std::ostream& os, const Cargo& cargo));
};

double calcTotalWorth(std::vector<Cargo>::iterator begin, std::vector<Cargo>::iterator end);

#endif// _FREIGHTER_H_
