// NamedCube.cpp - Replicated Base Classes


#include <iostream>
#include "NamedCube.h"

NamedCube::NamedCube(const char* n, double l)
    : Name(n), len(l) { }

double NamedCube::volume() const {
    return len * len * len;
}