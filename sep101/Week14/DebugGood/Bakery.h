//Bakery.h - class declaration for a bakery

#ifndef _BAKERY_H_//Bug 1. Add header guards
#define _BAKERY_H_
#include <iostream>

//using namespace std;//Bug 2. "using namespace std" should not appear in a header file

const int MAX_ITEMS = 64;

struct Item {
	std::string name;
	double cost;
};

class Bakery {
	std::string name;
	std::string address;
	Item item[MAX_ITEMS];
public://Bug 3. The below must be public
	Bakery();
	Bakery(const std::string&, const std::string&, Item*, int);
	//Add in first open slot, where name is ""
	bool AddItem(const Item&);
	//Remove by setting name to ""
	bool RemoveItem(const std::string&);//Bug 4. remove const
	double GetValue(const std::string&) const;
	double GetValueBakery() const;
	void DisplayBakery() const;
};
#endif// _BAKERY_H_