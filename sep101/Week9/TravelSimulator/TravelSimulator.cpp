//TravelSimulator.cpp - A travel simulator
//                      Several cars are tested for their fuel consumption
//
// 12-Mar-19  M. Watler         Created.
//

#include "Automobile.h"

int main()
{
    Automobile car1("Toyota", "Corolla", "grey", 2013);
    Automobile car2("Honda", "Civic", "red", 2012);
    Automobile car3("Chevrolet", "Impala", "blue", 2008);
    Automobile car4("Cadillac", "Escalade", "black", 2016);

    car1.addFuel(50.0);
    car2.addFuel(50.0);
    car3.addFuel(50.0);
    car4.addFuel(50.0);

    //Set fuel efficiency for city driving then drive 200km
    car1.setFuelEfficiency(8.2);//8.2L/100km
    car1.drive(200.0);
    car2.setFuelEfficiency(7.8);
    car2.drive(200.0);
    car3.setFuelEfficiency(10.6);
    car3.drive(200.0);
    car4.setFuelEfficiency(17.29);
    car4.drive(200.0);

    //Set fuel efficiency for highway driving then drive 300km
    car1.setFuelEfficiency(6.2);//6.2L/100km
    car1.drive(300.0);
    car2.setFuelEfficiency(5.8);
    car2.drive(300.0);
    car3.setFuelEfficiency(7.5);
    car3.drive(300.0);
    car4.setFuelEfficiency(12.5);
    car4.drive(200.0);

    //display the results
    car1.displayReport();
    car2.displayReport();
    car3.displayReport();
    car4.displayReport();

    return 0;
}
