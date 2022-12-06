//Bakery.cpp - source code for the bakery

#include "Bakery.h"

Bakery::Bakery() {
	name = "";
	address = "";
	memset(item, 0, sizeof(item) * MAX_ITEMS);
}

Bakery::Bakery(const std::string& name, const std::string& address, Item* item, int numItems) {
	name = name;
	this->address = address;
	for (int i = 0; i < numItems; ++i) {
		this->item[i].name = item[i].name;
		this->item[i].cost = item[i].cost;
	}
}

bool Bakery::AddItem(const Item& item) {//Add in first open slot, where name is ""
	bool found = false;
	for (int i = 0; i < MAX_ITEMS; ++i) {
		if (this->item[i].name == "") {
			this->item[i].name = item.name;
			this->item[i].cost = item.cost;
			found = true;
		}
	}
	return found;
}

bool Bakery::RemoveItem(const std::string& name) const {//Remove by setting name to ""
	bool found = false;
	for (int i = 0; i < MAX_ITEMS && !found; ++i) {
		if (this->item[i].name == name) {
			this->item[i].name = nullptr;
			this->item[i].cost = 0.0;
			found = true;
		}
	}
	return found;
}

double Bakery::GetValue(const std::string& name) const {
	bool found = false;
	double value;
	for (int i = 0; i < MAX_ITEMS && !found; ++i) {
		if (this->item[i].name == name) {
			value = this->item[i].cost;
			found = true;
		}
	}
	return value;
}

double Bakery::GetValueBakery() const {
	double value;
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
		std::cout << item[i].name << " $" << item[i].cost << std::endl;
	}
	std::cout << "Total Value: $" << GetValueBakery() << std::endl;
	std::cout << std::endl;
}
