//Spaceship.cpp - function declarations for a spaceship

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "Spaceship.h"

Spaceship::Spaceship() {
	name = nullptr;
}

Spaceship::Spaceship(const char* _name) {
	int len = strlen(_name) + 1;
	name = new char[len];
	strcpy(name, _name);
}

Spaceship& Spaceship::operator=(const Spaceship& rhs) {
	if (name != nullptr) {
		delete[] name;
	}
	int len = strlen(rhs.name) + 1;
	name = new char[len];
	strcpy(name, rhs.name);
	return *this;
}

char* Spaceship::GetName() const {
	return name;
}

void Spaceship::SetName(const char* _name) {
	if (name != nullptr) {
		delete[] name;
	}
	int len = strlen(_name) + 1;
	name = new char[len];
	strcpy(name, _name);
}

Spaceship::~Spaceship() {
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}
}
