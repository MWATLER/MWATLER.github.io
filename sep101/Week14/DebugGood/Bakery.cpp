//Bakery.cpp - source code for the bakery

#include "Bakery.h"

Bakery::Bakery() {
	name = "";
	address = "";
	memset(item, 0, sizeof(item));//Bug 5. Buffer overrun
}

Bakery::Bakery(const std::string& name, const std::string& address, Item* item, int numItems) {
	this->name = name;//Bug 6. use the this pointer to differentiate between the name's
	this->address = address;
	for (int i = 0; i < numItems && i<MAX_ITEMS; ++i) {//Bug 7. Consider the case where numItems is larger than MAX_ITEMS
		this->item[i].name = item[i].name;
		this->item[i].cost = item[i].cost;
	}
}

bool Bakery::AddItem(const Item& item) {//Add in first open slot, where name is ""
	bool found = false;
	for (int i = 0; i < MAX_ITEMS && !found; ++i) {//Bug 8. Use the found flag to stop the loop once an open slot has been found
		if (this->item[i].name == "") {
			this->item[i].name = item.name;
			this->item[i].cost = item.cost;
			found = true;
		}
	}
	return found;
}

bool Bakery::RemoveItem(const std::string& name) {//Remove by setting name to ""
	bool found = false;
	for (int i = 0; i < MAX_ITEMS && !found; ++i) {
		if (this->item[i].name == name) {
			this->item[i].name = "";//Bug 9. name is not a pointer
			this->item[i].cost = 0.0;
			found = true;
		}
	}
	return found;
}

double Bakery::GetValue(const std::string& name) const {
	bool found = false;
	double value = 0.0;//Bug 10. Initialize value. If the item is not found, this function will return an undefined value
	for (int i = 0; i < MAX_ITEMS && !found; ++i) {
		if (this->item[i].name == name) {
			value = this->item[i].cost;
			found = true;
		}
	}
	return value;
}

double Bakery::GetValueBakery() const {
	double value = 0.0;//Bug 11. value is effectively a running total. Be sure to initialize it to 0
	for (int i = 0; i < MAX_ITEMS; ++i) {
		if (this->item[i].name != "") {
			value += this->item[i].cost;
		}
	}
	return value;
}

void Bakery::DisplayBakery() const {
	std::cout << std::endl;
	std::cout << name << " " << address << std::endl;
	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
	for (int i = 0; i < MAX_ITEMS; ++i) {
		if (item[i].name != "") {//Bug 12. Ignore empty slots in the array
			std::cout << item[i].name << " $" << item[i].cost << std::endl;
		}
	}
	std::cout << "Total Value: $" << GetValueBakery() << std::endl;
	std::cout << std::endl;
}
