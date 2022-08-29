//Boat.cpp - function definitions for an boat

#include <iomanip>
#include "Boat.h"

using namespace std;

Boat::Boat(std::string _name, double efficiency, double fuel) {
	name = _name;
	litresPerHour = efficiency;
	fuelInTank = fuel;
	cost = fuel * costPerLitre;
	cout << name << " boat has added " << fuel << "L at a cost of $" << fuel * costPerLitre << "." << endl << endl;
}
Vehicle::Err_Status Boat::Travel(double distance) {
	Vehicle::Err_Status status = Vehicle::Err_Status::Err_Success;
	double time = distance / speed;
	double fuelConsumed = time * litresPerHour;
	cout << fixed;
	cout << setprecision(2);
	if (fuelConsumed > fuelInTank) {
		status = Vehicle::Err_Status::Err_OutOfFuel;
		time = fuelInTank / litresPerHour;//The actual time travelled
		distance = speed * time;//The actual distance travelled
		cout << name << " boat is out of fuel. It actually travelled " << distance << "km at a cost of $" << fuelInTank * costPerLitre << "." << endl;
		fuelInTank = 0.0;
	}
	else {
		fuelInTank -= fuelConsumed;
		cout << name << " boat has " << fuelInTank << "L of fuel left. It has travelled " << distance << "km at a cost of $" << fuelConsumed * costPerLitre << "." << endl;
	}

	return status;
}

Vehicle::Err_Status Boat::AddFuel(double amount) {
	Vehicle::Err_Status status = Vehicle::Err_Status::Err_Success;

	if ((fuelInTank + amount) > tankCapacity) {
		status = Vehicle::Err_Status::Err_FuelOverflow;
		amount = tankCapacity - fuelInTank;
		cost += amount * costPerLitre;
		fuelInTank = tankCapacity;
		cout << name << " boat has encountered a fuel overflow. The amount added is actually " << amount << "L at a cost of $" << amount * costPerLitre << "." << endl;
	}
	else {
		cost += amount * costPerLitre;
		fuelInTank += amount;
		cout << name << " boat has added " << amount << "L at a cost of $" << amount * costPerLitre << "." << endl;
	}

	return status;
}

double Boat::GetFuel() const {
	return fuelInTank;
}

double Boat::GetCost() const {
	return cost;
}
