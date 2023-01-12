//BaseballTeam.cpp - function definitions for a hockey team

#include "BaseballTeam.h"

using namespace std;

BaseballTeam::BaseballTeam(std::string name, std::string address, int wins, int losses) :
	SportsOrganization(name, address) {
	this->wins = wins;
	this->losses = losses;
	player = nullptr;
	numPlayers = 0;
}

BaseballTeam::BaseballTeam(const BaseballTeam& team) {
	*this = team;//invoke the copy assignment
}

BaseballTeam::BaseballTeam(BaseballTeam&& team) noexcept {//move constructor
	*this = std::move(team);//invoke the move assignment
}

BaseballTeam& BaseballTeam::operator=(const BaseballTeam& team) {
	if (this != &team) {//do not copy to yourself
		//call the base class copy assignment operator
		(SportsOrganization&)*this = team;
		//shallow copies
		this->wins = team.wins;
		this->losses = team.losses;
		numPlayers = team.numPlayers;
		//deep copy
		delete[] player;
		if (numPlayers > 0) {
			player = new BaseballPlayer[numPlayers];
			for (int i = 0; i < numPlayers; ++i) {
				player[i].name = team.player[i].name;
				player[i].atBats = team.player[i].atBats;
				player[i].hits = team.player[i].hits;
			}
		}
		else {
			player = nullptr;
		}
	}
	return *this;
}

BaseballTeam& BaseballTeam::operator=(BaseballTeam&& team) noexcept {//move assignment
	if (this != &team) {//do not move to yourself
		//call the base class move assignment operator
		(SportsOrganization&)*this = std::move(team);
		//shallow copies
		this->wins = team.wins;
		this->losses = team.losses;
		numPlayers = team.numPlayers;
		//take control of the resoure of the rhs
		delete[] player;
		player = team.player;

		//put the rhs into an empty state
		team.wins = 0;
		team.losses = 0;
		team.numPlayers = 0;
		team.player = nullptr;
	}
	return *this;
}

BaseballTeam::~BaseballTeam() {
	delete[] player;
	player = nullptr;
}

void BaseballTeam::SetPlayers(const BaseballPlayer* player, int num) {
	numPlayers = num;
	delete[] this->player;
	this->player = new BaseballPlayer[numPlayers];
	for (int i = 0; i < numPlayers; ++i) {
		this->player[i].name = player[i].name;
		this->player[i].atBats = player[i].atBats;
		this->player[i].hits = player[i].hits;
	}
}

double BaseballTeam::GetWinningPercentage() const {
	int points = 2 * wins;
	int games = wins + losses;
	int possiblePoints = 2 * games;
	return 100.0 * (double)points / possiblePoints;
}

void BaseballTeam::display(std::ostream& os) const {
	SportsOrganization::display(os);
	os << "The " << name << " is a baseball team which has the following players:" << endl;
	os.setf(std::ios::fixed);
	os.precision(3);
	for (int i = 0; i < numPlayers; ++i) {
		os << player[i].name << " has a batting average of " << (double)player[i].hits / player[i].atBats << endl;
	}
	os << endl;
	os.setf(std::ios::fixed);
	os.precision(1);
	os << name << " has a winning percentage of " << GetWinningPercentage() << "%." << endl << endl;
}

std::ostream& operator<<(std::ostream& os, const BaseballTeam& team) {
	team.display(os);
	return os;
}
