//TrafficLight.cpp - function definitions for a traffic light

#include <iostream>
#include "TrafficLight.h"

using namespace std;

TrafficLight::TrafficLight(double x, double y, LightState state) {
	xPos = x;
	yPos = y;
	this->state = state;
	if (this->state == LightState::Green) time = 0.0;
	else if (this->state == LightState::Amber) time = GREEN_PERIOD;
	else if (this->state == LightState::Red) time = GREEN_PERIOD + AMBER_PERIOD;
}

void TrafficLight::Travel(double timeStep) {
	time += timeStep;
	if (time < GREEN_PERIOD) {
		state = LightState::Green;
	}
	else if (time < GREEN_PERIOD + AMBER_PERIOD) {
		state = LightState::Amber;
	}
	else if (time < GREEN_PERIOD + AMBER_PERIOD + RED_PERIOD) {
		state = LightState::Red;
	}
	else if (time > CYCLE_PERIOD) {
		time -= CYCLE_PERIOD;
		state = LightState::Green;
	}
}

void TrafficLight::DrawLight() const {
	if (state == LightState::Red) cout << "R";
	else if (state == LightState::Amber) cout << "A";
	else if (state == LightState::Green) cout << "G";
}
