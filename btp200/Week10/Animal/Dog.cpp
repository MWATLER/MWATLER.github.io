//Dog.cpp - function definitions for a dog

#include "Dog.h"

Dog::Dog(std::string name) {
	this->name = name;
	weight = 0.0;
	age = 0.0;
	worth = 0.0;
}

std::string Dog::GetName() {
	return name;
}

void Dog::SetWeight(double weight) {
	this->weight = weight;
}

void Dog::addWeight(double wt) {
	weight += wt;
}

void Dog::reduceWeight(double wt) {
	weight -= wt;
}


void Dog::SetAge(double age) {
	this->age = age;
}

double Dog::CalculateWorth() {
	worth = 150.0 * (LIFESPAN - age) - 20 * (weight - IDEAL_WEIGHT) * (weight - IDEAL_WEIGHT);
	if (worth < 0) worth = 0.0;
	return worth;
}

Dog::~Dog() {

}