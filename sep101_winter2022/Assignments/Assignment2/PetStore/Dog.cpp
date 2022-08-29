//Dog.cpp - function definitions for a dog

#include "Dog.h"

using namespace std;

Dog::Dog() {
	name = "";
	age = 0;
	monthlyCost = 0.0;
}

void Dog::SetDog(string _name, int _age, double cost) {
	name = _name;
	age = _age;
	monthlyCost = cost;
}

void Dog::PrintInfo() {
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << name << ", " << age << " years, $" << monthlyCost << " per month." << endl;
}