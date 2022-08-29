//Cubed.h - header file for square

#ifndef _CUBED_H_
#define _CUBED_H_

#include <iostream>

template<typename T>
T cubed(T number) {
	static int numCalled = 0;
	++numCalled;
	std::cout << "cubed has been called " << numCalled << " times." << std::endl;
	return number * number * number;
}

#endif _CUBED_H_