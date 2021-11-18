//Dog.h - class declaration for a dog

#ifndef _DOG_H_
#define _DOG_H_

#include <iostream>

class Dog {
	std::string name;
	int age;
	double monthlyCost;
public:
	Dog();
	void SetDog(std::string _name, int _age, double cost);
	void PrintInfo();
};

#endif// _DOG_H_
