//PetStoreMain.cpp - main function for the petstore

#include "PetStore.h"

int main() {
	PetStore petstore("PetDumb");
	petstore.SetDog();
	petstore.SetCat();
	petstore.PrintInfo();

	return 0;
}