//Warehouse.h - class declaration for a warehouse

#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include <iostream>

struct WarehouseItem {
	std::string name;
	std::string type;
	int barcode;
	double price;
};

class Warehouse {
	std::string name = "";
	std::string address = "";
	WarehouseItem* item = nullptr;
	int numItems = 0;
	const int MAX_ITEMS = 15;
public:
	Warehouse() {}//default constructor
	Warehouse(std::string name, std::string address, WarehouseItem _item[], int num);

	Warehouse(const Warehouse& warehouse);//copy constructor
	Warehouse(Warehouse&& warehouse) noexcept ;//move constructor
	Warehouse& operator=(const Warehouse& warehouse);//copy assignment
	Warehouse& operator=(Warehouse&& warehouse) noexcept;//move assignment

	void SetAddress(std::string newAddr) { address = newAddr; }//change the address
	Warehouse& operator+=(WarehouseItem& _item);//add an item
	Warehouse& operator-=(std::string name);//remove an item
	void DisplayItems(std::ostream& os) const;//display all items
	~Warehouse();
};

std::ostream& operator<<(std::ostream& os, const Warehouse& warehouse);

#endif _WAREHOUSE_H_
