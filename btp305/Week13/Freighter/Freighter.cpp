//Freighter.cpp - function definitions for a freighter

#include <future>
#include <string>
#include <thread>
#include "Freighter.h"

Freighter& Freighter::operator+=(const Cargo& cargo) {
	if (cargo.GetValue() >= limit) {
		this->cargo.push_back(cargo);
	}
	else
		throw "Value of Cargo (" + cargo.GetName() + ") is less than " + std::to_string(limit);
	return *this;
}

Cargo* Freighter::operator[](const std::string& name_)
{
	for (std::vector<Cargo>::iterator it = this->cargo.begin(); it != this->cargo.end(); ++it)
	{
		if (it->GetName() == name_)
			return &(*it);
	}
	return nullptr;
}

void Freighter::display(void (*disp)(std::ostream&, const Cargo& cargo)) {
	bool status{ false };

	if (!disp)
		exit(11);

	if (!status) {
		std::future<double> f1 = std::async(calcTotalWorth, this->cargo.begin(), this->cargo.begin() + this->cargo.size() / 2);
		std::future<double> f2 = std::async(calcTotalWorth, this->cargo.begin() + this->cargo.size() / 2, this->cargo.end());
		worth = f1.get() + f2.get();
		status = true;
	}

	for (auto c : cargo)
		disp(std::cout, c);

	std::cout << "\n==========\nNet Worth: " << worth << "\n==========\n" << std::endl;
}

double calcTotalWorth(std::vector<Cargo>::iterator begin, std::vector<Cargo>::iterator end) {
	double worth = 0;
	for (auto i = begin; i != end; ++i)
		worth += i->GetValue();
	return worth;
}