//Shape.h - class declaration for a shape

#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape {
public:
    virtual double volume() const = 0;
    virtual void display() const = 0;
    virtual bool operator==(const Shape&) const = 0;
};

#endif// _SHAPE_H_
