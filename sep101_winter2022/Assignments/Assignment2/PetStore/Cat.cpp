//Cat.cpp - function definitions for a cat

#include "Cat.h"

using namespace std;

Cat::Cat() {
	name = "";
	age = 0;
	monthlyCost = 0.0;
}

void Cat::SetCat(string _name, int _age, double cost) {
	name = _name;
	age = _age;
	monthlyCost = cost;
}

void Cat::PrintInfo() {
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << name << ", " << age << " years, $" << monthlyCost << " per month." << endl;
}