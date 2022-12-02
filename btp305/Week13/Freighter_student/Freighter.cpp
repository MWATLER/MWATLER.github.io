//Freighter.cpp - function definitions for a freighter

#include <future>
#include <thread>
#include "Freighter.h"

Freighter::Freighter() {

}

Freighter::Freighter(const Freighter& rhs){
	*this = rhs;
}

Freighter& Freighter::operator=(const Freighter& rhs){
	if (this != &rhs && rhs.cargo.size()!=0) {
//		std::vector<Cargo> cargo;
		this->cargo.clear();
		this->cargo = rhs.cargo;//the vector has its own copy assignment
/*		for (auto it = rhs.cargo.begin(); it < rhs.cargo.end(); ++it) {
			this->cargo.push_back(*it);
		}*/
	}
	return *this;
}

Freighter::Freighter(Freighter&& rhs) noexcept{
	*this = std::move(rhs);
}

Freighter& Freighter::operator=(Freighter&& rhs) noexcept{
	if (this != &rhs && rhs.cargo.size() != 0) {
		this->cargo = std::move(rhs.cargo);
	}
	return *this;
}
/*
Overloaded += operator that

	Adds a Cargo object to the current object and returns a reference to 
	the current object only if the cargo is not of type Electronics

	If the cargo is of type Electronics, the operator should not change 
	the current object and throws an exception
*/
Freighter& Freighter::operator+=(const Cargo& rhs){
	if (rhs.GetType() != CargoType::Electronics) {
		this->cargo.push_back(rhs);
	}
	else {
		throw "Cargo (" + rhs.GetName() + ") is banned.";
	}
	return *this;
}
/*
Overloaded -= operator that

	Takes a name as argument and removes the first cargo with that name
	If the cargo cannot be found, it prints an error message
*/
Freighter& Freighter::operator-=(const std::string name) {
	bool found = false;
	//could use STL algorithm first_of
	for (auto it = cargo.begin(); it < cargo.end() && !found; it++) {
		if (it->GetName() == name) {
			found = true;
			it = this->cargo.erase(it);
			--it;
		}
	}
	if (!found) std::cout << "Cargo " << name << " not found" << std::endl;
	return *this;
}
/*
Overloaded [] operator that

	Takes as an input a value (double)
	Returns the address of the first cargo object that is greater than this value
	If no such cargo exists, the function returns nullptr
*/
Cargo* Freighter::operator[](const double& value) {
	
	for (auto it = this->cargo.begin(); it < this->cargo.end(); ++it) {
		if (it->GetValue() > value) {
			return &(*it);
		}
	}
	return nullptr;
}
/*
Overloaded [] operator that

	Takes as an input an index (int)
	Returns the address of the cargo object at this index of the Cargo container
	If no such cargo exists, the function returns nullptr
*/
Cargo* Freighter::operator[](const int& index) {
	if (index < cargo.size()) {
		return &cargo.at(index);
	}
	return nullptr;
}
/*
A display function that:

	Receives the address of one of the global functions that displays the 
	requested information (byCargoType, byValue, byEverything)

	Displays the total worth of all cargo

	Calculates the total worth of all cargo in three threads. 
	The thread function is calcTotalWorth
*/
void Freighter::display(void (*cargoDisp)(std::ostream& os, const Cargo& cargo)) {
	if (!cargoDisp)
		exit(11);

	for (auto it = this->cargo.begin(); it < this->cargo.end(); ++it) {
		cargoDisp(std::cout, *it);
	}
	std::future<double> f1 = std::async(calcTotalWorth, cargo.begin(), cargo.begin() + cargo.size() / 3);
	std::future<double> f2 = std::async(calcTotalWorth, cargo.begin() + cargo.size() / 3, cargo.begin() + 2 * cargo.size() / 3);
	std::future<double> f3 = std::async(calcTotalWorth, cargo.begin() + 2*cargo.size() / 3, cargo.end());
	double worth = f1.get() + f2.get() + f3.get();
	std::cout << "The worth of all cargo is $" << worth << std::endl;
}

double calcTotalWorth(std::vector<Cargo>::iterator begin, 
	                  std::vector<Cargo>::iterator end) {
	double worth = 0;
	for (auto i = begin; i != end; ++i)
		worth += i->GetValue();
	return worth;
}