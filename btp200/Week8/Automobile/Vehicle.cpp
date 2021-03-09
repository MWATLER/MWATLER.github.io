// Vehicle.cpp - Implementation of the Vehicle class
//
// 09-Mar-21  M. Watler         Created.
//
#include "Vehicle.h"

using namespace std;

//NOTE: Should have a default constructor

Vehicle::Vehicle(string _make, string _model, string _colour, int _year)
{
    cout << "Vehicle::Vehicle" << endl;
    make = _make;
    model = _model;
    colour = _colour;
    year = _year;
}

string Vehicle::GetMake() const {
    return make; 
}

string Vehicle::GetModel() const {
    return model; 
}

string Vehicle::GetColour() const {
    return colour; 
}

int Vehicle::GetYear() const {
    return year; 
}

void Vehicle::displayReport() const
{
    cout << "This is a " << GetColour() << " " << GetYear() << " " << GetMake() << " " << GetModel() << endl;
}

void Vehicle::displayReport(double fuel) const {
    cout << "The " << GetColour() << " " << GetYear() << " " << GetMake() << " " << GetModel() << " has " << fuel << " left in the tank" << endl;
}

Vehicle::~Vehicle() {
    cout << "Vehicle::~Vehicle" << endl;
}

