//Car.cpp - function definitions for a car travelling along a road

#include "Car.h"

using namespace std;

Car::Car(std::string name, double x, double y, double speed, Direction dir, Car* next, TrafficLight* lights[]) {
	this->name = name;
	xPos = x;
	yPos = y;
	this->speed = speed;
	direction = dir;
	nextCar = next;
	for (int i = 0; i < NUM_LIGHTS; ++i) trafficLight[i] = lights[i];
	lightIndex = 0;
}

void Car::Travel(double timeStep) {
	if (direction == Direction::WestEast) {
		if (xPos > trafficLight[lightIndex]->GetXPos() + 1)++lightIndex;//gone beyond the current light
		if (xPos >= trafficLight[lightIndex]->GetXPos()) {//we're at a light
			if ((trafficLight[lightIndex]->GetState() == LightState::Green) &&
				(xPos < nextCar->GetXPos() - GAP)) {
				if (lightIndex < NUM_LIGHTS-1) ++lightIndex;
				xPos += speed * timeStep;
			}
		}
		else {//on the open road (no lights)
			if (xPos < nextCar->GetXPos() - GAP) 
				xPos += speed * timeStep;
		}
	}
	else if (direction == Direction::NorthSouth) {
		if (yPos > trafficLight[lightIndex]->GetYPos() + 1)++lightIndex;//gone beyond the current light
		if (yPos >= trafficLight[lightIndex]->GetYPos()) {//we're at a light
			if ((trafficLight[lightIndex]->GetState() == LightState::Green) &&
				(yPos < nextCar->GetYPos() - GAP)) {
				if (lightIndex < NUM_LIGHTS-1) ++lightIndex;
				yPos += speed * timeStep;
			}
		}
		else {//on the open road (no lights)
			if (yPos < nextCar->GetYPos() - GAP) 
				yPos += speed * timeStep;
		}
	}
}

Car::~Car() {
	nextCar = nullptr;
	for (int i = 0; i < NUM_LIGHTS; ++i) trafficLight[i] = nullptr;
	lightIndex = 0;
}