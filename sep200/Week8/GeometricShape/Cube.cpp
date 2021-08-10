//Cube.cpp - function definitions for cube

#include "Cube.h"

Cube::Cube(double l) : length(l) {}

Shape* Cube::clone() const {
    return new Cube(*this);
}

double Cube::volume() const {
    return length * length * length;
}