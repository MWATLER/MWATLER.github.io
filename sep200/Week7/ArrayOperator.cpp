//ArrayOperator.cpp

#include <iostream>
#include "College.h"

using namespace std;

int main(void) {
	Student studentInfo[] = { {"Eric Cartman", 2, "Marketing"},
		{"Stan Marsh", 3, "Geology"},
		{"Kyle Broslovski", 1, "Law"},
		{"Kenny McCormick", 3, "Engineering Technology"} };
	string address = "1750 Finch Ave E, North York, ON M2J 5G3";

	College college(studentInfo, address);

	for (int i = 0; i < NUM; ++i) {
		cout << college[i].name << " is in year " << college[i].year << " of " << college[i].program << "." << endl;
	}

	return 0;
}