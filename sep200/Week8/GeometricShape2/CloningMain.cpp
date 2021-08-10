//CloningMain.cpp - main function for geometric shapes

#include <iostream>
#include "Cube.h"
#include "Sphere.h"

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
    Shape* s1 = select();
    Shape* s2 = select();
    s1->display();
    s2->display();
    if (*s1 == *s2)
        std::cout << "Same" << std::endl;
    else
        std::cout << "Different" << std::endl;
    delete s1;
    delete s2;
}