// Car.h - Class declaration for a car
//
// 09-Mar-21  M. Watler         Created.
//

#include "Vehicle.h"

class Car : public Vehicle {
private:
    double fuelEfficiency;
    double fuelInTank;
    const int tankCapacity = 50;

public:
    //NOTE: Should have a default constructor
    Car(std::string _make, std::string _model, std::string _colour, int _year);
    void setFuelEfficiency(double _efficiency);
    double getFuel(void) const;
    void addFuel(double _liters);
    void removeFuel(double _liters);
    void drive(double _distance);
    void displayReport() const;
    ~Car();
};
//better to have these inside the class, because they only operate on Car objects
void operator>>(Car& v1, Car& v2);
void operator+=(Car& v, double fuel);
