//CloningMain.cpp - main function for geometric shapes

#include <iostream>
#include "Cube.h"
#include "Sphere.h"

void displayVolume(const Shape* shape) {
    if (shape)
        std::cout << shape->volume() << std::endl;
    else
        std::cout << "error" << std::endl;
}

Shape* select() {
    Shape* shape;
    double x;
    char c;
    std::cout << "s (sphere), c (cube) : ";
    std::cin >> c;
    if (c == 's') {
        std::cout << "dimension : ";
        std::cin >> x;
        shape = new Sphere(x);
    }
    else if (c == 'c') {
        std::cout << "dimension : ";
        std::cin >> x;
        shape = new Cube(x);
    }
    else
        shape = nullptr;
    return shape;
}

int main() {
    Shape* shape = select();
    Shape* clone = shape->clone();
    displayVolume(shape);
    displayVolume(clone);
    delete clone;
    delete shape;
}
