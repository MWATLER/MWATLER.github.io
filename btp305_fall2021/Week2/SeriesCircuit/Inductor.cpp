//Inductor.cpp - function definitions for the inductor
//
// 09-Jul-21  M. Watler         Created.
#include <utility>
#include "Inductor.h"

Inductor::Inductor() {
	inductance = 0.0;
	current = new double[2];
	current[0] = 0.0;
	current[1] = 0.0;
}

Inductor::Inductor(double _inductance) {
	inductance = _inductance;
	current = new double[2];
	current[0] = 0.0;
	current[1] = 0.0;
}

Inductor::Inductor(const Inductor& inductor) {//Copy constructor
	*this = inductor;
/*	this->inductance = inductor.inductance;
	this->current = new double[2];
	if (inductor.current != nullptr) {
		this->current[0] = inductor.current[0];
		this->current[1] = inductor.current[1];
	}
	else {
		this->current[0] = 0.0;
		this->current[1] = 0.0;
	}*/
}

Inductor& Inductor::operator=(const Inductor& inductor) {//Copy assignment
	if (this != &inductor) {
		this->inductance = inductor.inductance;
		if (this->current == nullptr) this->current = new double[2];
		if (inductor.current != nullptr) {
			this->current[0] = inductor.current[0];
			this->current[1] = inductor.current[1];
		}
		else {
			this->current[0] = 0.0;
			this->current[1] = 0.0;
		}
	}
	return *this;
}

Inductor::Inductor(Inductor&& inductor) noexcept {//Move constructor
	*this = std::move(inductor);//&&
/*	this->inductance = inductor.inductance;
	if(this->current!=nullptr) delete[] this->current;
	this->current = inductor.current;
	inductor.inductance = 0.0;
	inductor.current = nullptr;*/
}

Inductor& Inductor::operator=(Inductor&& inductor) noexcept {//Move assignment
	if (this != &inductor) {
		this->inductance = inductor.inductance;
		if (this->current != nullptr) delete[] this->current;
		this->current = inductor.current;
		inductor.inductance = 0.0;
		inductor.current = nullptr;
	}
	return *this;
}

void Inductor::SetCurrent(double _current) {
	current[1] = current[0];
	current[0] = _current;
}

double Inductor::GetVoltage(void) {
	return inductance * (current[0] - current[1]) / timestep;
}

Inductor::~Inductor() {
	if (current != nullptr) {
		delete[] current;
		current = nullptr;
	}
}


/*
class Employee e1, e2;

class Employee {
	std::string name;
	int age;
	int count;
	double* salaryHistory;
};

e1 has the following:
std::string name = "Alpesh Gupta";
int age = 34;
int count = 5;
double* salaryHistory = { 47000, 48000, 50000, 55000, 62000 };

e2 has the following:
std::string name = "Mirko Crocop";
int age = 27;
int count = 3;
double* salaryHistory = { 60000, 65000, 75000 };

//Copy values from e2 to e1
e1.name = e2.name;
e1.age = e2.age;
e1.count = e2.count;
delete[] e1->salaryHistory;
//no need to allocate memory for e1->salaryHistory again
//no need to copy from e2->salaryHistory one by one
e1->salaryHistory = e2->salaryHistory;

//Make e2 an empty object
e2.name = "";
e2.age = 0;
e2.count = 0;
e2->salaryHistory = nullptr;
*/

/*
//Let's say in your object e1, your salaryHistory contains 20 members
double* salaryHistory = new double[20];
//If salaryHistory were simply a double, you would index it as follows:
std::cout << "The salary for year 11 is " << salaryHistory[10] << std::endl;
//If salaryHistory is a part of the object e1, you could index it as follows
//by overloading the operator[]:
std::cout << "The salary for year 11 is " << e1[10] << std::endl;

//You want to index your salary history in e1 by overloading []
double Employee::operator[](int index) {
	double retVal = 0.0;
	if (index < count) {
		retVal = salaryHistory[index];
	}
	return retVal;
}
*/