//stringMain.cpp - source code that demonstrates the bsa::string class

#include <iostream>//for cout
#include "string.h"//for bsa::string

using namespace bsa;

int main() {
	string string1("Hello World");
	string string2;

	string2 = string1;
	std::cout << *string1 << " " << *string2 << std::endl;
	string string3 = "Goodbye World";//converts "Goodbye World" into a string
	std::cout << *string3 << std::endl;
	string3 += string2;
	std::cout << *string3 << std::endl;
	string3 += "Hello";//converts "Hello" into a string

	return 0;
}