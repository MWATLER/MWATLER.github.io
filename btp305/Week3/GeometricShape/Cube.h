//Cube.h - class declarations for a cube

#ifndef _CUBE_H_
#define _CUBE_H_

#include "Shape.h"

class Cube : public Shape {
    double length;
public:
    Cube(double);
    double volume() const;
    Shape* clone() const;
};

#endif _CUBE_H_
