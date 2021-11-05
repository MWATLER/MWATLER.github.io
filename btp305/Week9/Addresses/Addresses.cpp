//Addresses.cpp - Code to demonstrate printing addresses

#include <iostream>

using namespace std;

int main() {
	const char s[] = "A C string";

	std::cout << std::hex;
	for (int i = 0; s[i]; i++) {
		std::cout << (int*)&s[i] << " : " << s[i] << std::endl;
	}
	for (int i = 0; s[i]; i++) {
		std::cout << &s[i] << " : " << s[i] << std::endl;
	}

	return 0;
}