//DatabaseMain.cpp - main function for the data base

#include "Database.h"

using namespace std;

int main() {
	std::shared_ptr<Database> dB = Database::getInstance();//copy assignment, copy constructor??
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
	//dB and dB2 will manage the same resource - the one and only instance of Database
	std::shared_ptr<Database> dB2 = Database::getInstance();
	key = "Leylah Fernandez";
	status = dB->GetValue(key, value);
	if (status == Database::Err_Status::Err_Success) {
		cout << key << " earned " << value << endl;
	}
	else {
		cout << "Unable to retrieve earnings for " << key;
	}

	//no clean up necessary 

	return 0;
}