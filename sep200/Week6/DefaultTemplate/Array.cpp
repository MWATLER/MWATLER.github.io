// Static Data Member Declaration
// Array.cpp

#include <iostream>
#include "Array.h"

int main() {
    Array<> s, t;
    Array<double> u;
    Array<int, 40> v;

    std::cout << Array<>::cnt() << std::endl;
    std::cout << Array<double>::cnt() << std::endl;
    std::cout << Array<int, 40>::cnt() << std::endl;
}
