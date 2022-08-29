//PetStore.h - class declaration for a pet store

#ifndef _PETSTORE_H_
#define _PETSTORE_H_

#include <iostream>
#include "Dog.h"
#include "Cat.h"

class PetStore {//The petstore has a dog and a cat
	std::string name;
	Dog dog;//invoke the default constructor for dog
	Cat cat;//invoke the default constructor for cat
public:
	PetStore(std::string _name);
	void SetDog();
	void SetCat();
	void PrintInfo();
};





#endif// _PETSTORE_H_
