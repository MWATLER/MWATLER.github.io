//stringMain.cpp - source code that demonstrates the bsa::string class

#include <iostream>//for cout
#include "string.h"//for bsa::string

using namespace bsa;

int main() {
	string string1("Hello World");//bsa::string
	string string2;

	string2 = string1;//overloaded '=' operator
	std::cout << *string1 << " " << *string2 << std::endl;
	string string3 = "Goodbye World";//promotes "Goodbye World" to a string
	std::cout << *string3 << std::endl;
	string3 += string2;//"Hello World" += "Goodbye World" -> "Hello WorldGoodbye World"
	std::cout << *string3 << std::endl;
	string3 += "Hello";//promotes "Hello" to a string, string3 becomes "Hello WorldGoodbye WorldHello"

	return 0;
}