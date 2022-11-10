// SmartPtr.cpp - Smart Pointer for title

#include <iostream>
#include "Title.h"
#include "SmartPtr.h"

void display(const char* s) {
	SmartPtr<Title> t(new Title(s));//p points to this new Title object
	t->display();
}

int main() {
	const char* s[] = { "Mr.", "Ms.", "", "Dr." };

	for (auto x : s) {
		try {
			display(x);
		}
		catch (const char* msg) {
			std::cerr << msg << std::endl;
		}
	}
}