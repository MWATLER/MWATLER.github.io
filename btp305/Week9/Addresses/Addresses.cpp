//Addresses.cpp - Code to demonstrate printing addresses

#include <iostream>

using namespace std;

int main() {
	const char s[] = "A C string";

	std::cout << std::hex;
	for (int i = 0; s[i]; i++) {
		std::cout << (int*)&s[i] << " : " << s[i] << std::endl;//could also use (void*) for the address
	}
	for (int i = 0; s[i]; i++) {
		std::cout << &s[i] << " : " << &s[0] << std::endl;//s is the same as &s[0]
	}

	return 0;
}