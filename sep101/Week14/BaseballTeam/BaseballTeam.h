//BaseballTeam.h - class declaration of a baseball team

#ifndef _BASEBALLTEAM_H_
#define _BASEBALLTEAM_H_

#include <iostream>

const int NUM = 5;

struct Player {
	std::string name;
	int atBats;
	int hits;
	double battingPercentage;
	int battingRank;//order by batting percentage
	int nameRank;//order by name
};

class BaseballTeam {
	std::string name;
	int wins;
	int losses;
	double winningPercentage;
	Player player[NUM];
	std::string dbFileName;
	bool UtilReadFromFile();
	void UtilDisplayHeaderStats(std::string category) const;
public:
	BaseballTeam();
	BaseballTeam(std::string dbFileName);//the database stores all team information
	                                     //the database fields are separated by a semicolon
	bool SetFileName(std::string dbFileName);
	void OrderPlayers();//by batting percentage and by name
	bool LoadStatsFromFile();
	bool UpdateStatsFromKeyboard();
	void DisplayStats() const;
	void DisplayStatsByBattingPercentage() const;
	void DisplayStatsByName() const;
	bool SaveStatsToFile();
	bool SaveStatsToFileByBattingPercentage();
	bool SaveStatsToFileByName();
};

#endif// _BASEBALLTEAM_H_
