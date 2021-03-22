//Cat.cpp - function definitions for a cat

#include "Cat.h"

Cat::Cat(std::string name) {
	this->name = name;
	weight = 0.0;
	age = 0.0;
	worth = 0.0;
}

std::string Cat::GetName() {
	return name;
}

void Cat::SetWeight(double weight) {
	this->weight = weight;
}

void Cat::addWeight(double wt) {
	weight += wt;
}

void Cat::reduceWeight(double wt) {
	weight-=wt;
}


void Cat::SetAge(double age) {
	this->age = age;
}

double Cat::CalculateWorth() {
	worth = 100.0 * (LIFESPAN - age) - 100 * (weight - IDEAL_WEIGHT) * (weight - IDEAL_WEIGHT);
	if (worth < 0) worth = 0.0;
	return worth;
}

Cat::~Cat() {

}
