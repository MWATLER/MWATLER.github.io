//DatabaseMain.cpp - main function for the data base

#include "Database.h"

using namespace std;

int main() {
	std::shared_ptr<Database> dB = Database::getInstance();//getInstance creates an object of type Database
	                                                       //if that object does not already exist.
	                                                       //If that object already exists, getInstance will
	                                                       //return that object.
	string key;
	string value;
	Database::Err_Status status;

	key = "Naomi Osaka";
	status = dB->GetValue(key, value);
	if (status == Database::Err_Status::Err_Success) {
		cout << key << " earned " << value << endl;
	}
	else {
		cout << "Unable to retrieve earnings for " << key;
	}

	key = "Leylah Fernandez";
	value = "$786,772";
	status = dB->SetValue(key, value);
	if (status == Database::Err_Status::Err_Success) {
		cout << key << " earned " << value << endl;
	}
	else {
		cout << "Unable to set earnings for " << key;
	}

	std::shared_ptr<Database> dB2 = Database::getInstance();//dB2 and dB manage the same resource
	key = "Leylah Fernandez";
	status = dB->GetValue(key, value);
	if (status == Database::Err_Status::Err_Success) {
		cout << key << " earned " << value << endl;
	}
	else {
		cout << "Unable to retrieve earnings for " << key;
	}

	return 0;
}