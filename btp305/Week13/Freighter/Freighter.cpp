//Freighter.cpp - function definitions for a freighter

#include <future>
#include <string>
#include <thread>
#include "Freighter.h"

Freighter& Freighter::operator+=(const Cargo& cargo) {
	if (cargo.GetType() != CargoType::Electronics) {
		this->cargo.push_back(cargo);
	}
	else
		throw "Cargo (" + cargo.GetName() + ") is banned.";
	return *this;
}

Freighter& Freighter::operator-=(const std::string& _name) {
	bool found = false;
	std::vector<Cargo>::iterator it;
	for (it = this->cargo.begin(); it != this->cargo.end() && !found; ++it) {
		if (it->GetName() == _name) {
			it = this->cargo.erase(it);
			if (it == this->cargo.end())--it;//don't go past the end of the vector
			found = true;
		}
	}
	if (!found) std::cout << "Could not erase cargo named " << _name << std::endl;

	return *this;
}

Cargo* Freighter::operator[](const double& value)
{
	for (std::vector<Cargo>::iterator it = this->cargo.begin(); it != this->cargo.end(); ++it)
	{
		if (it->GetValue() > value)
			return &(*it);
	}
	return nullptr;
}

Cargo* Freighter::operator[](const int& index) {
	if (index < this->cargo.size()) {
		return &(this->cargo.at(index));
	}
	return nullptr;
}


void Freighter::display(void (*disp)(std::ostream&, const Cargo& cargo)) {
	double worth = 0.00;
	if (!disp)
		exit(11);

	std::future<double> f1 = std::async(calcTotalWorth, this->cargo.begin(), this->cargo.begin() + this->cargo.size() / 3);
	std::future<double> f2 = std::async(calcTotalWorth, this->cargo.begin() + this->cargo.size() / 3, this->cargo.begin() + (2 * this->cargo.size() / 3));
	std::future<double> f3 = std::async(calcTotalWorth, this->cargo.begin() + 2 * this->cargo.size() / 3, this->cargo.end());
	worth = f1.get() + f2.get() + f3.get();

	for (auto c : cargo)
		disp(std::cout, c);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(2);
	std::cout << "\n==========\nNet Worth: $" << worth << "\n==========\n" << std::endl;
}

double calcTotalWorth(std::vector<Cargo>::iterator begin, std::vector<Cargo>::iterator end) {
	double worth = 0;
	for (auto i = begin; i != end; ++i)
		worth += i->GetValue();
	return worth;
}