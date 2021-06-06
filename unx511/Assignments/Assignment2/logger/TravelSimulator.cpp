//TravelSimulator.cpp - A travel simulator
//                      Several cars are tested for their fuel consumption
//
// 12-Mar-19  M. Watler         Created.
//

#include <signal.h>
#include <unistd.h>
#include "Automobile.h"
#include "Logger.h"

bool isRunning;

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            isRunning=false;
	    break;
    }
}

int main()
{
    signal(SIGINT, shutdownHandler);
    InitializeLog();
    SetLogLevel(DEBUG);
    Automobile *car1 = new Automobile("Toyota", "Corolla", "grey", 2013);
    Automobile *car2 = new Automobile("Honda", "Civic", "red", 2012);
    Automobile *car3 = new Automobile("Chevrolet", "Impala", "blue", 2008);
    Automobile *car4 = new Automobile("Cadillac", "Escalade", "black", 2016);
    Log(DEBUG, __FILE__, __func__, __LINE__, "Created the objects");
        
    isRunning=true;
    int track=1;
    while(isRunning) {
        car1->emptyFuel();
        car2->emptyFuel();
        car3->emptyFuel();
        car4->emptyFuel();
        car1->addFuel(50.0);
        car2->addFuel(50.0);
        car3->addFuel(50.0);
        car4->addFuel(50.0);
        Log(DEBUG, __FILE__, __func__, __LINE__, "Added the fuel");
        
        //Set fuel efficiency for city driving then drive
	int cityDistance = track*100.0;
        car1->setFuelEfficiency(8.2);
        car1->drive(cityDistance);
        car2->setFuelEfficiency(7.8);
        car2->drive(cityDistance);
        car3->setFuelEfficiency(10.6);
        car3->drive(cityDistance);
        car4->setFuelEfficiency(17.29);
        car4->drive(cityDistance);
        Log(DEBUG, __FILE__, __func__, __LINE__, "Set the efficiency");

        car1->addFuel(50.0);
        car2->addFuel(50.0);
        car3->addFuel(50.0);
        car4->addFuel(50.0);
        Log(DEBUG, __FILE__, __func__, __LINE__, "Added the fuel again");
        //Set fuel efficiency for highway driving then drive
	int highwayDistance = 500.0-cityDistance;
        car1->setFuelEfficiency(6.2);
        car1->drive(highwayDistance);
        car2->setFuelEfficiency(5.8);
        car2->drive(highwayDistance);
        car3->setFuelEfficiency(7.5);
        car3->drive(highwayDistance);
        car4->setFuelEfficiency(12.5);
        car4->drive(highwayDistance);
        Log(DEBUG, __FILE__, __func__, __LINE__, "Drove the cars");
	track = (track+1)%5 + 1;
        sleep(1);
    }
        
    //display the results
    car1->displayReport();
    car2->displayReport();
    car3->displayReport();
    car4->displayReport();
    Log(DEBUG, __FILE__, __func__, __LINE__, "Displayed the report");

    delete(car1);
    delete(car2);
    delete(car3);
    delete(car4);
    Log(DEBUG, __FILE__, __func__, __LINE__, "Deleted the objects");

    ExitLog();

    return 0;
}
