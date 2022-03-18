// Automobile.h - Header file for the Automobile class
//
// 12-Mar-19  M. Watler         Created.
//
#include <iostream>

using namespace std;

class Automobile {
private://not necessary
    string make;
    string model;
    string colour;//strings are based on the char array. If we wish to access the char array
	              //directly, we can call c_str(). For example colour.c_str() will access
	              //the char array inside of colour
    int year;
    double fuelEfficiency;
    double fuelInTank;

public:
    Automobile(string _make, string _model, string _colour, int _year);
    void setFuelEfficiency(double _efficiency);
    void addFuel(double _liters);
    void drive(double _distance);
    void displayReport();
};
