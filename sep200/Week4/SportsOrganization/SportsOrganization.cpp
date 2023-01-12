//SportsOrganization.cpp - function definitions for a sports organization

#include "SportsOrganization.h"

using namespace std;

SportsOrganization::SportsOrganization() {
}

SportsOrganization::SportsOrganization(std::string name, std::string address) {
	this->name = name;
	this->address = address;
	sponsor = nullptr;
	numSponsors = 0;
}

SportsOrganization::SportsOrganization(const SportsOrganization& sportsOrg) {
	*this = sportsOrg;//invoke the copy assignment
}

SportsOrganization::SportsOrganization(SportsOrganization&& sportsOrg) noexcept {
	*this = std::move(sportsOrg);//invoke the move assignment
}

SportsOrganization& SportsOrganization::operator=(const SportsOrganization& sportsOrg) {
	if (this != &sportsOrg) {//don't copy to yourself
		//shallow copies
		name = sportsOrg.name;
		address = sportsOrg.address;
		numSponsors = sportsOrg.numSponsors;
		//deep copy
		delete[] sponsor;
		if (numSponsors > 0) {
			sponsor = new Sponsor[numSponsors];
			for (int i = 0; i < numSponsors; ++i) {
				sponsor[i].name = sportsOrg.sponsor[i].name;
				sponsor[i].amount = sportsOrg.sponsor[i].amount;
			}
		}
		else {
			sponsor = nullptr;
		}
	}
	return *this;
}

SportsOrganization& SportsOrganization::operator=(SportsOrganization&& sportsOrg) noexcept {
	if (this != &sportsOrg) {//don't move to yourself
		//shallow copies
		name = sportsOrg.name;
		address = sportsOrg.address;
		numSponsors = sportsOrg.numSponsors;
		delete[] sponsor;
		//take control of the resource of the rhs
		sponsor = sportsOrg.sponsor;

		//put the rhs into an empty state
		sportsOrg.name = "";
		sportsOrg.address = "";
		sportsOrg.numSponsors = 0;
		sportsOrg.sponsor = nullptr;
	}
	return *this;
}

SportsOrganization::~SportsOrganization() {
	delete[] sponsor;
	sponsor = nullptr;
}

void SportsOrganization::SetName(std::string name) {
	this->name = name;
}

void SportsOrganization::SetAddress(std::string address) {
	this->address = address;
}

void SportsOrganization::SetSponsors(const Sponsor* sponsorList, int num) {
	numSponsors = num;
	delete[] sponsor;
	sponsor = new Sponsor[numSponsors];
	for (int i = 0; i < numSponsors; ++i) {
		sponsor[i].name = sponsorList[i].name;
		sponsor[i].amount = sponsorList[i].amount;
	}
}

double SportsOrganization::GetSponsorWorth() const {
	double runningTotal = 0;
	for (int i = 0; i < numSponsors; ++i) {
		runningTotal += sponsor[i].amount;
	}
	return runningTotal;
}


void SportsOrganization::display(std::ostream& os) const {
	if (name != "") {
		os << "The " << name << " is located at " << address << "." << endl << "It has the following sponsors:" << endl;
		os.setf(std::ios::fixed);
		os.precision(2);
		for (int i = 0; i < numSponsors; ++i) {
			os << sponsor[i].name << ": $" << sponsor[i].amount << " million." << endl;
		}
		os << "The total sponsorship is worth $" << GetSponsorWorth() << " million." << endl << endl;
	}
}
