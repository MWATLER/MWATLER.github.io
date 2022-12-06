//Bakery.h - class declaration for a bakery

#include <iostream>

using namespace std;

const int MAX_ITEMS = 64;

struct Item {
	std::string name;
	double cost;
};

class Bakery {
	std::string name;
	std::string address;
	Item item[MAX_ITEMS];

	Bakery();
	Bakery(const std::string&, const std::string&, Item*, int);
	//Add in first open slot, where name is ""
	bool AddItem(const Item&);
	//Remove by setting name to ""
	bool RemoveItem(const std::string&) const;
	double GetValue(const std::string&) const;
	double GetValueBakery() const;
	void DisplayBakery() const;
};
