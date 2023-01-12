//Stooge.cpp - function definitions for the stooge base class

#include "Stooge.h"
#include "Curly.h"
#include "Larry.h"
#include "Moe.h"

std::unique_ptr<Stooge> Stooge::make_stooge(int choice) {
	if (choice == 1) {
		return std::unique_ptr<Larry>(new Larry);
	}
	else if (choice == 2) {
		return std::unique_ptr<Moe>(new Moe);
	}
	else {
		return std::unique_ptr<Curly>(new Curly);
	}
}
