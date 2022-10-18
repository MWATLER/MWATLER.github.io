//TravelSimulator.c - A travel simulator
//                    Several cars are tested for their fuel consumption

#include <stdio.h>
#include "Automobile.h"

int main()
{
    struct Automobile car1 = { "Toyota", "Corolla", "grey", 2013 };
    struct Automobile car2 = { "Honda", "Civic", "red", 2012 };
    struct Automobile car3 = { "Chevrolet", "Impala", "blue", 2008 };
    struct Automobile car4 = { "Cadillac", "Escalade", "black", 2016 };

    //Add 50 litres of fuel to each car
    car1.fuelInTank = 50;
    car2.fuelInTank = 50;
    car3.fuelInTank = 50;
    car4.fuelInTank = 50;

    //Set fuel efficiency for city driving then drive 200km
    printf("\nDriving 200km in the city\n");
    car1.fuelEfficiency = 8.2;
    drive(&car1, 200.0);
    car2.fuelEfficiency = 7.8;
    drive(&car2, 200.0);
    car3.fuelEfficiency = 10.6;
    drive(&car3, 200.0);
    car4.fuelEfficiency = 17.29;
    drive(&car4, 200.0);

    //display the results
    displayReport(car1);
    displayReport(car2);
    displayReport(car3);
    displayReport(car4);
    printf("\n");
    //Set fuel efficiency for highway driving then drive 300km
    printf("\nDriving 300km on the highway\n");
    car1.fuelEfficiency = 6.2;
    drive(&car1, 300.0);
    car2.fuelEfficiency = 5.8;
    drive(&car2, 300.0);
    car3.fuelEfficiency = 7.5;
    drive(&car3, 300.0);
    car4.fuelEfficiency = 12.5;
    drive(&car4, 300.0);

    //display the results
    displayReport(car1);
    displayReport(car2);
    displayReport(car3);
    displayReport(car4);

    return 0;
}
