//Team.h - class declarations for a team

#ifndef _TEAM_H_
#define _TEAM_H_

#include <iostream>

enum Err_Status {
	Err_Success,
	Err_Undefined,
	Err_OutOfBounds,
	Err_Calculation
};

class Team {
public:
	virtual std::string GetName() const = 0;
	virtual Err_Status display() const = 0;
	virtual bool operator==(const Team&) const = 0;
};

Team* CreateTeam();

#endif// _TEAM_H_