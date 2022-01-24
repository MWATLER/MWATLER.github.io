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

	static Database* instance;
	Database();//Private constructors to prevent instancing
public:
	enum class Err_Status {
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory
	};
	static Database* getInstance();
	static bool isInstance();
	Err_Status GetValue(std::string key, std::string& value);
	Err_Status SetValue(std::string key, std::string value);
	int GetNumEntries();
	~Database();
};

#endif// _DATABASE_H_
