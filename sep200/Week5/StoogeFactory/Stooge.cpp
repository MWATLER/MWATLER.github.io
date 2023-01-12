//Stooge.cpp - function definitions for the stooge base class

#include "Stooge.h"
#include "Curly.h"
#include "Larry.h"
#include "Moe.h"

Stooge* Stooge::make_stooge(int choice) {//a factory of Stooge objects
    if (choice == 1) return new Larry;
    else if (choice == 2) return new Moe;
    else return new Curly;
}
