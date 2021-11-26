//AmphibiousVehicle.cpp - function definitions for an amphibious vehicle

#include "AmphibiousVehicle.h"

using namespace std;

AmphibiousVehicle::AmphibiousVehicle(std::string _name) : Boat(_name, 20.0, 150.0), Automobile(_name, 10.0, 50.0){
	name = _name;
	mode = VEHICLE_NONE;
}

Vehicle::Err_Status AmphibiousVehicle::Travel(double distance) {
	Vehicle::Err_Status status = Vehicle::Err_Status::Err_Success;

	if (mode == VEHICLE_BOAT) {
		status = Boat::Travel(distance);
	}
	else if (mode == VEHICLE_AUTOMOBILE) {
		status = Automobile::Travel(distance);
	}

	return status;
}

Vehicle::Err_Status AmphibiousVehicle::AddFuel(double amount) {
	Vehicle::Err_Status status = Vehicle::Err_Status::Err_Success;

	if (mode == VEHICLE_BOAT) {
		status = Boat::AddFuel(amount);
	}
	else if (mode == VEHICLE_AUTOMOBILE) {
		status = Automobile::AddFuel(amount);
	}

	return status;
}

string AmphibiousVehicle::GetName() const {
	return name;
}

double AmphibiousVehicle::GetFuel() const {
	double fuel = 0.0;
	if (mode == VEHICLE_BOAT || mode == VEHICLE_AUTOMOBILE) {
		fuel = Boat::GetFuel() + Automobile::GetFuel();
	}
	return fuel;
}

double AmphibiousVehicle::GetCost() const {
	double cost = 0.0;
	if (mode == VEHICLE_BOAT || mode==VEHICLE_AUTOMOBILE) {
		cost = Boat::GetCost() + Automobile::GetCost();
	}
	return cost;
}

Vehicle::Err_Status AmphibiousVehicle::UnsetMode(unsigned short _mode) {
	Vehicle::Err_Status status = Vehicle::Err_Status::Err_Success;

	if (_mode<VEHICLE_NONE || mode >VEHICLE_BOAT) {
		status = Vehicle::Err_Status::Err_IncorrectMode;
	}
	else {
		mode = mode & ~_mode;
	}

	return status;
}

Vehicle::Err_Status AmphibiousVehicle::SetMode(unsigned short _mode) {
	Vehicle::Err_Status status = Vehicle::Err_Status::Err_Success;

	if (_mode<VEHICLE_NONE || mode >VEHICLE_BOAT) {
		status = Vehicle::Err_Status::Err_IncorrectMode;
	}
	else {
		mode = mode | _mode;
	}

	return status;
}

