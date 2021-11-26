//TrafficLight.h - class declaration for a traffic light

#ifndef _TRAFFICLIGHT_H
#define _TRAFFICLIGHT_H

#define NUM_LIGHTS 3

enum class LightState {
	Red=0,
	Amber,
	Green
};

class TrafficLight {
	double xPos;
	double yPos;
	LightState state;
	const double GREEN_PERIOD = 25.0;//time at green
	const double AMBER_PERIOD = 5.0;//time at amber
	const double RED_PERIOD = 30.0;//time at red
	const double CYCLE_PERIOD = GREEN_PERIOD + AMBER_PERIOD + RED_PERIOD;
	double time;
public:
	TrafficLight(double x, double y, LightState state);
	void Travel(double timeStep);
	LightState GetState() const {
		return state;
	}
	double GetXPos() const {
		return xPos;
	}
	double GetYPos() const {
		return yPos;
	}
	void DrawLight() const;
};

#endif _TRAFFICLIGHT_H