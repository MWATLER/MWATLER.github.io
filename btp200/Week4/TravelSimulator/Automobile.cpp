// Automobile.cpp - Implementation of the Automobile class
//
// 12-Mar-19  M. Watler         Created.
//
#include "Automobile.h"

//NOTE: Should have a default constructor

Automobile::Automobile(string _make, string _model, string _colour, int _year)
{
    make = _make;
    model = _model;
    colour = _colour;
    year = _year;
    fuelInTank = 0;
	fuelEfficiency = 0;
}
/*
Automobile::Automobile(string make, string model, string colour, int year)
{
    this->make = make;
    this->model = model;
    this->colour = colour;
    this->year = year;
    fuelInTank = 0;
}
*/
void Automobile::setFuelEfficiency(double _efficiency)
{
    fuelEfficiency = _efficiency;
}

void Automobile::addFuel(double _liters)
{
    fuelInTank += _liters;//ignore tank capacity
}

void Automobile::drive(double _distance)
{
    //liters consumed = liters/100km divide by 100km to get liters/km
    //                  then multiply that by the distance in km
    double fuelConsumed = fuelEfficiency / 100 * _distance;
    fuelInTank -= fuelConsumed;
    if (fuelInTank < 0) {
        fuelInTank = 0;
        char message[128];
        sprintf(message, "WARNING: The %s %d %s %s has no gas left in the tank\n", colour.c_str(), year, make.c_str(), model.c_str());
        cout << message;
    }
}

void Automobile::displayReport() const
{
    cout << "The " << colour << " " << year << " " << make << " " << model << " has " << fuelInTank << " left in the tank" << endl;
}

