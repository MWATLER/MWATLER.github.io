// Name.cpp -0 Replicated Base Classes

#include <iostream>
#include <iomanip>
#include "Name.h"

Name::Name(const char* n) : name(n) {}
void Name::display() const {
    std::cout << std::left << std::setw(60)
        << name << std::right << std::endl;
}