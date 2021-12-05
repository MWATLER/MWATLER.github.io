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
		{Cargo("Cherries", 11000.00, CargoType::Food)},
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

	std::string name;
	std::cout << std::endl << "Enter the name of cargo to display: ";
	std::cin >> name;
	Cargo* aCargo = (*freighter)[name];
	if (aCargo == nullptr)
		std::cout << "Could not retrieve cargo named " << name << std::endl;
	else {
		std::cout << "The cargo retrieved is:" << std::endl;
		byEverything(std::cout, *aCargo);
	}
	delete freighter;
}


void byCargoType(std::ostream& os, const Cargo& cargo) {
	os << "\nBy Cargo Type ";
	switch (cargo.GetType())
	{
	case CargoType::Car: os << "Car \n"; break;
	case CargoType::Food: os << "Food \n"; break;
	case CargoType::Commodity: os << "Commodity \n"; break;
	}
}

void byValue(std::ostream& os, const Cargo& cargo)
{
	os << "\nBy Cargo Value ";
	os << cargo.GetValue() << std::endl;
}

void byEverything(std::ostream& os, const Cargo& cargo)
{
	os << std::endl << cargo.GetName() << " $" << cargo.GetValue() << " ";
	switch (cargo.GetType())
	{
	case CargoType::Car: os << "Car \n"; break;
	case CargoType::Food: os << "Food \n"; break;
	case CargoType::Commodity: os << "Commodity \n"; break;
	}
}
