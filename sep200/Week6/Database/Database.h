//Database.h - class declaration for the database

#include <iostream>

struct Database1 {
	std::string name;//used as the key in the database
	int age;
	double salary;
};

struct Database2 {
	std::string name;//used as the key in the database
	std::string position;
	int yearsWithCompany;
};

template<class T, int N>
class Database {
public:
	T data[N];
	bool FindDataElement(std::string key, T& element) {
		bool found = false;
		int index;
		for (index = 0; index < N && !found; ++index) {
			if (data[index].name == key) {
				element = data[index];
				found = true;
			}
		}
		return found;
	}
	int GetNumberOfDataElements() {
		return N;
	}
	bool GetDataElement(int _index, T& element) {
		bool found = false;
		if (_index<N) {
			element = data[_index];
			found = true;
		}
		return found;
	}
	bool GetLastDataElement(T& element) {
		return GetDataElement(N - 1, element);
	}
	bool GetFirstDataElement(T& element) {
		return GetDataElement(0, element);
	}
};