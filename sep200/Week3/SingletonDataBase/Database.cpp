//Database.cpp - function definitions for the database

#include <fstream>
#include <string>
#include "Database.h"

using namespace std;

Database* Database::instance = nullptr;

Database::Database() {
	dbFileName = "Data.txt";
	ifstream myfile(dbFileName);
	if (myfile.is_open()) {
		key = new std::string[MAX_ENTRIES];
		value = new std::string[MAX_ENTRIES];
		numEntries = 0;
		while (!myfile.eof() && numEntries < MAX_ENTRIES) {
			getline(myfile, key[numEntries]);
			getline(myfile, value[numEntries]);
#ifdef DEBUG
			Log(key[numEntries]);
			Log(value[numEntries]);
			cout << endl;
#endif
			++numEntries;
		}
		myfile.close();
	}
}

Database* Database::getInstance() {
	if (instance == nullptr) {
		instance = new Database();
	}
	return instance;
}

bool Database::isInstance() {
	bool ret = true;
	if (instance == nullptr) ret = false;
	return ret;
}



Database::Err_Status Database::GetValue(std::string key, std::string& value) {
	Err_Status status = Err_Status::Err_NotFound;
	for (int i = 0; i < numEntries && status == Err_Status::Err_NotFound; ++i) {
		if (key == this->key[i]) {
			value = this->value[i];
			status = Err_Status::Err_Success;
		}
	}
	return status;
}

Database::Err_Status Database::SetValue(std::string key, std::string value) {
	Err_Status status = Err_Status::Err_OutOfMemory;
	if (numEntries < MAX_ENTRIES) {
		status = Err_Status::Err_Success;
		this->key[numEntries] = key;
		this->value[numEntries] = value;
		++numEntries;
	}
	return status;
}

int Database::GetNumEntries() {
	return numEntries;
}

Database::~Database() {
	ofstream myfile(dbFileName);
	for (int i = 0; i < numEntries; ++i) {
		myfile << key[i] << endl;
		myfile << value[i];
		if (i < (numEntries - 1)) myfile << endl;
	}
	myfile.close();
	if (key) delete[] key;
	if (value) delete[] value;
	Database::instance = nullptr;
}