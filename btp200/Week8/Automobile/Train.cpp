// Train.cpp - Implementation of the Train class
//
// 09-Mar-21  M. Watler         Created.
//
#include "Train.h"

using namespace std;

//NOTE: Should have a default constructor

Train::Train(string _make, string _model, string _colour, int _year) : Vehicle(_make, _model, _colour, _year)
{
    cout << "Train::Train" << endl;
    fuelInTank = 0;
    fuelEfficiency = 0;
}

void Train::setFuelEfficiency(double _efficiency)//Litres per km
{
    fuelEfficiency = _efficiency;
}

double Train::getFuel(void) const {
    return fuelInTank;
}
void Train::addFuel(double _liters)
{
    fuelInTank += _liters;
    if (fuelInTank > tankCapacity) {
        fuelInTank = tankCapacity;
    }
}

void Train::removeFuel(double _liters) {
    fuelInTank -= _liters;
    if (fuelInTank < 0) {
        fuelInTank = 0;
        cout << "WARNING: The " << GetColour() << " " << GetYear() << " " << GetMake() << " " << GetModel() << " has no gas left in the tank" << endl;
    }
}


void Train::drive(double _distance)
{
    //liters consumed = liters/km times the distance in km
    double fuelConsumed = fuelEfficiency * _distance;
    fuelInTank -= fuelConsumed;
    if (fuelInTank < 0) {
        fuelInTank = 0;
        cout << "WARNING: The " << GetColour() << " " << GetYear() << " " << GetMake() << " " << GetModel() << " has no gas left in the tank" << endl;
    }
}

void Train::displayReport() const
{
    cout << "The " << GetColour() << " " << GetYear() << " " << GetMake() << " " << GetModel() << " has " << fuelInTank << " left in the tank" << endl;
}

Train::~Train() {
    cout << "Train::~Train" << endl;
}


void operator>>(Train& v1, Train& v2) {
    double fuel = v1.getFuel();
    v1.removeFuel(fuel);
    v2.addFuel(fuel);
}

void operator+=(Train& v, double fuel) {
    v.addFuel(fuel);
}