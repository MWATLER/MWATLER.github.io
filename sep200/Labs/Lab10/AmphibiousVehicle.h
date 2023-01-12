//AmphibiousVehicle.h - class declaration for an amphibious vehicle

#ifndef _AMPHIBIOUSVEHICLE_H_
#define _AMPHIBIOUSVEHICLE_H_

#include <iostream>
#include "Boat.h"
#include "Automobile.h"

class AmphibiousVehicle:public Boat, public Automobile {
	//TODO: Add a variable for the name of the amphibious vehicle and add
	//      a variable for the operating mode.
public:
	//TODO: Add three constant class variables indicating these modes: none, automobile, boat

    //Add a constructor that passes through the name of the amphibious vehicle. This name should
	//also be passed through to the boat and automobile classes

	//Add a Travel function that takes as an argument the distance and returns error status.
	//Depending on the mode, the travel function will call either the travel function of the
	//automobile class or the travel function of the boat class. The travel function should
	//be run in a try-catch block. If an exception is thrown, it should be caught here.
	//The only exception we are expecting is a message from either the boat or the automobile.
	//Be sure to set the error status to out of fuel.

	//Add an AddFuel function that takes as an argument the amount of fuel and returns error status.
	//Depending on the mode, the add fuel function will call either the add fuel function of the
	//automobile class or the add fuel function of the boat class.

	//Add getter functions for name, fuel and cost. When getting the fuel, be sure to return
	//the total fuel used by both the boat and the automobile portions of the amphibious vehicle.
	//Likewise, when getting the cost, be sure to return the costs of both the boat and automobile.

	//Add an UnsetMode function to unset a mode, and a
	//SetMode function to set a mode. For instance, if we are changing from 
	//the automobile mode to the boat mode, we have to unset the automobile mode
	//then set the boat mode. You will do this using bitwise expressions.

};

#endif// _AMPHIBIOUSVEHICLE_H_