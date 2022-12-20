//AnalogCircuit.h - header file for the analog circuit
//
// 21-May-22  M. Watler         Created.
// 27-May-22  M. Watler         Added graphical display.

#ifndef _ANALOGCIRCUIT_H_
#define _ANALOGCIRCUIT_H_

#include <fstream>
#include <list>
#include <Windows.h>    
#include <gl/GL.h>    
#include <gl/GLU.h>    
#include <gl/glut.h>
#include <gl/freeglut.h>
#include "Component.h"

extern int windowWidth, windowHeight;
extern double scalingFactor;

void start();

class AnalogCircuit {
	const double T = 0.000001;//timestep of 1uS
	const double timeMax = 0.1;
	const double tolerance = 0.0001;//
	const double freq = 50;//50Hz
	const double Vpeak = 10.0;//10V
	const int xoffset = 50;
	double I;
	std::list<Component*> component;//polymorphism with the STL
	std::ofstream fout;
public:
	AnalogCircuit(std::string filename);//dump output data to a file
	static void display(float R, float G, float B);//display output data on the screen
	void run();
	void CostFunctionV(double& current, double V);
	~AnalogCircuit();
};

#endif// _ANALOGCIRCUIT_H_
