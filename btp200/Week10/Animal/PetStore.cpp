//PetStore.cpp - main program for pet animals

#include <iostream>
#include "Animal.h"

using namespace std;

int main(void) {
	const int NUM = 3;
	Animal* pets[NUM];
	for (int i = 0; i < NUM; ++i) {
		pets[i] = CreateAnimal();
	}

	cout << endl;
	for (int i = 0; i < NUM; ++i) {
		cout << pets[i]->GetName() << " has a worth of $" << pets[i]->CalculateWorth() << endl;
	}
	cout << endl;

	//Let's fatten the animals
	for (int i = 0; i < NUM; ++i) {
		*pets[i] << 10;
	}

	for (int i = 0; i < NUM; ++i) {
		cout << pets[i]->GetName() << " has a worth of $" << pets[i]->CalculateWorth() << endl;
	}
	cout << endl;

	//Let's diet the animals
	for (int i = 0; i < NUM; ++i) {
		*pets[i] >> 5;
	}

	for (int i = 0; i < NUM; ++i) {
		cout << pets[i]->GetName() << " has a worth of $" << pets[i]->CalculateWorth() << endl;
	}

	return 0;
}