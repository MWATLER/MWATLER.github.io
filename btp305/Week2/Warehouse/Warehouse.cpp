//Warehouse.cpp - function definitions for the warehouse

#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse(std::string name, std::string address, WarehouseItem item[], int num) {
	this->name = name;
	this->address = address;
	if (num > 0 && num <= MAX_ITEMS) {
		numItems = num;
		this->item = new WarehouseItem[numItems];
		for (int i = 0; i < numItems; ++i) {
			this->item[i].name = item[i].name;
			this->item[i].type = item[i].type;
			this->item[i].barcode = item[i].barcode;
			this->item[i].price = item[i].price;
		}
	}
	else {
		numItems = 0;
		this->item = nullptr;
	}
}

Warehouse::Warehouse(const Warehouse& warehouse) {//copy constructor
	*this = warehouse;//will invoke the copy assignment
}

Warehouse::Warehouse(Warehouse&& warehouse) noexcept {//move constructor
	*this = std::move(warehouse);//will invoke the move assignment
}

Warehouse& Warehouse::operator=(const Warehouse& warehouse) {//copy assignment
	if (this != &warehouse) {//don't copy to yourself
		//shallow copies
		name = warehouse.name;
		address = warehouse.address;
		numItems = warehouse.numItems;
		//deep copy any resources
		//remove existing resourse
		delete[] item;
		if (numItems > 0) {
			//allocate for a new resource and copy data over
			item = new WarehouseItem[numItems];
			for (int i = 0; i < numItems; ++i) {
				item[i].name = warehouse.item[i].name;
				item[i].type = warehouse.item[i].type;
				item[i].barcode = warehouse.item[i].barcode;
				item[i].price = warehouse.item[i].price;
			}
		}
		else {
			item = nullptr;
		}
	}

	return *this;
}

Warehouse& Warehouse::operator=(Warehouse&& warehouse) noexcept {//move assignment
	if (this != &warehouse) {//don't move to yourself
		//shallow copies
		name = warehouse.name;
		address = warehouse.address;
		numItems = warehouse.numItems;
		//remove existing resource
		delete[] item;
		//take control of the resource on the rhs
		item = warehouse.item;

		//Put the rhs into an empty state
		warehouse.name = "";
		warehouse.address = "";
		warehouse.numItems = 0;
		warehouse.item = nullptr;
	}

	return *this;
}

Warehouse& Warehouse::operator+=(WarehouseItem& item) {
	if (numItems < MAX_ITEMS) {
		WarehouseItem* newItem = new WarehouseItem[numItems + 1];
		for (int i = 0; i < numItems; ++i) {
			newItem[i].name = this->item[i].name;
			newItem[i].type = this->item[i].type;
			newItem[i].barcode = this->item[i].barcode;
			newItem[i].price = this->item[i].price;
		}
		newItem[numItems].name = item.name;
		newItem[numItems].type = item.type;
		newItem[numItems].barcode = item.barcode;
		newItem[numItems].price = item.price;

//		if (this->item != nullptr)delete[] this->item;//the comparison is not necessary
		delete[] this->item;
		this->item = newItem;
		++numItems;
	}
	else {
		cout << "Error: maximum items reached. Aborting..." << endl;
	}
	return *this;
}

Warehouse& Warehouse::operator-=(std::string name) {
	bool found = false;
	for (int i = 0; i < numItems && !found; ++i) {
		if (item[i].name == name) {
			found = true;
			WarehouseItem* newItem = new WarehouseItem[numItems - 1];
			for (int j = 0; j < i; ++j) {//'i' is 3
				newItem[j].name = item[j].name;
				newItem[j].type = item[j].type;
				newItem[j].barcode = item[j].barcode;
				newItem[j].price = item[j].price;
			}
			for (int j = i; j < numItems - 1; ++j) {//skips over item 3
				newItem[j].name = item[j + 1].name;
				newItem[j].type = item[j + 1].type;
				newItem[j].barcode = item[j + 1].barcode;
				newItem[j].price = item[j + 1].price;
			}
//			if (item != nullptr)delete[] item;//the comparison is not necessary
			delete[] item;
			item = newItem;
			--numItems;
		}
	}

	if (!found) cout << "Error: item " << name << " not found. Could not remove it." << endl;
	return *this;
}

Warehouse::~Warehouse() {
	if (item != nullptr) {
		delete[] item;
		item = nullptr;
	}
}

void Warehouse::DisplayItems(ostream& os) const {
	os << endl;
	os << name << " " << address << endl;
	os << "LIST OF ITEMS:" << endl;
	for (int i = 0; i < numItems; ++i) {
		os.setf(ios::fixed);
		os.precision(2);
		os << item[i].name << ", " << item[i].type << ", " << item[i].barcode << ", $" << item[i].price << "." << endl;
	}
	os << endl;
}

std::ostream& operator<<(std::ostream& os, const Warehouse& warehouse) {
	warehouse.DisplayItems(os);
	return os;
}
