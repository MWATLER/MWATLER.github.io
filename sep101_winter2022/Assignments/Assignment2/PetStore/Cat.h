//Cat.h - class declaration for a cat

#ifndef _CAT_H_
#define _CAT_H_

#include <iostream>

class Cat {
	std::string name;
	int age;
	double monthlyCost;
public:
	Cat();
	void SetCat(std::string _name, int _age, double cost);
	void PrintInfo();
};

#endif// _CAT_H_
