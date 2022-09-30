//Database.h - class declaration for a database

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <fstream>
#include <iomanip>
#include <iostream>
#include "KeyValue.h"

#define DEBUG
#define Log(msg) std::cout << __func__ << ":" << __LINE__ << ":" << msg << std::endl;
const int MAX_ENTRIES = 20;

template <class K, class V>
class Database {
	int numEntries{ 0 };
	KeyValue<K, V>* keyValue[MAX_ENTRIES]{ };
	std::string dbFileName{ "" };
public:
	enum class Err_Status {
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory
	};
	Database(std::string filename) {
		dbFileName = filename;
		std::ifstream myfile(dbFileName);
		if (myfile.is_open()) {
			K key;
			V value;
			numEntries = 0;
			while (!myfile.eof() && numEntries < MAX_ENTRIES) {
				myfile >> key;
				myfile >> value;
				keyValue[numEntries] = new KeyValue<K, V>(key, value);
#ifdef DEBUG
				Log(keyValue[numEntries]->Key());
				Log(keyValue[numEntries]->Value());
				std::cout << std::endl;
#endif
				++numEntries;
			}
			myfile.close();
		}
	}
	Err_Status GetValue(K key, V& value) {
		Err_Status status = Err_Status::Err_NotFound;
		for (int i = 0; i < numEntries && status == Err_Status::Err_NotFound; ++i) {
			if (key == keyValue[i]->Key()) {
				value = keyValue[i]->Value();
				status = Err_Status::Err_Success;
			}
		}
		return status;
	}
	Err_Status SetValue(K key, V value) {
		Err_Status status = Err_Status::Err_OutOfMemory;
		bool found = false;
		for (int i = 0; i < numEntries && !found; ++i) {//does it exist?
			if (keyValue[i]->Key() == key) {
				found = true;
				keyValue[i]->SetValue(value);
				status = Err_Status::Err_Success;
			}
		}
		if (!found && numEntries < MAX_ENTRIES) {//add the key-value pair
			keyValue[numEntries] = new KeyValue<K, V>(key, value);//this presents a problem. 
			//In aggregation, objects are created outside of the class. 
			//How do we know which to delete in the destructor?
			status = Err_Status::Err_Success;
			++numEntries;
		}
		return status;
	}
	int GetNumEntries() {
		return numEntries;
	}
	Database<K, V>& operator+=(KeyValue<K, V>& kv) {
		if (numEntries < MAX_ENTRIES) {
			keyValue[numEntries] = &kv;
			++numEntries;
		}
		else {
			std::cout << "Error: No more space in the database." << std::endl;
		}
		return *this;
	}
	void display(std::ostream& os) const {
		os << std::endl << std::endl;
		os << std::left;
		for (int i = 0; i < numEntries; ++i) {
			os << std::setw(12);
			os << keyValue[i]->Key() << ": " << keyValue[i]->Value() << std::endl;
		}
	}
	~Database() {
		std::ofstream myfile(dbFileName);
		for (int i = 0; i < numEntries; ++i) {
			myfile << keyValue[i]->Key() << std::endl;
			myfile << keyValue[i]->Value();
			if (i < (numEntries - 1)) myfile << std::endl;
		}
		myfile.close();
		//PROBLEM: Which KeyValue objects were created within dataBase
//		if (keyValue) delete[] keyValue;
	}
};

#endif// _DATABASE_H_