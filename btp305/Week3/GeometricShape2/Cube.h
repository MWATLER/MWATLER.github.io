//Cube.h - class declarations for a cube

#ifndef _CUBE_H_
#define _CUBE_H_

#include "Shape.h"

class Cube : public Shape {
    double length;
public:
    Cube(double);
    void display() const;
    double volume() const;
    Shape* clone() const;
    bool operator==(const Shape&) const;
};

#endif _CUBE_H_
