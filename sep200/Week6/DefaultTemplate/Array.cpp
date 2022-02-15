// Static Data Member Declaration
// Array.cpp

#include <iostream>
#include "Array.h"

int main() {
    Array<> s, t;//uses all default parameters: T is int, size is 50
    Array<double> u;//T is double, size is the default of 50
    Array<int, 40> v;//T is int, size is 40

    std::cout << Array<>::cnt() << std::endl;
    std::cout << Array<double>::cnt() << std::endl;
    std::cout << Array<int, 40>::cnt() << std::endl;
}
