// Vehicle.h - Class declaration for a vehicle
//
// 09-Mar-21  M. Watler         Created.
//

#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>

class Vehicle {
private:
    std::string make;
    std::string model;
    std::string colour;
    int year;

public:
    //NOTE: Should have a default constructor
    Vehicle(std::string _make, std::string _model, std::string _colour, int _year);
    std::string GetMake() const;
    std::string GetModel() const;
    std::string GetColour() const;
    int GetYear() const;
    void displayReport() const;
    void displayReport(double fuel) const;
    ~Vehicle();
};

#endif//_VEHICLE_H_