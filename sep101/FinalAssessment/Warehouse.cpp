//Warehouse.cpp - function definitions for the warehouse

//QUESTION 7: Has <iostream> been included in this file?
#include "Warehouse.h"

//QUESTION 8: Why wasn't "using namespace std;" put in the header file?
using namespace std;

Warehouse::Warehouse(WarehouseItem item[], int num) {
	if (num > 0 && num<=MAX_ITEMS) {
		numItems = num;
		//QUESTION 9: Why do we need the "this" pointer here?
		this->item = new WarehouseItem[numItems];
		for (int i = 0; i < numItems; ++i) {
			this->item[i].name = item[i].name;
			this->item[i].type = item[i].type;
			this->item[i].barcode = item[i].barcode;
			this->item[i].price = item[i].price;
		}
	}
	else {
		cout << "Error constructing the warehouse. Aborting..." << endl;
		numItems = 0;
		this->item = nullptr;
	}
	numHammers = 0;
	numScrewdrivers = 0;
	numWrenches = 0;
	numAnonymousItems = 0;

	hammer = nullptr;
	screwdriver = nullptr;
	wrench = nullptr;
	anonymousItem = nullptr;
}

bool Warehouse::AddWarehouseItem(WarehouseItem& item) {
	bool ret = true;
	if (numItems < MAX_ITEMS) {
		//QUESTION 10: What is the purpose of newItem?
		//QUESTION 11: Why is newItem allocating "numItems+1" WarehouseItem's of memory? Why not, for instance, "numItems+10"?
		//QUESTION 12: What changes would you have to make if newItem allocated "numItems+10" WarehouseItem's of memory?
		//QUESTION 13: Does this code work if numItems is 1? If not, what changes are required?
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

		//QUESTION 14: Why am I deleting this->item?
		//QUESTION 15: Is it possible for this->item to equal nullptr in this part of the code?
		if (this->item != nullptr)delete[] this->item;
		//QUESTION 16: Why is this->item pointing to newItem?
		this->item = newItem;
		//QUESTION 17: Why am I incrementing numItems?
		++numItems;
	}
	else {
		cout << "Error: maximum items reached. Aborting..." << endl;
		ret = false;
	}
	return ret;
}

bool Warehouse::RemoveWarehouseItem(std::string name) {
	bool found = false;
	for (int i = 0; i < numItems && !found; ++i) {
		//QUESTION 18: What are we searching for here?
		if (item[i].name == name) {
			found = true;
			//QUESTION 19: What is the purpose of newItem?
			//QUESTION 20: Why is newItem allocating "numItems-1" WarehouseItem's of memory?
			//QUESTION 21: Does this code work if numItems is 1? If not, what changes are required?
			WarehouseItem* newItem = new WarehouseItem[numItems - 1];
			for (int j = 0; j < i; ++j) {
				newItem[j].name = item[j].name;
				newItem[j].type = item[j].type;
				newItem[j].barcode = item[j].barcode;
				newItem[j].price = item[j].price;
			}
			for (int j = i; j < numItems-1; ++j) {
				newItem[j].name = item[j + 1].name;
				newItem[j].type = item[j + 1].type;
				newItem[j].barcode = item[j + 1].barcode;
				newItem[j].price = item[j + 1].price;
			}
			//QUESTION 22: Is it possible for item to equal nullptr in this part of the code?
			if (item != nullptr)delete[] item;
			//QUESTION 23: Why is item pointing to newItem?
			item = newItem;
			//QUESTION 24: Why am I decrementing numItems?
			--numItems;
		}
	}

	if (!found) cout << "Error: item " << name << " not found. Could not remove it." << endl;
	return found;
}

bool Warehouse::GenerateListOfHammers() {
	bool ret = true;
	//QUESTION 25: When is hammer equal to nullptr?
	//QUESTION 26: When is hammer not equal to nullptr?
	if (hammer != nullptr) delete[] hammer;
	//QUESTION 27: What does count represent?
	int count = 0;
	for (int i = 0; i < numItems; ++i) {
		if (item[i].type == "hammer") ++count;
	}

	if (count > 0) {
		//QUESTION 28: Is it possible to create a list of hammers without allocating more memory? If so, how?
		hammer = new Hammer[count];
		//QUESTION 29: Could we use count instead of numHammers here? How?
		numHammers = 0;
		//QUESTION 30: If we are creating a list of hammers, why do we use numItems here?
		for (int i = 0; i < numItems; ++i) {
			if (item[i].type == "hammer") {
				hammer[numHammers].name = item[i].name;
				hammer[numHammers].barcode = item[i].barcode;
				hammer[numHammers].price = item[i].price;
				++numHammers;
			}
		}
	}
	else {
		ret = false;
		cout << "Error: failed to generate a list of hammers." << endl;
	}
	return ret;
}

//QUESTION 31: This function is private. Who calls it?
//QUESTION 32: Is it a good idea to make this function public? Why?
bool Warehouse::GenerateListOfScrewdrivers() {
	bool ret = true;
	if (screwdriver != nullptr) delete[] screwdriver;
	int count = 0;
	for (int i = 0; i < numItems; ++i) {
		if (item[i].type == "screwdriver") ++count;
	}

	if (count > 0) {
		//QUESTION 33: Is it possible to create a list of screwdrivers without allocating more memory? If so, how?
		screwdriver = new Screwdriver[count];
		numScrewdrivers = 0;
		for (int i = 0; i < numItems; ++i) {
			if (item[i].type == "screwdriver") {
				screwdriver[numScrewdrivers].name = item[i].name;
				screwdriver[numScrewdrivers].barcode = item[i].barcode;
				screwdriver[numScrewdrivers].price = item[i].price;
				++numScrewdrivers;
			}
		}
	}
	else {
		ret = false;
		cout << "Error: failed to generate a list of screwdrivers." << endl;
	}
	return ret;
}

bool Warehouse::GenerateListOfWrenches() {
	bool ret = true;
	if (wrench != nullptr) delete[] wrench;
	int count = 0;
	for (int i = 0; i < numItems; ++i) {
		if (item[i].type == "wrench") ++count;
	}

	if (count > 0) {
		//QUESTION 34: Is it possible to create a list of wrenches without allocating more memory? If so, how?
		wrench = new Wrench[count];
		numWrenches = 0;
		for (int i = 0; i < numItems; ++i) {
			if (item[i].type == "wrench") {
				wrench[numWrenches].name = item[i].name;
				wrench[numWrenches].barcode = item[i].barcode;
				wrench[numWrenches].price = item[i].price;
				++numWrenches;
			}
		}
	}
	else {
		ret = false;
		cout << "Error: failed to generate a list of wrenches." << endl;
	}
	return ret;
}

bool Warehouse::GenerateListOfAnonymousItems() {
	bool ret = true;
	if (anonymousItem != nullptr) delete[] anonymousItem;
	int count = 0;
	for (int i = 0; i < numItems; ++i) {
		if (item[i].type == "anonymous") ++count;
	}

	if (count > 0) {
		//QUESTION 35: Is it possible to create a list of anonymous items without allocating more memory? If so, how?
		anonymousItem = new AnonymousItem[count];
		numAnonymousItems = 0;
		for (int i = 0; i < numItems; ++i) {
			if (item[i].type == "anonymous") {
				anonymousItem[numAnonymousItems].name = item[i].name;
				anonymousItem[numAnonymousItems].barcode = item[i].barcode;
				anonymousItem[numAnonymousItems].price = item[i].price;
				++numAnonymousItems;
			}
		}
	}
	else {
		ret = false;
		cout << "Error: failed to generate a list of anonymous items." << endl;
	}
	return ret;
}

//QUESTION 36: Why is this getter function a const?
//QUESTION 37: Is num pass-by-address or pass-by-value?
WarehouseItem* Warehouse::GetListOfItems(int& num) const {
	WarehouseItem* itemPtr = nullptr;
	if (item != nullptr) {
		itemPtr = item;
		num = numItems;
	}
	else {
		cout << "Error: list of items does not exist." << endl;
	}
	return itemPtr;
}

//QUESTION 38: Why is this getter function not a const?
Hammer* Warehouse::GetListOfHammers(int& num) {
	Hammer* hammerPtr = nullptr;
	if (GenerateListOfHammers()) {
		hammerPtr = hammer;
		num = numHammers;
	}
	else {
		cout << "Error: list of hammers does not exist." << endl;
	}
	return hammerPtr;
}

Screwdriver* Warehouse::GetListOfScrewdrivers(int& num) {
	Screwdriver* screwdriverPtr = nullptr;
	if (GenerateListOfScrewdrivers()) {
		screwdriverPtr = screwdriver;
		num = numScrewdrivers;
	}
	else {
		cout << "Error: list of screwdrivers does not exist." << endl;
	}
	return screwdriverPtr;
}

Wrench* Warehouse::GetListOfWrenches(int& num) {
	Wrench* wrenchPtr = nullptr;
	if (GenerateListOfWrenches()) {
		wrenchPtr = wrench;
		num = numWrenches;
	}
	else {
		cout << "Error: list of wrenches does not exist." << endl;
	}
	return wrenchPtr;
}

AnonymousItem* Warehouse::GetListOfAnonymousItems(int& num) {
	AnonymousItem* anonymousItemPtr = nullptr;
	if (GenerateListOfAnonymousItems()) {
		anonymousItemPtr = anonymousItem;
		num = numAnonymousItems;
	}
	else {
		cout << "Error: list of anonymous items does not exist." << endl;
	}
	return anonymousItemPtr;
}

Warehouse::~Warehouse() {
	//QUESTION 39: Why do I test each of these to nullptr before deleting memory?
	//QUESTION 40: When is this destructor actually called?
	if (item != nullptr) {
		delete[] item;
		item = nullptr;
	}
	if (hammer != nullptr) {
		delete[] hammer;
		hammer = nullptr;
	}
	if (screwdriver != nullptr) {
		delete[] screwdriver;
		screwdriver = nullptr;
	}
	if (wrench != nullptr) {
		delete[] wrench;
		wrench = nullptr;
	}
	if (anonymousItem != nullptr) {
		delete[] anonymousItem;
		anonymousItem = nullptr;
	}
}

//QUESTION 41: Can these display functions be called from WarehouseMain.cpp?
//QUESTION 42: How would you make these functions a part of class Warehouse?
//QUESTION 43: Is it a good idea to make these functions a part of class Warehouse?
void DisplayItems(WarehouseItem* item, int num) {
	//QUESTION 44: What namespace is cout and endl a part of?
	cout << endl;
	cout << "LIST OF ITEMS:" << endl;
	for (int i = 0; i < num; ++i) {
		cout.setf(ios::fixed);
		cout.precision(2);
		//QUESTION 45: How would I reserve 10 spaces for name?
		//QUESTION 46: How would I fill empty spaces with the character '*'?
		cout << item[i].name << ", " << item[i].type << ", " << item[i].barcode << ", $" << item[i].price << "." << endl;
	}
	cout << endl;
}

void DisplayHammers(Hammer* item, int num) {
	cout << endl;
	cout << "LIST OF HAMMERS:" << endl;
	for (int i = 0; i < num; ++i) {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << item[i].name << ", " << item[i].barcode << ", $" << item[i].price << "." << endl;
	}
	cout << endl;
}

void DisplayScrewdrivers(Screwdriver* item, int num) {
	cout << endl;
	cout << "LIST OF SCREWDRIVERS:" << endl;
	for (int i = 0; i < num; ++i) {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << item[i].name << ", " << item[i].barcode << ", $" << item[i].price << "." << endl;
	}
	cout << endl;
}

void DisplayWrenches(Wrench* item, int num) {
	cout << endl;
	cout << "LIST OF WRENCHES:" << endl;
	for (int i = 0; i < num; ++i) {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << item[i].name << ", " << item[i].barcode << ", $" << item[i].price << "." << endl;
	}
	cout << endl;
}

void DisplayAnonymousItems(AnonymousItem* item, int num) {
	cout << endl;
	cout << "LIST OF ANONYMOUS ITEMS:" << endl;
	for (int i = 0; i < num; ++i) {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << item[i].name << ", " << item[i].barcode << ", $" << item[i].price << "." << endl;
	}
	cout << endl;
}