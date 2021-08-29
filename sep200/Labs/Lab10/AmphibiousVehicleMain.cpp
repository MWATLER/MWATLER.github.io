//AmphibiousVehicleMain.cpp - main program for travelling with an amphibious vehicle

#include <iomanip>
#include <iostream>
#include "AmphibiousVehicle.h"

using namespace std;

int main() {
	Vehicle::Err_Status status;
	//TODO: Add a smart pointer of type AmphibiousVehicle. 
	//      Call the amphibious vehicle object "ampVehicle" and name this amphibious vehicle as "Hydra Spyder"

	cout << "The automobile will travel 200km" << endl;
	ampVehicle->SetMode(AmphibiousVehicle::VEHICLE_AUTOMOBILE);
	status = ampVehicle->Travel(200.0);//travel 200km
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " automobile cannot travel 200km." << endl;
	cout << endl;
	
	cout << "The boat will travel 20km" << endl;
	ampVehicle->UnsetMode(AmphibiousVehicle::VEHICLE_AUTOMOBILE);
	ampVehicle->SetMode(AmphibiousVehicle::VEHICLE_BOAT);
	status = ampVehicle->Travel(20.0);//travel 20km
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " boat cannot travel 20km." << endl;
	cout << endl;

	cout << fixed;
	cout << setprecision(2);
	cout << ampVehicle->GetName() << " in total has spent $" << ampVehicle->GetCost() << " on fuel." << endl;
	cout << endl;

	//Add 30L of fuel to the boat and travel 200km
	cout << "Adding 30L of fuel to the boat" << endl;
	status = ampVehicle->AddFuel(30);
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " boat cannot add 30L of fuel." << endl;
	cout << endl;
	cout << "The boat will travel 200km" << endl;
	ampVehicle->Travel(200.0);
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " boat cannot travel 200km." << endl;
	cout << endl;

	//And 30L of fuel to the automobile and travel 300km
	ampVehicle->UnsetMode(AmphibiousVehicle::VEHICLE_BOAT);
	ampVehicle->SetMode(AmphibiousVehicle::VEHICLE_AUTOMOBILE);
	cout << "Adding 30L of fuel to the automobile" << endl;
	status = ampVehicle->AddFuel(30);
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " automobile cannot add 30L of fuel." << endl;
	cout << endl;
	cout << "The automobile will travel 300km" << endl;
	status = ampVehicle->Travel(300.0);
	if (status != Vehicle::Err_Status::Err_Success) cout << "The " << ampVehicle->GetName() << " automobile cannot travel 300km." << endl;
	cout << endl;

	cout << ampVehicle->GetName() << " in total has spent $" << ampVehicle->GetCost() << " on fuel." << endl;
	cout << endl;

	return 0;
}
