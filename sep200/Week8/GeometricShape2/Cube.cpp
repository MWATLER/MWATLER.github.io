//Cube.cpp - function definitions for cube

#include <iostream>
#include "Cube.h"

Cube::Cube(double l) : length(l) {}

Shape* Cube::clone() const {
    return new Cube(*this);
}

void Cube::display() const {
    std::cout << "length = " << length << std::endl;
}

double Cube::volume() const {
    return length * length * length;
}

bool Cube::operator==(const Shape& s)const {
    const Cube* c = dynamic_cast<const Cube*>(&s);
    return c ? length == c->length : false;
}