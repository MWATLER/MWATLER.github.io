//Warehouse.h - class declaration for a warehouse

//QUESTION 1: Why do we need this header guard?
#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include <iostream>

struct WarehouseItem {
	std::string name;
	std::string type;
	int barcode;
	double price;
};

struct Hammer {
	std::string name;
	int barcode;
	double price;
};

struct Screwdriver {
	std::string name;
	int barcode;
	double price;
};

struct Wrench {
	std::string name;
	int barcode;
	double price;
};

struct AnonymousItem {
	std::string name;
	std::string type;
	int barcode;
	double price;
};

class Warehouse {
	//QUESTION 2: I could have used arrays here. Why do I have pointers for WarehouseItem, Hammer, Screwdriver, Wrench, AnonymousItem?
	WarehouseItem* item;
	Hammer* hammer;
	Screwdriver* screwdriver;
	Wrench* wrench;
	AnonymousItem* anonymousItem;
	const int MAX_ITEMS = 15;
	//QUESTION 3: Why do I have to keep track of the number of items, hammers, screwdrivers, wrenches and anonymous items?
	int numItems;
	int numHammers;
	int numScrewdrivers;
	int numWrenches;
	int numAnonymousItems;
	//QUESTION 4: Can these functions be called from WarehouseMain.cpp?
	bool GenerateListOfHammers();
	bool GenerateListOfScrewdrivers();
	bool GenerateListOfWrenches();
	bool GenerateListOfAnonymousItems();
public:
	//QUESTION 5: Can these functions be called from WarehouseMain.cpp?
	Warehouse(WarehouseItem _item[], int num);
	bool AddWarehouseItem(WarehouseItem& _item);
	bool RemoveWarehouseItem(std::string name);
	WarehouseItem* GetListOfItems(int& num) const;
	Hammer* GetListOfHammers(int& num);
	Screwdriver* GetListOfScrewdrivers(int& num);
	Wrench* GetListOfWrenches(int& num);
	AnonymousItem* GetListOfAnonymousItems(int& num);
	//QUESTION 6: Why do we need a destructor?
	~Warehouse();
};

void DisplayItems(WarehouseItem* item, int num);
void DisplayHammers(Hammer* item, int num);
void DisplayWrenches(Wrench* item, int num);
void DisplayScrewdrivers(Screwdriver* item, int num);
void DisplayAnonymousItems(AnonymousItem* item, int num);
#endif _WAREHOUSE_H_
