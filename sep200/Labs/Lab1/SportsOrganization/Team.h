//Team.h - class declarations for a sports team

#ifndef _TEAM_H_
#define _TEAM_H_

#include <iostream>

class Team {
	std::string name = "";
	std::string sport = "";
	std::string address = "";
	double netWorth = 0.0;//in millions of dollars
public:
	Team(std::string name, std::string sport, std::string address, double netWorth) {
		this->name = name;
		this->sport = sport;
		this->address = address;
		this->netWorth = netWorth;
	}
	std::string GetName() const { return name; }
	std::string GetSport() const { return sport; }
	std::string GetAddress() const { return address; }
	double GetNetWorth() const { return netWorth; }
	void display(std::ostream& os) const {//os could be cout, cerr, ...
		if (name != "") {
			os << "The " << name << " is a " << sport << " team located at " << std::endl << address << "." << std::endl;
			os.setf(std::ios::fixed);
			os.precision(2);
			os << "The " << name << " has a net worth of $" << netWorth << " million." << std::endl;
		}
		else {
			os << "no data available." << std::endl;
		}
		os << std::endl;
	}
	bool operator==(const Team& team2) const {//*team[i] == *team[j]   //Why '*'
		bool retVal = false;
		if (this->address == team2.address) retVal = true;
		return retVal;
	}
};

std::ostream& operator<<(std::ostream& os, const Team& team) {//cout << *team[i];//Why '*'
	team.display(os);
	return os;
}

#endif// _TEAM_H_
