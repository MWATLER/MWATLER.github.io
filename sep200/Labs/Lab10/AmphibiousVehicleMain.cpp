//AmphibiousVehicleMain.cpp - main program for travelling with an amphibious vehicle

#include <iomanip>
#include <iostream>
#include "AmphibiousVehicle.h"

using namespace std;

int main() {
	//TODO: Create a smart pointer to an AmphibiousVehicle object. Call the vehicle "Hydra Spyder"

	cout << "The automobile will travel 200km" << endl;
	ampVehicle->SetMode(AmphibiousVehicle::VEHICLE_AUTOMOBILE);
	ampVehicle->Travel(200.0);//travel 200km
	cout << endl;
	
	cout << "The boat will travel 20km" << endl;
	ampVehicle->UnsetMode(AmphibiousVehicle::VEHICLE_AUTOMOBILE);
	ampVehicle->SetMode(AmphibiousVehicle::VEHICLE_BOAT);
	ampVehicle->Travel(20.0);//travel 20km
	cout << endl;

	cout << fixed;
	cout << setprecision(2);
	cout << ampVehicle->GetName() << " in total has spent $" << ampVehicle->GetCost() << " on fuel." << endl;
	cout << endl;

	//Add 30L of fuel to the boat and travel 200km
	cout << "Adding 30L of fuel to the boat" << endl;
	ampVehicle->AddFuel(30);
	cout << endl;
	cout << "The boat will travel 200km" << endl;
	ampVehicle->Travel(200.0);
	cout << endl;

	//And 30L of fuel to the automobile and travel 300km
	ampVehicle->UnsetMode(AmphibiousVehicle::VEHICLE_BOAT);
	ampVehicle->SetMode(AmphibiousVehicle::VEHICLE_AUTOMOBILE);
	cout << "Adding 30L of fuel to the automobile" << endl;
	ampVehicle->AddFuel(30);
	cout << endl;
	cout << "The automobile will travel 300km" << endl;
	ampVehicle->Travel(300.0);
	cout << endl;

	cout << ampVehicle->GetName() << " in total has spent $" << ampVehicle->GetCost() << " on fuel." << endl;
	cout << endl;

	return 0;
}
