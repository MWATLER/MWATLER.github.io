//Animal.h - class declaration for the animal interface class

#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>

class Animal {
public:
	virtual std::string GetName() = 0;
	virtual void SetWeight(double) = 0;
	virtual void SetAge(double) = 0;
	virtual void addWeight(double) = 0;
	virtual void reduceWeight(double) = 0;
	virtual double CalculateWorth() = 0;
};

void operator<<(Animal& an, double amt);//add weight
void operator>>(Animal& an, double amt);//reduce weight

Animal* CreateAnimal();

#endif//_ANIMAL_H_