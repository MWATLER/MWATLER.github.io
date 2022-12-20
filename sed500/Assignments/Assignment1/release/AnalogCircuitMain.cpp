//AnalogCircuitMain.cpp - main function for the analog circuit simulation
//                        Generate graphs with the OpenGL graphics library
// 
// https://content.byui.edu/file/2315e65e-a34a-48d3-814d-4175a2b74ed5/1/intro/165-opengl-visualStudio2017.html
// Create a project
// Right-click on "References", then click on Manage Nuget Packages
// Select Package Manager Console
// Click on the prompt (where it says PM>), and type: Install-Package nupengl.core Then press enter.
// http://code.nabla.net/doc/OpenGL/api/OpenGL/man/
// 
// 23-May-22  M. Watler         Created.
// 27-May-22  M. Watler         Added graphical display.

#include <iostream>
#include "AnalogCircuit.h"

using namespace std;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	cout << "Enter the width of the window: ";
	cin >> windowWidth;
	cout << "Enter the height of the window: ";
	cin >> windowHeight;
	cout << "Enter the height scaling factor: ";
	cin >> scalingFactor;
	glutInitWindowSize(windowWidth, scalingFactor * windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("ANASIM");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, windowWidth, 0.0, scalingFactor * windowHeight);
	glutDisplayFunc(start);
	glutMainLoop();

	return 0;
}
