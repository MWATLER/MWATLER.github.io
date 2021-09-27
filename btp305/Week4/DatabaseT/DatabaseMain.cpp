//DatabaseMain.cpp - main function for the data base

#include "Database.h"
#include "KeyValue.h"

using namespace std;

int main() {
	Database<string, double>* dB=new Database<string, double>("Data.txt");
	string key;
	double value;
	Database<string, double>::Err_Status status;

	key = "Osaka";
	status = dB->GetValue(key, value);
	if (status == Database<string, double>::Err_Status::Err_Success) {
		cout << key << " earned " << value << endl;
	}
	else {
		cout << "Unable to retrieve earnings for " << key;
	}

	key = "Fernandez";
	value = 786772.00;
	status = dB->SetValue(key, value);
	if (status == Database<string, double>::Err_Status::Err_Success) {
		cout << key << " earned " << value << endl;
	}
	else {
		cout << "Unable to set earnings for " << key;
	}

	delete dB;

	//Run again, based on rankings

	Database<string, int>* dB2 = new Database<string, int>("Data2.txt");
	string key2;
	int ranking;
	Database<string, int>::Err_Status status2;

	key2 = "Osaka";
	status2 = dB2->GetValue(key2, ranking);
	if (status2 == Database<string, int>::Err_Status::Err_Success) {
		cout << key2 << " has rank " << ranking << endl;
	}
	else {
		cout << "Unable to retrieve ranking for " << key2;
	}

	key2 = "Fernandez";
	ranking = 29;
	status2 = dB2->SetValue(key2, ranking);
	if (status2 == Database<string, int>::Err_Status::Err_Success) {
		cout << key2 << " has rank " << ranking << endl;
	}
	else {
		cout << "Unable to set ranking for " << key2;
	}

	KeyValue<string, int> keyValue1("Sabalenka", 2);
	KeyValue<string, int> keyValue2("Swiatek", 4);
	KeyValue<string, int> keyValue3("Kenin", 8);

	*dB2 += keyValue1;
	*dB2 += keyValue2;
	*dB2 += keyValue3;

	dB2->display(cout);

	delete dB2;

	return 0;
}