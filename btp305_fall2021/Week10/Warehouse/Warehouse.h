//Warehouse.h - structure and class declarations for a warehouse

#ifndef _WAREHOUSE_H_
#define _WAREHOUSE_H_

#include <iostream>
#include <vector>

struct WarehouseItem {//dynamically allocated resource under a unique_ptr
	std::string name;
	int barcode;
	double price;
	WarehouseItem(std::string _name, int _barcode, double _price) {
		name = _name;
		barcode = _barcode;
		price = _price;
	}
	~WarehouseItem() {
		std::cout << "~WarehouseItem: " << name << std::endl;
	}
};

struct Hammer {
	std::string name;//Hammer1
	int barcode;
};

struct Screwdriver {
	std::string name;
	int barcode;
};

struct Wrench {
	std::string name;
	int barcode;
};

struct Barcode {
	int barcode;
	double price;
};

class Warehouse {
	std::string name;
	//The merged list
	std::vector<WarehouseItem> itemList;

	//A list of products
	std::vector<Hammer> hammerList;
	std::vector<Screwdriver> screwdriverList;
	std::vector<Wrench> wrenchList;
	
	//A list of barcodes
	std::vector<Barcode> barcodeList;
public:
	Warehouse(std::string);
	bool StockHammers(Hammer* hammer, int len);
	bool StockScrewdrivers(Screwdriver* screwdriver, int len);
	bool StockWrenches(Wrench* wrench, int len);
	bool SetBarcodes(Barcode* barcode, int len);
	void MergeProducts();
	void PrintWarehouseItems() const;
	~Warehouse();
};


#endif _WAREHOUSE_H_
