//HouseMain.cpp - main program for houses

#include <iostream>
#include "House.h"

using namespace std;

int main() {
	House house1("Lionel Messi", "34 Cedarwood Road", 5, 2.5, 2500000.00);
	House house2("Neymar da Silva Santos Junior", "12 Broadway Street", 7, 4, 5600000.00);
	House house3(house1);//Copy constructor
	House house4;
	house4 = house2;//Copy assignment

	house1.DisplayInfo();
	house2.DisplayInfo();
	house3.DisplayInfo();
	house4.DisplayInfo();

	cout << "----------------------------" << endl << endl;

	House house5(std::move(house1));//Move constructor
	House house6("Luke Shaw", "33 Picadilly Avenue", 6, 4.5, 4400000);
	house6 = std::move(house2);//Move assignment

	house1.DisplayInfo();
	house2.DisplayInfo();
	house3.DisplayInfo();
	house4.DisplayInfo();
	house5.DisplayInfo();
	house6.DisplayInfo();

	cout << "----------------------------" << endl << endl;

	if (house3 == house4) cout << "Houses 3 and 4 are the same" << endl;
	if (house3 == house5) cout << "Houses 3 and 5 are the same" << endl;
	if (house3 == house6) cout << "Houses 3 and 6 are the same" << endl;
	if (house4 == house5) cout << "Houses 4 and 5 are the same" << endl;
	if (house4 == house6) cout << "Houses 4 and 6 are the same" << endl;
	if (house5 == house6) cout << "Houses 5 and 6 are the same" << endl;

	cout << endl << "----------------------------" << endl << endl;

	house3 += 1000000;
	house4 += 1000000;
	house3.DisplayInfo();
	house4.DisplayInfo();
	house5.DisplayInfo();
	house6.DisplayInfo();

	cout << "----------------------------" << endl << endl;

	house3 >> house5;
	house4 >> house6;
	house3.DisplayInfo();
	house4.DisplayInfo();
	house5.DisplayInfo();
	house6.DisplayInfo();

	return 0;
}