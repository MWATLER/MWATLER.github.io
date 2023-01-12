//DietClientMain.cpp - main program for the dietician's client

#include <iostream>
#include "DietClient.h"

using namespace std;

int main(void) {
	DietClient client1("Eric Cartman", 1.8, 140);
	DietClient client2("Stan Marsh", 1.78, 90);
	DietClient client3("Kyle Broslovski", 1.75, 80);

	if (client1) {//if(boolean expression), such as if(a==b)
		cout << "client1 exists" << endl;
	}
	client1 += 4000;
	client2 += 2000;
	client3 += 1000;
	client1 += "Apple";
	client2 += "Yoghurt";
	client3 += "Banana";
	++client1;//prefix increment
	client2++;//postfix increment
	++client3;

	client1.PrintReport() << endl << endl;
	client2.PrintReport() << endl << endl;
	client3.PrintReport();
}
