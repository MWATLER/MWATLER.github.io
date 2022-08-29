//Sphere.cpp - function definitions for a sphere

#include "Sphere.h"

Sphere::Sphere(double r) : radius(r) {}

Shape* Sphere::clone() const {
    return new Sphere(*this);//default copy constructor
}

double Sphere::volume() const {
    return 4.18879 * radius * radius * radius;//4/3 pi radius^3
}