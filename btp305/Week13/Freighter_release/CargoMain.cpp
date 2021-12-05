//CargoMain.cpp - main function for cargo

#include "Cargo.h"
#include "Freighter.h"

void byCargoType(std::ostream& os, const Cargo& cargo);
void byValue(std::ostream& os, const Cargo& cargo);
void byEverything(std::ostream& os, const Cargo& cargo);

int main() {
	Cargo cargo[]{
		{Cargo("Toyota", 29000.00, CargoType::Car)},
		{Cargo("Honda", 31000.00, CargoType::Car)},
		{Cargo("Chocolates", 9000.00, CargoType::Food)},
		{Cargo("Butane", 12000.00, CargoType::Commodity)},
		{Cargo("Huawei", 8000.00, CargoType::Electronics)},
		{Cargo("Cherries", 11000.00, CargoType::Food)},
		{Cargo("Samsung", 8000.00, CargoType::Electronics)},
		{Cargo("Mazda", 30000.00, CargoType::Car)},
		{Cargo("Charcoal", 8000.00, CargoType::Commodity)}
	};
	Freighter* freighter = new Freighter();
	for (const auto& i : cargo) {
		*freighter += i;
	}
	freighter->display(byCargoType);
	freighter->display(byValue);
	freighter->display(byEverything);

	double value;
	std::cout << std::endl << "Enter a value. The first cargo item greater than this value will be returned: ";
	std::cin >> value;
	Cargo* aCargo = (*freighter)[value];
	if (aCargo == nullptr)
		std::cout << "Could not retrieve any cargo greater than $" << value << std::endl;
	else {
		std::cout << "The cargo retrieved is:" << std::endl;
		byEverything(std::cout, *aCargo);
	}

	int index;
	std::cout << std::endl << "Enter an index. The cargo item with this index will be returned: ";
	std::cin >> index;
	Cargo* bCargo = (*freighter)[index];
	if (bCargo == nullptr)
		std::cout << "Could not retrieve any cargo with index " << index << std::endl;
	else {
		std::cout << "The cargo retrieved is:" << std::endl;
		byEverything(std::cout, *bCargo);
	}

	*freighter -= "Mazda";
	*freighter -= "Chips";
	freighter->display(byEverything);

	delete freighter;
}


void byCargoType(std::ostream& os, const Cargo& cargo) {
	os << "\nBy Cargo Type ";
	switch (cargo.GetType())
	{
	case CargoType::Car: os << "Car \n"; break;
	case CargoType::Food: os << "Food \n"; break;
	case CargoType::Commodity: os << "Commodity \n"; break;
	case CargoType::Electronics: os << "Electronics \n"; break;
	}
}

void byValue(std::ostream& os, const Cargo& cargo)
{
	os.setf(std::ios::fixed);
	os.precision(2);
	os << "\nBy Cargo Value $";
	os << cargo.GetValue() << std::endl;
}

void byEverything(std::ostream& os, const Cargo& cargo)
{
	os.setf(std::ios::fixed);
	os.precision(2);
	os << std::endl << cargo.GetName() << " $" << cargo.GetValue() << " ";
	switch (cargo.GetType())
	{
	case CargoType::Car: os << "Car \n"; break;
	case CargoType::Food: os << "Food \n"; break;
	case CargoType::Commodity: os << "Commodity \n"; break;
	case CargoType::Electronics: os << "Electronics \n"; break;
	}
}
