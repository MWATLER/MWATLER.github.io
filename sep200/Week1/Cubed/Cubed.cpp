//Cubed.cpp - main function for the cube macro

#include <iostream>

using namespace std;

#define CUBE(X) X*X*X

int main() {
	std::cout << "The cube of 2 is " << CUBE(2) << std::endl;//2 * 2 * 2, correct
	std::cout << "The cube of 2+1 is " << CUBE(2 + 1) << std::endl;//2+1 * 2+1 * 2+1=7, wrong
	std::cout << "The cube of 3+1 is " << CUBE((3 + 1)) << std::endl;//(3+1) * (3+1) * (3+1)=64, correct

	for (int i = 0; i < 10; ++i) {
		std::cout << "The cube of "<<i<<" is " << CUBE(i) << std::endl;//i * i * i
	}
	return 0;
}
