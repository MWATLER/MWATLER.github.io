//TravelSimulator.cpp - A travel simulator
//                      Several cars and trains are tested for their fuel consumption
//
// 09-Mar-21  M. Watler         Created.
//

#include<iostream>
#include "Car.h"
#include "Train.h"

int main()
{
    Car car1("Toyota", "Corolla", "grey", 2013);
    Car car2("Honda", "Civic", "red", 2012);
    Train train1("Bombardier", "Aventra", "black", 1972);
    Train train2("National Steel Car", "Flat", "brown", 1966);

    car1.addFuel(50.0);
    car2.addFuel(50.0);
    train1.addFuel(5000.0);
    train2.addFuel(5000.0);

    //Set fuel efficiency for city driving then drive 200km
    car1.setFuelEfficiency(8.2);
    car1.drive(200.0);
    car2.setFuelEfficiency(7.8);
    car2.drive(200.0);
    train1.setFuelEfficiency(10.6);
    train1.drive(200.0);
    train2.setFuelEfficiency(12.29);
    train2.drive(200.0);

    //Set fuel efficiency for rural driving then drive 300km
    car1.setFuelEfficiency(6.2);
    car1.drive(300.0);
    car2.setFuelEfficiency(5.8);
    car2.drive(300.0);
    train1.setFuelEfficiency(9.0);
    train1.drive(300.0);
    train2.setFuelEfficiency(10.8);
    train2.drive(200.0);

    //display the results
    std::cout << std::endl << std::endl;
    car1.displayReport();
    car2.displayReport();
    train1.displayReport();
    train2.displayReport();

    car1 >> car2;
    car1 += 50;

    train2 >> train1;
    train2 += 1000;
    std::cout << std::endl << std::endl;

    train2.displayReport(1000);

    std::cout << std::endl << std::endl;
    car1.displayReport();
    car2.displayReport();
    train1.displayReport();
    train2.displayReport();

    return 0;
}
