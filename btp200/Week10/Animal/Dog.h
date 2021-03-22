//Dog.h - class declaration for a dog

#ifndef _DOG_H_
#define _DOG_H_
#include "Animal.h"

class Dog : public Animal {
	std::string name;
	double weight;
	double age;
	double worth;
	const double LIFESPAN = 11.5;
	const double IDEAL_WEIGHT = 20.0;//kg
public:
	Dog(std::string name);
	std::string GetName();
	void SetWeight(double);
	void addWeight(double);
	void reduceWeight(double);
	void SetAge(double);
	double CalculateWorth();
	~Dog();
};
#endif// _DOG_H_
