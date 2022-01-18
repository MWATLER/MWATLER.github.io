//HockeyTeam.cpp - function definitions for a hockey team
//
// 09-Feb-21  M. Watler         Created.

#include "HockeyTeam.h"

using namespace std;

HockeyTeam::HockeyTeam() {
	name = "";
	games = 0;
	wins = 0;
	ties = 0;
	losses = 0;
	points = 0;
	goalsFor = 0;
	goalsAgainst = 0;
}

HockeyTeam::HockeyTeam(std::string _name, int _games, int _wins, int _losses, int _ties, int _goalsFor, int _goalsAgainst) {
	name = _name;
	games = _games;
	wins = _wins;
	losses = _losses;
	ties = _ties;
	points = 2*wins + ties;
	goalsFor = _goalsFor;
	goalsAgainst = _goalsAgainst;
}

void HockeyTeam::AddGame(HockeyTeam& opponent, int goalsFor, int goalsAgainst) {
//	team[0]->AddGame(*team[1], 3, 4);
	++this->games;
	++opponent.games;
	this->goalsFor += goalsFor;
	this->goalsAgainst += goalsAgainst;
	opponent.goalsFor += goalsAgainst;
	opponent.goalsAgainst += goalsFor;
	if (goalsFor > goalsAgainst) {
		++this->wins;
		++opponent.losses;
		this->points += 2;
	}
	else if (goalsFor < goalsAgainst) {
		++this->losses;
		++opponent.wins;
		opponent.points += 2;
	}
	else {
		++this->ties;
		++opponent.ties;
		this->points += 1;
		opponent.points += 1;
	}
}

const HockeyTeam& HockeyTeam::operator+=(int points) {
	this->points += points;
	return *this;
}

const HockeyTeam& HockeyTeam::operator-=(int points) {
	this->points -= points;
	return *this;
}

double HockeyTeam::GetWinningPercentage() const {
	return (double)100.0* points / (2.0 * games);
}

double HockeyTeam::GetGoalsForAverage() const {
	return (double)goalsFor / games;
}

double HockeyTeam::GetGoalsAgainstAverage() const {
	return (double)goalsAgainst / games;
}

string HockeyTeam::GetName() const {
	return name;
}

int HockeyTeam::GetPoints() const {
	return points;
}

std::ostream& HockeyTeam::PrintReport() const {
	cout << name << " has played " << games << " and has a winning percentage of " << GetWinningPercentage() << endl;
	cout << name << " has a goals for average of " << GetGoalsForAverage() << " and a goals against average of " << GetGoalsAgainstAverage() << endl;
	return cout;
}

bool operator==(const HockeyTeam& team1, const HockeyTeam& team2) {//not a friend of HockeyTeam
//	if (*team[0] == *team[1])
//	return (team1.points == team2.points);
	return (team1.GetPoints() == team2.GetPoints());//use accessor functions
}

bool operator!=(const HockeyTeam& team1, const HockeyTeam& team2) {//a friend of HockeyTeam
//	if (*team[2] != *team[3])
	return (team1.points != team2.points);//direct access to private members
//	return (team1.GetPoints() != team2.GetPoints());
}
/*
bool HockeyTeam::operator!=(const HockeyTeam& team2) {
	return (this->points != team2.points);//direct access to private members
//	return (team1.GetPoints() != team2.GetPoints());
}
*/
HockeyTeam operator+(HockeyTeam& team, int points) {
//	*team[0] = *team[0] + 2;
	team += points;// += has also been overloaded
	return team;
}

HockeyTeam operator-(HockeyTeam& team, int points) {
//	*team[1] = *team[1] - 2;
	team -= points;// -= has also been overloaded
	return team;
}
