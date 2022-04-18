//GroceryStore.h - class declaration for a grocerystore

//QUESTION 1: Why do we need this header guard?
#ifndef _GROCERYSTORE_H_
#define _GROCERYSTORE_H_

#include <iostream>

struct GroceryItem {
	std::string name;
	std::string type;
	int barcode;
	double price;
};

struct Fruit {
	std::string name;
	int barcode;
	double price;
};

struct Vegetable {
	std::string name;
	int barcode;
	double price;
};

struct Dairy {
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

class GroceryStore {
	//QUESTION 2: I could have used arrays here. Why do I have pointers for GroceryItem, Fruit, Vegetable, Dairy, AnonymousItem?
	GroceryItem* item;
	Fruit* fruit;
	Vegetable* vegetable;
	Dairy* dairy;
	AnonymousItem* anonymousItem;
	const int MAX_ITEMS = 15;
	//QUESTION 3: Why do I have to keep track of the number of items, fruits, vegetables, dairy products and anonymous items?
	int numItems;
	int numFruits;
	int numVegetables;
	int numDairy;
	int numAnonymousItems;
	//QUESTION 4: Can these functions be called from GroceryStoreMain.cpp?
	bool GenerateListOfFruits();
	bool GenerateListOfVegetables();
	bool GenerateListOfDairy();
	bool GenerateListOfAnonymousItems();
public:
	//QUESTION 5: Can these functions be called from GroceryStoreMain.cpp?
	GroceryStore(GroceryItem _item[], int num);
	bool AddGroceryItem(GroceryItem& _item);
	bool RemoveGroceryItem(std::string name);
	GroceryItem* GetListOfItems(int& num) const;
	Fruit* GetListOfFruits(int& num);
	Vegetable* GetListOfVegetables(int& num);
	Dairy* GetListOfDairy(int& num);
	AnonymousItem* GetListOfAnonymousItems(int& num);
	//QUESTION 6: Why do we need a destructor?
	~GroceryStore();
};

void DisplayItems(GroceryItem* item, int num);
void DisplayFruits(Fruit* item, int num);
void DisplayDairy(Dairy* item, int num);
void DisplayVegetables(Vegetable* item, int num);
void DisplayAnonymousItems(AnonymousItem* item, int num);
#endif _GROCERYSTORE_H_
