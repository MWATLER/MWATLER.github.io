//WarehouseMain.cpp - main function for the warehouse

#include "Warehouse.h"

using namespace std;

int main() {
	const int NUM = 13;
	WarehouseItem item[NUM] = {
		{"Hammer1", "hammer", 1000123, 11.99},
		{"Screwdriver1", "screwdriver", 1000124, 8.99},
		{"Wrench1", "wrench", 1000125, 12.99},
		{"Extension Cord", "anonymous", 1000126, 6.99},
		{"Hammer2", "hammer", 1000127, 12.99},
		{"Screwdriver2", "screwdriver", 1000128, 10.99},
		{"Wrench2", "wrench", 1000129, 15.99},
		{"Stud Finder", "anonymous", 1000130, 26.99},
		{"Hammer3", "hammer", 1000131, 9.99},
		{"Screwdriver3", "screwdriver", 1000132, 7.99},
		{"Wrench3", "wrench", 1000133, 14.99},
		{"Plaster", "anonymous", 1000134, 4.99},
		{"Hammer4", "hammer", 1000135, 10.49},
	};

	Warehouse warehouse1("Home Depot", "2920 Argentia Road, Mississauga", item, NUM);
	cout << "Warehouse1: " << warehouse1;

	WarehouseItem newItem1 = { "Shovel", "anonymous", 1000136, 17.99 };
	WarehouseItem newItem2 = { "Hammer5", "hammer", 1000137, 13.99 };
	WarehouseItem newItem3 = { "Wrench4", "wrench", 1000138, 12.39 };
	warehouse1 += newItem1;
	warehouse1 += newItem2;
	warehouse1 += newItem3;
	cout << "Warehouse1: " << warehouse1;

 	warehouse1 -= "Screwdriver3";
	cout << "Warehouse1: " << warehouse1;

	//test the copy constructor
	Warehouse warehouse2(warehouse1);
	warehouse2.SetAddress("5975 Terry Fox Way, Mississauga");
	warehouse2 -= "Wrench3";//change something
	cout << "Warehouse2: " << warehouse2;
	//test the copy assignment
	Warehouse warehouse3;
	warehouse3 = warehouse2;
	warehouse3.SetAddress("3065 Mavis Rd, Mississauga");
	warehouse3 -= "Plaster";
	cout << "Warehouse3: " << warehouse3;

	//test the move constructor, move everything from warehouse1 to warehouse4
	Warehouse warehouse4(std::move(warehouse1));
	warehouse4.SetAddress("99 Cross Ave, Oakville");
	cout << "Warehouse1: " << warehouse1;
	cout << "Warehouse4: " << warehouse4;
	//test the move assignment, move everything from warehouse2 to warehouse5
	Warehouse warehouse5;
	warehouse5 = std::move(warehouse2);
	warehouse5.SetAddress("49 First Gulf Blvd, Brampton");
	cout << "Warehouse2: " << warehouse2;
	cout << "Warehouse5: " << warehouse5;

	return 0;
}
