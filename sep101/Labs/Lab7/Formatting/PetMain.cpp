//PetMain.cpp - main function for pets

#include <iomanip>//setw() setprecision()
#include "PetInfo.h"//PetInfo.h includes iostream

using namespace std;

int main() {
	const int NUM = 3;
	PetInfo pets[NUM];
	bool ret;
	int retVal = 0;

	ret = pets[0].SetName("Snoopy");
	if (ret) ret = pets[0].SetType("cat");
	if (ret) ret = pets[0].SetAge(13);
	if (ret) ret = pets[1].SetName("Sheba");
	if (ret) ret = pets[1].SetType("dog");
	if (ret) ret = pets[1].SetAge(7);
	if (ret) ret = pets[2].SetName("Caesar");
	if (ret) ret = pets[2].SetType("rabbit");
	if (ret) ret = pets[2].SetAge(2);

	if (ret) {
		for (int i = 0; i < NUM; ++i) {
//			cout.width(10);//best to put these inside the stream itself
			cout.setf(ios::right);
			cout << setw(10) << setfill('.') << pets[i].GetName() << " is a " << setw(6) << setfill('*') << pets[i].GetType() << " and is " << setw(2) << pets[i].GetAge() << " years old." << endl;
		}
	}

	if (!ret) retVal = -1;
	return retVal;
}