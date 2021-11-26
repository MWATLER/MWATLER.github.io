// NCube.cpp - Replicated Base Classes


#include <iostream>
#include "NCube.h"

NCube::NCube(const char* n, double l)
    : Name(n), len(l) { }

double NCube::volume() const {
    return len * len * len;
}