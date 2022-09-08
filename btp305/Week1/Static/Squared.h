//Squared.h - header file for square

#ifndef _SQUARED_H_
#define _SQUARED_H_

#include <iostream>

template<typename T>
T squared(T number) {
	static int numCalled = 0;
	++numCalled;
	std::cout << "squared has been called " << numCalled << " times." << std::endl;
	return number * number;
}

#endif _SQUARED_H_
