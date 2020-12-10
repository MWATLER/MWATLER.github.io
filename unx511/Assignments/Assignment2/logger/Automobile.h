// Automobile.h - Header file for the Automobile class
//
// 12-Mar-19  M. Watler         Created.
//
#include <iostream>

using namespace std;

class Automobile {
    private:
        string make;
        string model;
        string colour;
        int year;
        double fuelEfficiency;
        double fuelInTank;

    public:
        Automobile(string _make, string _model, string _colour, int _year);
        void setFuelEfficiency(double _efficiency);
        void emptyFuel(void);
        void addFuel(double _liters);
        void drive(double _distance);
        void displayReport();
};
