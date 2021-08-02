//FrameText.cpp - main function for framing text

#include<iostream>
#include<fstream>
#include "Cars.h"
using namespace std;

int main(void) {
	CarName carname;

	carname.GetNumberOfEntries();
	carname.GetEntries();
	carname.DisplayEntries();

	return 0;
}