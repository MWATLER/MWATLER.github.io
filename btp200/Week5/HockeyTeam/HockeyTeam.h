//HockeyTeam.h - class declaration for a hockey team
//
// 09-Feb-21  M. Watler         Created.

#include <iostream>

class HockeyTeam {
	std::string name;
	int games;
	int wins;
	int losses;
	int ties;
	int points;//2*wins + 1*ties
	int goalsFor;
	int goalsAgainst;
public:
	HockeyTeam();
	HockeyTeam(std::string _name, int _games, int _wins, int _losses, int _ties, int goalsFor, int goalsAgainst);

	void AddGame(HockeyTeam& opponent, int goalsFor, int goalsAgainst);
	const HockeyTeam& operator+=(int);
	const HockeyTeam& operator-=(int);
	friend bool operator!=(const HockeyTeam&, const HockeyTeam&);
	double GetWinningPercentage() const;
	double GetGoalsForAverage() const;
	double GetGoalsAgainstAverage() const;
	std::string GetName() const;
	int GetPoints() const;
	std::ostream& PrintReport() const;
};

bool operator==(const HockeyTeam&, const HockeyTeam&);
bool operator!=(const HockeyTeam&, const HockeyTeam&);
HockeyTeam operator+(HockeyTeam&, int);
HockeyTeam operator-(HockeyTeam&, int);
