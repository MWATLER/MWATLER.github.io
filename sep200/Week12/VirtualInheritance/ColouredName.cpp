// ColouredName.cpp - Replicated Base Classes

#include <iostream>
#include "ColouredName.h"

ColouredName::ColouredName(const char* n, ulong c)
    : Name(n), color(c) { }

ulong ColouredName::GetColour() const {
    return color;
}