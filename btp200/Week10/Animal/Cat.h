//Cat.h - class declaration for a cat

#ifndef _CAT_H_
#define _CAT_H_

#include "Animal.h"

class Cat : public Animal {
	std::string name;
	double weight;
	double age;
	double worth;
	const double LIFESPAN = 15.0;
	const double IDEAL_WEIGHT = 4.0;//kg
public:
	Cat(std::string name);
	std::string GetName();
	void SetWeight(double);
	void addWeight(double);
	void reduceWeight(double);
	void SetAge(double);
	double CalculateWorth();
	~Cat();
};
#endif// _CAT_H_
