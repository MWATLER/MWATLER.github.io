//WarehouseMain.cpp

#include "Warehouse.h"

using namespace std;

int main() {
	const int NUM1 = 3;
	const int NUM2 = 9;
	Hammer hammer[NUM1] = {
		{"Hammer1", 100000},
		{"Hammer2", 100010},
		{"Hammer3", 100020},
	};
	Screwdriver screwdriver[NUM1] = {
		{"Screwdriver1", 100001},
		{"Screwdriver2", 100011},
		{"Screwdriver3", 100021},
	};
	Wrench wrench[NUM1] = {
		{"Wrench1", 100002},
		{"Wrench2", 100012},
		{"Wrench3", 100022},
	};
	Barcode barcode[NUM2] = {
		{100000, 18.99},
		{100001, 9.99},
		{100002, 21.99},
		{100010, 19.99},
		{100011, 7.99},
		{100012, 20.99},
		{100020, 17.99},
		{100021, 8.99},
		{100022, 22.99},
	};

	Warehouse warehouse("Terminal1");
	warehouse.StockHammers(hammer, NUM1);
	warehouse.StockScrewdrivers(screwdriver, NUM1);
	warehouse.StockWrenches(wrench, NUM1);
	warehouse.SetBarcodes(barcode, NUM2);

	warehouse.MergeProducts();
	warehouse.PrintWarehouseItems();

	return 0;
}