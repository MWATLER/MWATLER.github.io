//Warehouse.cpp - function definitions for a warehouse

#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse(std::string name) {
	this->name = name;
}

bool Warehouse::StockHammers(Hammer* hammer, int len) {
	bool retVal = true;
	if (len < 0) retVal = false;
	for (int i = 0; i < len; ++i) {
		hammerList.push_back(hammer[i]);
	}
	return retVal;
}

bool Warehouse::StockScrewdrivers(Screwdriver* screwdriver, int len) {
	bool retVal = true;
	if (len < 0) retVal = false;
	for (int i = 0; i < len; ++i) {
		screwdriverList.push_back(screwdriver[i]);
	}
	return retVal;
}

bool Warehouse::StockWrenches(Wrench* wrench, int len) {
	bool retVal = true;
	if (len < 0) retVal = false;
	for (int i = 0; i < len; ++i) {
		wrenchList.push_back(wrench[i]);
	}
	return retVal;
}

bool Warehouse::SetBarcodes(Barcode* barcode, int len) {
	bool retVal = true;
	if (len < 0) retVal = false;
	for (int i = 0; i < len; ++i) {
		barcodeList.push_back(barcode[i]);
	}
	return retVal;
}

void Warehouse::MergeProducts() {
	bool found = false;
	//Go through the hammers
	for (size_t i = 0; i < hammerList.size(); ++i) {
		found = false;
		for (size_t j = 0; j < barcodeList.size() && !found; ++j) {
			if (hammerList[i].barcode == barcodeList[j].barcode) {
				found = true;
				unique_ptr<WarehouseItem> wItem(new WarehouseItem(hammerList[i].name, hammerList[i].barcode, barcodeList[j].price));
				itemList.push_back(std::move(*wItem));
			}
		}
	}

	//Go through the screwdrivers
	for (size_t i = 0; i < screwdriverList.size(); ++i) {
		found = false;
		for (size_t j = 0; j < barcodeList.size() && !found; ++j) {
			if (screwdriverList[i].barcode == barcodeList[j].barcode) {
				found = true;
				unique_ptr<WarehouseItem> wItem(new WarehouseItem(screwdriverList[i].name, screwdriverList[i].barcode, barcodeList[j].price));
				itemList.push_back(std::move(*wItem));
			}
		}
	}

	//Go through the wrenches
	for (size_t i = 0; i < wrenchList.size(); ++i) {
		found = false;
		for (size_t j = 0; j < barcodeList.size() && !found; ++j) {
			if (wrenchList[i].barcode == barcodeList[j].barcode) {
				found = true;
				unique_ptr<WarehouseItem> wItem(new WarehouseItem(wrenchList[i].name, wrenchList[i].barcode, barcodeList[j].price));
				itemList.push_back(std::move(*wItem));
			}
		}
	}
}

void Warehouse::PrintWarehouseItems() const {
	cout << endl;
	cout << "WAREHOUSE ITEMS:" << endl;
	for (int i = 0; i < itemList.size(); ++i) {
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << itemList[i].name << ", " << itemList[i].barcode << ", $" << itemList[i].price << endl;
	}
	cout << endl;
}


Warehouse::~Warehouse() {
	cout << "~Warehouse:" << endl;
}
