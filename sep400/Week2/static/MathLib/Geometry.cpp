//Geometry.cpp - Geometric Calculations
//
// 14-Jan-19  M. Watler         Created.

#include "Geometry.h"

double Circumference(double radius) {
    return 2 * M_PI * radius;
}

double Area(double radius) {
    return M_PI * radius * radius;
}

double Volume(double radius) {
    return 4.0/3.0 * M_PI * radius * radius * radius;
}
