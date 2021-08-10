//Sphere.cpp - function definitions for a sphere

#include <iostream>
#include "Sphere.h"

Sphere::Sphere(double r) : radius(r) {}

Shape* Sphere::clone() const {
    return new Sphere(*this);
}

void Sphere::display() const {
    std::cout << "radius = " << radius << std::endl;
}

double Sphere::volume() const {
    return 4.18879 * radius * radius * radius;//4/3 pi radius^3
}

bool Sphere::operator==(const Shape& s)const {
    const Sphere* c = dynamic_cast<const Sphere*>(&s);
    return c ? radius == c->radius : false;
}