//GroceryStore.cpp - function definitions for the grocerystore

//QUESTION 7: Has <iostream> been included in this file?
#include "GroceryStore.h"

//QUESTION 8: Why wasn't "using namespace std;" put in the header file?
using namespace std;

GroceryStore::GroceryStore(GroceryItem item[], int num) {
	if (num > 0 && num<=MAX_ITEMS) {
		numItems = num;
		//QUESTION 9: Why do we need the "this" pointer here?
		this->item = new GroceryItem[numItems];
		for (int i = 0; i < numItems; ++i) {
			this->item[i].name = item[i].name;
			this->item[i].type = item[i].type;
			this->item[i].barcode = item[i].barcode;
			this->item[i].price = item[i].price;
		}
	}
	else {
		cout << "Error constructing the grocerystore. Aborting..." << endl;
		numItems = 0;
		this->item = nullptr;
	}
	numFruits = 0;
	numVegetables = 0;
	numDairy = 0;
	numAnonymousItems = 0;

	fruit = nullptr;
	vegetable = nullptr;
	dairy = nullptr;
	anonymousItem = nullptr;
}

bool GroceryStore::AddGroceryItem(GroceryItem& item) {
	bool ret = true;
	if (numItems < MAX_ITEMS) {
		//QUESTION 10: What is the purpose of newItem?
		//QUESTION 11: Why is newItem allocating "numItems+1" GroceryItem's of memory? Why not, for instance, "numItems+10"?
		//QUESTION 12: What changes would you have to make if newItem allocated "numItems+10" GroceryItem's of memory?
		//QUESTION 13: Does this code work if numItems is 0? If not, what changes are required?
		GroceryItem* newItem = new GroceryItem[numItems + 1];
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

bool GroceryStore::RemoveGroceryItem(std::string name) {
	bool found = false;
	for (int i = 0; i < numItems && !found; ++i) {
		//QUESTION 18: What are we searching for here?
		if (item[i].name == name) {
			found = true;
			//QUESTION 19: What is the purpose of newItem?
			//QUESTION 20: Why is newItem allocating "numItems-1" GroceryItem's of memory?
			//QUESTION 21: Does this code work if numItems is 1? If not, what changes are required?
			GroceryItem* newItem = new GroceryItem[numItems - 1];
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

bool GroceryStore::GenerateListOfFruits() {
	bool ret = true;
	//QUESTION 25: When is fruit equal to nullptr?
	//QUESTION 26: When is fruit not equal to nullptr?
	if (fruit != nullptr) delete[] fruit;
	//QUESTION 27: What does count represent?
	int count = 0;
	for (int i = 0; i < numItems; ++i) {
		if (item[i].type == "fruit") ++count;
	}

	if (count > 0) {
		//QUESTION 28: Is it possible to create a list of fruits without allocating more memory? If so, how?
		fruit = new Fruit[count];
		//QUESTION 29: Could we use count instead of numFruits here? How?
		numFruits = 0;
		//QUESTION 30: If we are creating a list of fruits, why do we use numItems here?
		for (int i = 0; i < numItems; ++i) {
			if (item[i].type == "fruit") {
				fruit[numFruits].name = item[i].name;
				fruit[numFruits].barcode = item[i].barcode;
				fruit[numFruits].price = item[i].price;
				++numFruits;
			}
		}
	}
	else {
		ret = false;
		cout << "Error: failed to generate a list of fruits." << endl;
	}
	return ret;
}

//QUESTION 31: This function is private. Who calls it?
//QUESTION 32: Is it a good idea to make this function public? Why?
bool GroceryStore::GenerateListOfVegetables() {
	bool ret = true;
	if (vegetable != nullptr) delete[] vegetable;
	int count = 0;
	for (int i = 0; i < numItems; ++i) {
		if (item[i].type == "vegetable") ++count;
	}

	if (count > 0) {
		//QUESTION 33: Is it possible to create a list of vegetables without allocating more memory? If so, how?
		vegetable = new Vegetable[count];
		numVegetables = 0;
		for (int i = 0; i < numItems; ++i) {
			if (item[i].type == "vegetable") {
				vegetable[numVegetables].name = item[i].name;
				vegetable[numVegetables].barcode = item[i].barcode;
				vegetable[numVegetables].price = item[i].price;
				++numVegetables;
			}
		}
	}
	else {
		ret = false;
		cout << "Error: failed to generate a list of vegetables." << endl;
	}
	return ret;
}

bool GroceryStore::GenerateListOfDairy() {
	bool ret = true;
	if (dairy != nullptr) delete[] dairy;
	int count = 0;
	for (int i = 0; i < numItems; ++i) {
		if (item[i].type == "dairy") ++count;
	}

	if (count > 0) {
		//QUESTION 34: Is it possible to create a list of dairyes without allocating more memory? If so, how?
		dairy = new Dairy[count];
		numDairy = 0;
		for (int i = 0; i < numItems; ++i) {
			if (item[i].type == "dairy") {
				dairy[numDairy].name = item[i].name;
				dairy[numDairy].barcode = item[i].barcode;
				dairy[numDairy].price = item[i].price;
				++numDairy;
			}
		}
	}
	else {
		ret = false;
		cout << "Error: failed to generate a list of dairyes." << endl;
	}
	return ret;
}

bool GroceryStore::GenerateListOfAnonymousItems() {
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
GroceryItem* GroceryStore::GetListOfItems(int& num) const {
	GroceryItem* itemPtr = nullptr;
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
Fruit* GroceryStore::GetListOfFruits(int& num) {
	Fruit* fruitPtr = nullptr;
	if (GenerateListOfFruits()) {
		fruitPtr = fruit;
		num = numFruits;
	}
	else {
		cout << "Error: list of fruits does not exist." << endl;
	}
	return fruitPtr;
}

Vegetable* GroceryStore::GetListOfVegetables(int& num) {
	Vegetable* vegetablePtr = nullptr;
	if (GenerateListOfVegetables()) {
		vegetablePtr = vegetable;
		num = numVegetables;
	}
	else {
		cout << "Error: list of vegetables does not exist." << endl;
	}
	return vegetablePtr;
}

Dairy* GroceryStore::GetListOfDairy(int& num) {
	Dairy* dairyPtr = nullptr;
	if (GenerateListOfDairy()) {
		dairyPtr = dairy;
		num = numDairy;
	}
	else {
		cout << "Error: list of dairyes does not exist." << endl;
	}
	return dairyPtr;
}

AnonymousItem* GroceryStore::GetListOfAnonymousItems(int& num) {
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

GroceryStore::~GroceryStore() {
	//QUESTION 39: Why do I test each of these to nullptr before deleting memory?
	//QUESTION 40: When is this destructor actually called?
	if (item != nullptr) {
		delete[] item;
		item = nullptr;
	}
	if (fruit != nullptr) {
		delete[] fruit;
		fruit = nullptr;
	}
	if (vegetable != nullptr) {
		delete[] vegetable;
		vegetable = nullptr;
	}
	if (dairy != nullptr) {
		delete[] dairy;
		dairy = nullptr;
	}
	if (anonymousItem != nullptr) {
		delete[] anonymousItem;
		anonymousItem = nullptr;
	}
}

//QUESTION 41: Can these display functions be called from GroceryStoreMain.cpp?
//QUESTION 42: How would you make these functions a part of class GroceryStore?
//QUESTION 43: Is it a good idea to make these functions a part of class GroceryStore?
void DisplayItems(GroceryItem* item, int num) {
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

void DisplayFruits(Fruit* item, int num) {
	cout << endl;
	cout << "LIST OF FRUITS:" << endl;
	for (int i = 0; i < num; ++i) {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << item[i].name << ", " << item[i].barcode << ", $" << item[i].price << "." << endl;
	}
	cout << endl;
}

void DisplayVegetables(Vegetable* item, int num) {
	cout << endl;
	cout << "LIST OF VEGETABLES:" << endl;
	for (int i = 0; i < num; ++i) {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << item[i].name << ", " << item[i].barcode << ", $" << item[i].price << "." << endl;
	}
	cout << endl;
}

void DisplayDairy(Dairy* item, int num) {
	cout << endl;
	cout << "LIST OF DAIRY PRODUCTS:" << endl;
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