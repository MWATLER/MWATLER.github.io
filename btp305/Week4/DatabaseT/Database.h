//Database.h - class declaration for a database

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <fstream>
#include <iomanip>
#include <iostream>
#include "KeyValue.h"

#define DEBUG
#define Log(msg) std::cout << __func__ << ":" << __LINE__ << ":" << msg << std::endl;

template <class K, class V>
class Database {
	const int MAX_ENTRIES = 20;
	int numEntries{ 0 };
	K* key{ nullptr };
	V* value{ nullptr };
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
			key = new K[MAX_ENTRIES];
			value = new V[MAX_ENTRIES];
			numEntries = 0;
			while (!myfile.eof() && numEntries < MAX_ENTRIES) {
				myfile >> key[numEntries];
				myfile >> value[numEntries];
#ifdef DEBUG
				Log(key[numEntries]);
				Log(value[numEntries]);
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
			if (key == this->key[i]) {
				value = this->value[i];
				status = Err_Status::Err_Success;
			}
		}
		return status;
	}
	Err_Status SetValue(K key, V value) {
		Err_Status status = Err_Status::Err_OutOfMemory;
		if (numEntries < MAX_ENTRIES) {
			status = Err_Status::Err_Success;
			this->key[numEntries] = key;
			this->value[numEntries] = value;
			++numEntries;
		}
		return status;
	}
	int GetNumEntries() const {
		return numEntries;
	}
	Database<K, V>& operator+=(const KeyValue<K, V>& kv) {
		if (numEntries < MAX_ENTRIES) {
			key[numEntries] = kv.Key();
			value[numEntries] = kv.Value();
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
			os << key[i] << ": " << value[i] << std::endl;
		}
	}
	~Database() {
		std::ofstream myfile(dbFileName);
		for (int i = 0; i < numEntries; ++i) {
			myfile << key[i] << std::endl;
			myfile << value[i];
			if (i < (numEntries - 1)) myfile << std::endl;
		}
		myfile.close();
		if (key) delete[] key;
		if (value) delete[] value;
	}
};

#endif// _DATABASE_H_