//Car.h - class declaration for a car travelling along a road

#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include "TrafficLight.h"

#define GAP 1//keep 1 space away from the car in front

enum class Direction {
	WestEast=0,
	NorthSouth,
};

class Car {
	std::string name;
	double xPos;
	double yPos;
	double speed;
	Direction direction;
	Car *nextCar;
	int lightIndex;
	TrafficLight* trafficLight[NUM_LIGHTS];
	int numLights;
public:
	Car(std::string name, double x, double y, double speed, Direction dir, Car* next, TrafficLight* lights[]);
	double GetXPos() const {
		return xPos;
	}
	double GetYPos() const {
		return yPos;
	}
	void Travel(double timeStep);
	~Car();
};


#endif// _CAR_H_