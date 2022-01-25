//DatabaseMain.cpp - main function for the data base

#include "Database.h"

using namespace std;

int main() {
	Database* dB = Database::getInstance();
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

	Database* dB2 = Database::getInstance();
	key = "Leylah Fernandez";
	status = dB2->GetValue(key, value);
	if (status == Database::Err_Status::Err_Success) {
		cout << key << " earned " << value << endl;
	}
	else {
		cout << "Unable to retrieve earnings for " << key;
	}

	if (Database::isInstance()) delete dB;
	if (Database::isInstance()) delete dB2;
	return 0;
}