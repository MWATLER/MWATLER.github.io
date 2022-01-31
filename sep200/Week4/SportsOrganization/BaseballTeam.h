//BaseballTeam.h - class declaration for a baseball team

#ifndef _BASEBALLTEAM_H_
#define _BASEBALLTEAM_H_

#include "SportsOrganization.h"

struct BaseballPlayer {
	std::string name;
	int hits;
	int atBats;
};

class BaseballTeam : public SportsOrganization {
	int wins;
	int losses;
	BaseballPlayer* player;
	int numPlayers;
public:
	BaseballTeam(std::string name, std::string address, int wins, int losses);

	//The rule of 5: a custom copy constructor, copy assignment, move constructor, move assignment, destructor
	BaseballTeam(const BaseballTeam& team);//copy constructor
	BaseballTeam(BaseballTeam&& team) noexcept;//move constructor
	BaseballTeam& operator=(const BaseballTeam& team);//copy assignment
	BaseballTeam& operator=(BaseballTeam&& team) noexcept;//move assignment
	~BaseballTeam();

	void SetPlayers(const BaseballPlayer* player, int num);
	double GetWinningPercentage() const;
	void display(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const BaseballTeam& team);

#endif// _BASEBALLTEAM_H_