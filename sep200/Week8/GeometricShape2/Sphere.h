//Sphere.h - class declaration for a sphere

#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Shape.h"

class Sphere : public Shape {
    double radius;
public:
    Sphere(double);
    void display() const;
    double volume() const;
    Shape* clone() const;
    bool operator==(const Shape&) const;
};

#endif// _SPHERE_H_