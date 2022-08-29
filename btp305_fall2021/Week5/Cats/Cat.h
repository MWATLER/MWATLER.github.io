//Cat.h - class declaration for a cat

#ifndef _CAT_H_
#define _CAT_H_

#include <iostream>
#include "CatToy.h"

class Cat {
	std::string name = "";
	//Objects of type CatToy are created outside of Cat.
    //If there was only one CatToy, a single pointer would suffice.
	//If there are many CatToy's, then we need an array of pointers.

	//If we know how many CatToy's there are, we could use 
	//const CatToy* catToy[NUM];

	//We do not know how many CatToy's there are, so we have to use a double pointer.
	const CatToy** catToy = nullptr;//an array of pointers
	int numToys{ 0 };
public:
	Cat(std::string _name);
	Cat& operator+=(const CatToy& toy);
	Cat& operator-=(const CatToy& toy);
	friend std::ostream& operator<<(std::ostream& os, const Cat& cat);
};

#endif// _CAT_H_
