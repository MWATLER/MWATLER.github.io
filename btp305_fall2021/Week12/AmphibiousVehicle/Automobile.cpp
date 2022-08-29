//Automobile.cpp - function definitions for an automobile

#include <iomanip>
#include "Automobile.h"

using namespace std;

Automobile::Automobile(std::string _name, double efficiency, double fuel) {
	name = _name;
	fuelEfficiency= efficiency;
	fuelInTank = fuel;
	cost = fuel * costPerLitre;
	cout << name << " automobile has added " << fuel << "L at a cost of $" << fuel * costPerLitre << "." << endl << endl;
}
Vehicle::Err_Status Automobile::Travel(double distance) {
	Vehicle::Err_Status status = Vehicle::Err_Status::Err_Success;
	double fuelConsumed = distance * fuelEfficiency / 100.0;;
	cout << fixed;
	cout << setprecision(2);
	if (fuelConsumed > fuelInTank) {
		status = Vehicle::Err_Status::Err_OutOfFuel;
		distance = fuelInTank * 100.0;//The actual distance travelled
		cout << name << " automobile is out of fuel. It actually travelled " << distance << "km at a cost of $" << fuelInTank * costPerLitre << "." << endl;
		fuelInTank = 0.0;
	}
	else {
		fuelInTank -= fuelConsumed;
		cout << name << " automobile has " << fuelInTank << "L of fuel left. It has travelled " << distance << "km at a cost of $" << fuelConsumed * costPerLitre << "." << endl;
	}

	return status;
}

Vehicle::Err_Status Automobile::AddFuel(double amount) {
	Vehicle::Err_Status status = Vehicle::Err_Status::Err_Success;

	cout << fixed;
	cout << setprecision(2);
	if ((fuelInTank + amount) > tankCapacity) {
		status = Vehicle::Err_Status::Err_FuelOverflow;
		amount = tankCapacity - fuelInTank;
		cost += amount * costPerLitre;
		fuelInTank = tankCapacity;
		cout << name << " automobile has encountered a fuel overflow. The amount added is actually " << amount << "L at a cost of $" << amount * costPerLitre << "." << endl;
	}
	else {
		cost += amount * costPerLitre;
		fuelInTank += amount;
		cout << name << " automobile has added " << amount << "L at a cost of $" << amount * costPerLitre << "." << endl;
	}

	return status;
}

double Automobile::GetFuel() const {
	return fuelInTank;
}

double Automobile::GetCost() const {
	return cost;
}