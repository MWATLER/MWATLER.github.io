//HockeyTeam.cpp - function definitions for a hockey team

#include "HockeyTeam.h"

using namespace std;

HockeyTeam::HockeyTeam(std::string name, std::string address, int wins, int losses, int ties) :
	SportsOrganization(name, address) {//invoke the constructor for SportsOrganization
	this->wins = wins;
	this->losses = losses;
	this->ties = ties;
	player = nullptr;
	numPlayers = 0;
}

HockeyTeam::HockeyTeam(const HockeyTeam& team) {//copy constructor
	*this = team;//invoke the copy assignment
}

HockeyTeam::HockeyTeam(HockeyTeam&& team) noexcept {
	*this = std::move(team);//invoke the move assignment
}

HockeyTeam& HockeyTeam::operator=(const HockeyTeam& team) {//copy assignment
	if (this != &team) {//do not copy to yourself
		//call the base class copy assignment operator
		(SportsOrganization&)*this = team;
		//shallow copies
		this->wins = team.wins;
		this->losses = team.losses;
		this->ties = team.ties;
		numPlayers = team.numPlayers;
		//deep copy
		delete[] player;
		if (numPlayers > 0) {
			player = new HockeyPlayer[numPlayers];
			for (int i = 0; i < numPlayers; ++i) {
				player[i].name = team.player[i].name;
				player[i].goals = team.player[i].goals;
				player[i].assists = team.player[i].assists;
			}
		}
		else {
			player = nullptr;
		}
	}
	return *this;
}

HockeyTeam& HockeyTeam::operator=(HockeyTeam&& team) noexcept {
	if (this != &team) {//do not move to yourself
		//call the base class move assignment operator
		(SportsOrganization&)*this = std::move(team);
		//shallow copies
		this->wins = team.wins;
		this->losses = team.losses;
		this->ties = team.ties;
		numPlayers = team.numPlayers;
		//take control of the resoure of the rhs
		delete[] player;
		player = team.player;

		//put the rhs into an empty state
		team.wins = 0;
		team.losses = 0;
		team.ties = 0;
		team.numPlayers = 0;
		team.player = nullptr;
	}
	return *this;
}

HockeyTeam::~HockeyTeam() {
	delete[] player;
	player = nullptr;
}

void HockeyTeam::SetPlayers(const HockeyPlayer* player, int num) {
	numPlayers = num;
	delete[] this->player;
	this->player = new HockeyPlayer[numPlayers];
	for (int i = 0; i < numPlayers; ++i) {
		this->player[i].name = player[i].name;
		this->player[i].goals = player[i].goals;
		this->player[i].assists = player[i].assists;
	}
}

double HockeyTeam::GetWinningPercentage() const {
	int points = 2 * wins + ties;
	int games = wins + ties + losses;
	int possiblePoints = 2 * games;
	return 100.0 * (double)points / possiblePoints;
}

void HockeyTeam::display(std::ostream& os) const {
	SportsOrganization::display(os);
	os << "The " << name << " is a hockey team which has the following players:" << endl;
	for (int i = 0; i < numPlayers; ++i) {
		os << player[i].name << " has " << player[i].goals << " goals, " << player[i].assists << " assists, " << (player[i].goals + player[i].assists) << " points." << endl;
	}
	os << endl;
	os.setf(std::ios::fixed);
	os.precision(1);
	os << name << " has a winning percentage of " << GetWinningPercentage() << "%." << endl << endl;

}

std::ostream& operator<<(std::ostream& os, const HockeyTeam& team) {
	team.display(os);
	return os;
}
