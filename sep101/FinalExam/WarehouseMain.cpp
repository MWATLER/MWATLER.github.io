//WarehouseMain.cpp - main function for the warehouse

//QUESTION 47: Has <iostream> been included in this file?
#include "Warehouse.h"

using namespace std;

int main() {
	bool ret;
	const int NUM = 13;
	//QUESTION 48: Do I need to use NUM in the definition below?
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

	//QUESTION 49: In the below statement, which is the class and which is the object?
	//QUESTION 50: How many items are in our warehouse?
	Warehouse warehouse(item, NUM);
	WarehouseItem* itemPtr=nullptr;
	int numItems;
	//QUESTION 51: Does the function GetListOfItems() have the ability to change the value of numItems?
	itemPtr = warehouse.GetListOfItems(numItems);
	if (itemPtr == nullptr)cout << "main: cannot get list of items." << endl;
	//QUESTION 52: If DisplayItems() were part of the class Warehouse, how would you call DisplayItems()?
	else DisplayItems(itemPtr, numItems);

	WarehouseItem newItem1 = { "Shovel", "anonymous", 1000136, 17.99 };
	WarehouseItem newItem2 = { "Hammer5", "hammer", 1000137, 13.99 };
	WarehouseItem newItem3 = { "Wrench4", "wrench", 1000138, 12.39 };
	//QUESTION 53: How many of the above warehouse items (newItem1, newItem2, newItem3) will actually be added to the warehouse?
	ret = warehouse.AddWarehouseItem(newItem1);
	if (!ret)cout << "main: Cannot add " << newItem1.name << "." << endl;
	ret = warehouse.AddWarehouseItem(newItem2);
	if (!ret)cout << "main: Cannot add " << newItem2.name << "." << endl;
	ret = warehouse.AddWarehouseItem(newItem3);
	if (!ret)cout << "main: Cannot add " << newItem3.name << "." << endl;

	//QUESTION 54: How many items are in our warehouse now?
	itemPtr = warehouse.GetListOfItems(numItems);
	if (itemPtr == nullptr)cout << "main: cannot get list of items." << endl;
	else DisplayItems(itemPtr, numItems);

	//QUESTION 55: Will the below call to RemoveWarehouseItem() succeed?
	ret = warehouse.RemoveWarehouseItem("Screwdriver3");
	if (!ret)cout << "main: Cannot remove Screwdriver3" << endl;
	//QUESTION 56: How many items are in our warehouse now?
	itemPtr = warehouse.GetListOfItems(numItems);
	if (itemPtr == nullptr)cout << "main: cannot get list of items." << endl;
	else DisplayItems(itemPtr, numItems);

	Hammer* hammerPtr = nullptr;
	Screwdriver* screwdriverPtr = nullptr;
	Wrench* wrenchPtr = nullptr;
	AnonymousItem* anonymousItemPtr = nullptr;
	int numHammers;
	int numScrewdrivers;
	int numWrenches;
	int numAnonymousItems;
	
	//QUESTION 57: What variable inside the class Warehouse is hammerPtr actually pointing to?
	hammerPtr = warehouse.GetListOfHammers(numHammers);
	if (hammerPtr == nullptr)cout << "main: cannot get list of hammers." << endl;
	else DisplayHammers(hammerPtr, numHammers);

	//QUESTION 58: What variable inside the class Warehouse is screwdriverPtr actually pointing to?
	screwdriverPtr = warehouse.GetListOfScrewdrivers(numScrewdrivers);
	if (screwdriverPtr == nullptr)cout << "main: cannot get list of screwdrivers." << endl;
	else DisplayScrewdrivers(screwdriverPtr, numScrewdrivers);

	//QUESTION 59: What variable inside the class Warehouse is wrenchPtr actually pointing to?
	wrenchPtr = warehouse.GetListOfWrenches(numWrenches);
	if (wrenchPtr == nullptr)cout << "main: cannot get list of wrenches." << endl;
	else DisplayWrenches(wrenchPtr, numWrenches);

	//QUESTION 60: What variable inside the class Warehouse is anonymousItemPtr actually pointing to?
	anonymousItemPtr = warehouse.GetListOfAnonymousItems(numAnonymousItems);
	if (anonymousItemPtr == nullptr)cout << "main: cannot get list of anonymous items." << endl;
	else DisplayAnonymousItems(anonymousItemPtr, numAnonymousItems);

	return 0;
}
