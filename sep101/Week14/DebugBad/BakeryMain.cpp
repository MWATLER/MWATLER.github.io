//BakeryMain.cpp - main function for the bakery

#include "Bakery.h"

int main() {
	const int NUM = 5;
	Item items[NUM-1] = {
		{"Cookie", 1.99 },
		{"Cupcake", 2.99 },
		{"Muffin", 3.49 },
		{"Tea Biscuit", 2.49 },
		{"Donut", 1.49 },
	};
	std::string name = "Petrani's Bakery";
	std::string address = "299 Mill Road, Etobicoke, Ontario";
	Bakery* bakery = new Bakery(name, address, &items, NUM);

	double value = bakery->GetValue("Tea Biscuit");
	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
	std::cout << "The value of a tea biscuit is $" << value << std::endl;
	bakery->DisplayBakery();

	Item *item = { "Cake", 12.99 };
	bakery->AddItem(item);
	bakery->RemoveItem("Muffin");
	bakery->DisplayBakery();

	return 0;
}