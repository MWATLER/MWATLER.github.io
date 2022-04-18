//GroceryStoreMain.cpp - main function for the grocerystore

//QUESTION 47: Has <iostream> been included in this file?
#include "GroceryStore.h"

using namespace std;

int main() {
	bool ret;
	const int NUM = 13;
	//QUESTION 48: Do I need to use NUM in the definition below?
	GroceryItem item[NUM] = {
		{"Apple", "fruit", 1000123, 1.99},
		{"Onion", "vegetable", 1000124, 0.99},
		{"Cheese", "dairy", 1000125, 6.99},
		{"Hot Dog", "anonymous", 1000126, 4.99},
		{"Orange", "fruit", 1000127, 2.99},
		{"Carrot", "vegetable", 1000128, 1.49},
		{"Milk", "dairy", 1000129, 8.99},
		{"Hot Dog Buns", "anonymous", 1000130, 3.99},
		{"Banana", "fruit", 1000131, 5.12},
		{"Broccoli", "vegetable", 1000132, 4.19},
		{"Ice Cream", "dairy", 1000133, 10.99},
		{"Chocolate Bar", "anonymous", 1000134, 1.49},
		{"Grapes", "fruit", 1000135, 10.49},
	};

	//QUESTION 49: In the below statement, which is the class and which is the object?
	//QUESTION 50: How many items are in our grocerystore?
	GroceryStore grocerystore(item, NUM);
	GroceryItem* itemPtr=nullptr;
	int numItems;
	//QUESTION 51: Does the function GetListOfItems() have the ability to change the value of numItems?
	itemPtr = grocerystore.GetListOfItems(numItems);
	if (itemPtr == nullptr)cout << "main: cannot get list of items." << endl;
	//QUESTION 52: If DisplayItems() were part of the class GroceryStore, how would you call DisplayItems()?
	else DisplayItems(itemPtr, numItems);

	GroceryItem newItem1 = { "Potato Chips", "anonymous", 1000136, 0.99 };
	GroceryItem newItem2 = { "Strawberries", "fruit", 1000137, 7.99 };
	GroceryItem newItem3 = { "Yoghurt", "dairy", 1000138, 11.39 };
	//QUESTION 53: How many of the above grocerystore items (newItem1, newItem2, newItem3) will actually be added to the grocerystore?
	ret = grocerystore.AddGroceryItem(newItem1);
	if (!ret)cout << "main: Cannot add " << newItem1.name << "." << endl;
	ret = grocerystore.AddGroceryItem(newItem2);
	if (!ret)cout << "main: Cannot add " << newItem2.name << "." << endl;
	ret = grocerystore.AddGroceryItem(newItem3);
	if (!ret)cout << "main: Cannot add " << newItem3.name << "." << endl;

	//QUESTION 54: How many items are in our grocerystore now?
	itemPtr = grocerystore.GetListOfItems(numItems);
	if (itemPtr == nullptr)cout << "main: cannot get list of items." << endl;
	else DisplayItems(itemPtr, numItems);

	//QUESTION 55: Will the below call to RemoveGroceryItem() succeed?
	ret = grocerystore.RemoveGroceryItem("Broccoli");
	if (!ret)cout << "main: Cannot remove Cauliflower" << endl;
	//QUESTION 56: How many items are in our grocerystore now?
	itemPtr = grocerystore.GetListOfItems(numItems);
	if (itemPtr == nullptr)cout << "main: cannot get list of items." << endl;
	else DisplayItems(itemPtr, numItems);

	Fruit* fruitPtr = nullptr;
	Vegetable* vegetablePtr = nullptr;
	Dairy* dairyPtr = nullptr;
	AnonymousItem* anonymousItemPtr = nullptr;
	int numFruits;
	int numVegetables;
	int numDairy;
	int numAnonymousItems;
	
	//QUESTION 57: What variable inside the class GroceryStore is fruitPtr actually pointing to?
	fruitPtr = grocerystore.GetListOfFruits(numFruits);
	if (fruitPtr == nullptr)cout << "main: cannot get list of fruits." << endl;
	else DisplayFruits(fruitPtr, numFruits);

	//QUESTION 58: What variable inside the class GroceryStore is vegetablePtr actually pointing to?
	vegetablePtr = grocerystore.GetListOfVegetables(numVegetables);
	if (vegetablePtr == nullptr)cout << "main: cannot get list of vegetables." << endl;
	else DisplayVegetables(vegetablePtr, numVegetables);

	//QUESTION 59: What variable inside the class GroceryStore is dairyPtr actually pointing to?
	dairyPtr = grocerystore.GetListOfDairy(numDairy);
	if (dairyPtr == nullptr)cout << "main: cannot get list of dairyes." << endl;
	else DisplayDairy(dairyPtr, numDairy);

	//QUESTION 60: What variable inside the class GroceryStore is anonymousItemPtr actually pointing to?
	anonymousItemPtr = grocerystore.GetListOfAnonymousItems(numAnonymousItems);
	if (anonymousItemPtr == nullptr)cout << "main: cannot get list of anonymous items." << endl;
	else DisplayAnonymousItems(anonymousItemPtr, numAnonymousItems);

	return 0;
}
