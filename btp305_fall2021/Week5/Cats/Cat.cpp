//Cat.cpp - function definitions for a cat

#include <iomanip>//setw
#include "Cat.h"

using namespace std;

Cat::Cat(std::string _name) {
	name = _name;
}

Cat& Cat::operator+=(const CatToy& toy) {
	bool found = false;
	for (int i = 0; i < numToys && !found; ++i) {//does the cat already have this toy?
		if (catToy[i] == &toy) found = true;
	}
	if (!found) {//if not, resize the array of pointers and add the toy
		const CatToy** tmp = nullptr;
		tmp = new const CatToy * [numToys + 1];//the new array of pointers
		for (int i = 0; i < numToys; ++i) {
			tmp[i] = catToy[i];//point to the existing CatToy objects
		}
		tmp[numToys] = &toy;//point to the new CatToy object
		++numToys;
		delete[] catToy;//get rid of the old array of pointers
		catToy = tmp;//set the array of pointers to tmp
	}

	return *this;
}

Cat& Cat::operator-=(const CatToy& toy) {
	bool found = false;
	for (int i = 0; i < numToys && !found; ++i) {
		if (&toy == catToy[i]) {
			found = true;
			catToy[i] = nullptr;//let's cheat and simply set the pointer to nullptr
			                    //This is incomplete. I should resize the array of pointers
		}
	}
	return *this;
}

//Since the CatToy objects have been created outside of the Cat class, 
//Cat is not responsible for destroying them.

std::ostream& operator<<(std::ostream& os, const Cat& cat) {
	os << cat.name << " has " << cat.numToys << " toys. They are:" << endl;
	for (int i = 0; i < cat.numToys; ++i) {
		os << "Name:" << setw(15) << cat.catToy[i]->GetName() << " Colour:" << setw(8) << cat.catToy[i]->GetColour() << " Cost:" << setw(8) << fixed << setprecision(2) << cat.catToy[i]->GetCost() << endl;
	}
	return os;
}
