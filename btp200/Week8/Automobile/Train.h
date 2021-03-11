// Train.h - Class declaration for a car
//
// 09-Mar-21  M. Watler         Created.
//

#include "Vehicle.h"

class Train : public Vehicle {
private:
    double fuelEfficiency;
    double fuelInTank;
    const int tankCapacity = 10000;

public:
    //NOTE: Should have a default constructor
    Train(std::string _make, std::string _model, std::string _colour, int _year);
    void setFuelEfficiency(double _efficiency);
    double getFuel(void) const;
    void addFuel(double _liters);
    void removeFuel(double _liters);
    void drive(double _distance);
    void displayReport() const;
    using Vehicle::displayReport;//use overloaded displayReport functions in the parent class
    ~Train();
};

void operator>>(Train& v1, Train& v2);//v1 >> v2
void operator+=(Train& v, double fuel);//v += fuel
