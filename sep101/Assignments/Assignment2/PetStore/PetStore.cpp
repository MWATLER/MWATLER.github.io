//PetStore.cpp - function definitions for a petstore

#include "PetStore.h"

using namespace std;

PetStore::PetStore(std::string _name) {
	name = _name;
}

void PetStore::SetDog() {
	std::string name;
	int age;
	double expense;
	cout << "Enter the dog's name: ";
	cin >> name;
	cout << "Enter the dog's age: ";
	cin >> age;
	cout << "Enter the dog's monthly expense: ";
	cin >> expense;
	dog.SetDog(name, age, expense);
}

void PetStore::SetCat() {
	std::string name;
	int age;
	double expense;
	cout << "Enter the cat's name: ";
	cin >> name;
	cout << "Enter the cat's age: ";
	cin >> age;
	cout << "Enter the cat's monthly expense: ";
	cin >> expense;
	cat.SetCat(name, age, expense);
}

void PetStore::PrintInfo() {
	dog.PrintInfo();
	cat.PrintInfo();
}