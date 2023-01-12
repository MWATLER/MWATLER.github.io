//Automobile.h - class declaration for an automobile

#ifndef _AUTOMOBILE_H_
#define _AUTOMOBILE_H_

#include <iostream>
#include "Vehicle.h"

class Automobile : public Vehicle{
	//TODO: Add variables for name, fuel efficiency (L per 100km), fuel in the tank and accumulated cost
	//      Assume the cost per litre of fuel is $1.30
	//      Assume the tank capacity is 50.0L
public:
    //TODO: Create a constructor that passes through the automobiles's name, the fuel efficiency, 
	//      and the initial fuel in the tank. Be sure to initialize the cost based on this fuel.
	//      Print out a message indicating how much fuel has been added and its cost.
	//
    //      Complete the interface functions from the abstract base class
	//
	//      Travel should accept distance as an argument and return an error status. Based on the 
	//      distance travelled and the fuel efficiency, one can calculate the amount of fuel consumed.
	//      If the fuel consumed is greater than the fuel in the tank, an exception is thrown with the message:
	//      "Automobile out of fuel".
	//      If there is enough fuel, decrease the fuel in the tank by the fuel consumed, and calculate the cost of the travel. Print out 
	//      a message showing how much fuel is left in the tank, how far the automobile travelled, and the cost of the travel.
	//
	//      AddFuel should accept an amount as an argument and return an error status.
	//      If the amount added will cause the tank to overflow, set the return status to fuel overflow. Readjust the 
	//      amount to result in a full tank. Print out an error message that includes the actual amount added and the actual cost.
	//      If the amount added does not result in an overflow, calculate the cost and add the amount to the fuel in the tank.
	//      Print out a message showing the amount added and the cost.
	//      Be sure to always add the actual cost to the accumulated cost in either case.
	//
	//      GetFuel simply returns the amount of fuel in the tank.
	//
	//      GetCost simply returns the accumulated cost of all the fuel purchased.
};

#endif// _AUTOMOBILE_H_
