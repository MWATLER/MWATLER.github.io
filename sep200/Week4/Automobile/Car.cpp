// Car.cpp - Implementation of the Car class
//
// 09-Mar-21  M. Watler         Created.
//
#include "Car.h"

using namespace std;

//NOTE: Should have a default constructor

Car::Car(string _make, string _model, string _colour, int _year) : 
	Vehicle(_make, _model, _colour, _year)
{
    cout << "Car::Car" << endl;
    fuelInTank = 0;
    fuelEfficiency = 0;
}

void Car::setFuelEfficiency(double _efficiency)//Liters per 100km
{
    fuelEfficiency = _efficiency;
}

double Car::getFuel(void) const {
    return fuelInTank;
}

void Car::addFuel(double _liters)
{
    fuelInTank += _liters;
    if (fuelInTank > tankCapacity) {
        fuelInTank = tankCapacity;
    }
}

void Car::removeFuel(double _liters) {
    fuelInTank -= _liters;
    if (fuelInTank < 0 ) {
        fuelInTank = 0;
        cout << "WARNING: The " << GetColour() << " " << GetYear() << " " << GetMake() << " " << GetModel() << " has no gas left in the tank" << endl;
    }
}

void Car::drive(double _distance)
{
    //liters consumed = liters/100km times distance/100km
    double fuelConsumed = fuelEfficiency * _distance/100.0;
    fuelInTank -= fuelConsumed;
    if (fuelInTank < 0) {
        fuelInTank = 0;
        cout << "WARNING: The " << GetColour() << " " << GetYear() << " " << GetMake() << " " << GetModel() << " has no gas left in the tank" << endl;
    }
}

void Car::displayReport() const
{
    Vehicle::displayReport();
    cout << "The " << GetColour() << " " << GetYear() << " " << GetMake() << " " << GetModel() << " has " << fuelInTank << " left in the tank" << endl;
}

Car::~Car() {
    cout << "Car::~Car" << endl;
}

void operator>>(Car& v1, Car& v2) {
    double fuel = v1.getFuel();
    v1.removeFuel(fuel);
    v2.addFuel(fuel);
}

void operator+=(Car& v, double fuel) {
    v.addFuel(fuel);
}
