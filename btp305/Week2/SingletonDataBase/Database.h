//Database.h - class declaration for a database

#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <iostream>

#define DEBUG
#define Log(msg) std::cout << __func__ << ":" << __LINE__ << ":" << msg << std::endl;

class Database {
	int numEntries;
	const int MAX_ENTRIES = 20;
	std::string *key;
	std::string *value;
	std::string dbFileName;

	static Database* instance;//we only want one object or instance of class Database
	Database();//Private constructors to prevent instancing
public:
	enum Err_Status {
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory
	};
	static Database* getInstance();//returns instance if an object exists, otherwise creates the object
	static bool isInstance();
	Err_Status GetValue(std::string key, std::string& value) const;
	Err_Status SetValue(std::string key, std::string value);
	int GetNumEntries() const;
	~Database();
};

#endif// _DATABASE_H_
