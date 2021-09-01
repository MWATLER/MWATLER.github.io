//Personnel.cpp - function definitions for the Personnel base class

#include <string>
#include "Personnel.h"

using namespace std;

Personnel::Personnel(string _name, Personnel::Role _role, string _address, int number) {
	name = _name;
	role = _role;
	address = _address;
	SenecaNumber = number;
	string make;
	int year;
	int currentYear;
	int numCars;
	cout << name << ", enter the number of cars: ";
	cin >> numCars;
	try {
		if (numCars < 0) throw "Invalid number of cars";
		for (int i = 0; i < numCars; ++i) {
			// discards the input buffer 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << i + 1 << ". make: ";
			getline(cin, make);
			cout << i + 1 << ". year: ";
			cin >> year;
			cout << i + 1 << ". the current year: ";
			cin >> currentYear;
			if (currentYear < year) throw "Invalid year";
			Vehicle vehicle(make, year, currentYear);
			vehicles.push_back(vehicle);
		}
		cout << endl;
	}
	catch (const char* msg) {
		cout << msg << endl;
		numCars = 0;
	}
}

string Personnel::GetInfo() const {
	string persType="";
	if (role == Personnel::Role::Faculty) persType = "Faculty";
	else if (role == Personnel::Role::Student) persType = "Student";

	string info = name + ", " + persType + ", " + address + ", " + to_string(SenecaNumber) + ".\n";
	if (vehicles.size() > 0) {
		info += name + " has the following cars: \n";
		for (auto& it : vehicles) {
			info += it.GetMake() + ", " + to_string(it.GetAge()) + " years old.\n";
		}
	}
	return info;
}

string Personnel::GetName() const {
	return name;
}

double Personnel::GetSalary() const {
	return 0.0;//implemented in a child class
}

double Personnel::GetAverage() const {
	return 0.0;//implemented in a child class
}

vector<int> Personnel::GetMarks() const {
	vector<int> marks;//implemented in a child class
	marks.push_back(0);
	return marks;
}

vector<Vehicle> Personnel::GetCars() const {
	return vehicles;
}