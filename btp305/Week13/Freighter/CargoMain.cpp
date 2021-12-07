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
	//Freighter* freighter = new Freighter();
	std::unique_ptr<Freighter> freighter(new Freighter());
	for (const auto& i : cargo) {
		try {
			*freighter += i;
		}
		catch (const std::string& error) {
			std::cerr << error << "\n";
		}
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

	std::cout << std::endl << "BUILD FREIGHTER 2:" << std::endl;
	Freighter freighter2;
	for (const auto& i : cargo) {
		try {
			freighter2 += i;
		}
		catch (const std::string& error) {
			std::cerr << error << "\n";
		}
	}

	std::cout << std::endl << "TEST THE COPY CONSTRUCTOR AND COPY ASSIGNMENT:" << std::endl;
	Freighter freighter3(freighter2);//test the copy constructor
	Freighter freighter4 = freighter2;//test the copy assignment
	std::cout << "The original freighter" << std::endl;
	freighter2.display(byEverything);
	std::cout << "The copied freighter (copy constructor)" << std::endl;
	freighter3.display(byEverything);
	std::cout << "The copied freighter (copy assignment)" << std::endl;
	freighter4.display(byEverything);

	std::cout << std::endl << "TEST THE MOVE CONSTRUCTOR AND MOVE ASSIGNMENT:" << std::endl;
	Freighter freighter5 = std::move(freighter3);
	Freighter freighter6(std::move(freighter4));
	std::cout << "The new freighter (move constructor)" << std::endl;
	freighter5.display(byEverything);
	std::cout << "Another new freighter (move assignment)" << std::endl;
	freighter6.display(byEverything);
	std::cout << "The moved freighters" << std::endl;
	freighter3.display(byEverything);
	freighter4.display(byEverything);



	//  delete freighter;
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
