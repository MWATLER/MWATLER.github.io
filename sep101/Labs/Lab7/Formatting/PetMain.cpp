//PetMain.cpp - main function for pets

#include <iomanip>//setw() setprecision()
#include "PetInfo.h"//PetInfo.h includes iostream

using namespace std;//use all libraries inside the package std

int main() {
	const int NUM = 3;
	PetInfo pets[NUM];
	bool ret;
	int retVal = 0;

	ret = pets[0].SetName("Snoopy");//****Snoopy
	if (ret) ret = pets[0].SetType("cat");
	if (ret) ret = pets[0].SetAge(13);
	if (ret) ret = pets[1].SetName("Sheba");//*****Sheba
	if (ret) ret = pets[1].SetType("dog");
	if (ret) ret = pets[1].SetAge(7);
	if (ret) ret = pets[2].SetName("Caesar");//****Caesar
	if (ret) ret = pets[2].SetType("rabbit");
	if (ret) ret = pets[2].SetAge(2);

	//the following two lines are equivalent
	printf("Hello World\n");//C version of printing to a screen
	cout << "Hello World" << endl;//C++ version of printing to a screen

	//the following two lines are equivalent
	printf("%s is %d years old\n", pets[0].GetName().c_str(), pets[0].GetAge());//C
	cout << pets[0].GetName() << " is " << pets[0].GetAge() << " years old" << endl;//C++

	if (ret) {
		for (int i = 0; i < NUM; ++i) {
//			cout.width(10);//best to put these inside the stream itself
			cout.setf(ios::right);//right justified
			cout << setw(10) << setfill('.') << pets[i].GetName() << " is a " << pets[i].GetType() << " and is " << pets[i].GetAge() << " years old." << endl;
		}
	}
	int runningTotal = 0.0;
	for (int i = 0; i < NUM; ++i) {
		runningTotal += pets[i].GetAge();
	}
	double average = (double)runningTotal / NUM;
	cout.setf(ios::fixed);//with the field set to fixed, precision will determine the number of numbers after the decimal place
	cout.precision(3);//to 3 decimal places
	cout << "The average age of these pets is " << average << " years old." << endl;

	if (!ret) retVal = -1;
	return retVal;
}