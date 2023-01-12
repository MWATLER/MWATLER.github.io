//HockeyTeam.h - class declaration for a hockey team

#ifndef _HOCKEYTEAM_H_
#define _HOCKEYTEAM_H_

#include "SportsOrganization.h"

struct HockeyPlayer {
	std::string name;
	int goals;
	int assists;
};

class HockeyTeam : public SportsOrganization {
	int wins;
	int losses;
	int ties;
	HockeyPlayer* player;//a resource
	int numPlayers;
public:
	HockeyTeam(std::string name, std::string address, int wins, int losses, int ties);

	//The rule of 5: a custom copy constructor, copy assignment, move constructor, move assignment, destructor
	HockeyTeam(const HockeyTeam& team);//copy constructor
	HockeyTeam(HockeyTeam&& team) noexcept;//move constructor
	HockeyTeam& operator=(const HockeyTeam& team);//copy assignment
	HockeyTeam& operator=(HockeyTeam&& team) noexcept;//move assignment
	~HockeyTeam();

	void SetPlayers(const HockeyPlayer* player, int num);
	double GetWinningPercentage() const;
	void display(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, const HockeyTeam& team);

#endif// _HOCKEYTEAM_H_