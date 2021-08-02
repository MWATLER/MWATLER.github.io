//BaseballMain.cpp - main function for baseball team

#include <iostream>
#include "BaseballTeam.h"

using namespace std;

int main(void) {
	int retVal = 0;
	BaseballTeam team;
	team.SetFileName("BaseballTeamDB.txt");
	if (!team.LoadStatsFromFile()) {
		retVal = -1;
	}
	else {
		team.DisplayStats();
		team.DisplayStatsByBattingPercentage();
		team.DisplayStatsByName();
		if (!team.UpdateStatsFromKeyboard()) {
			retVal = -2;
		}
		else {
			team.OrderPlayers();
			team.DisplayStats();
			team.DisplayStatsByBattingPercentage();
			team.DisplayStatsByName();
		}
	}
	if (!team.SaveStatsToFile()) {
		retVal = -3;
	}
	if (!team.SaveStatsToFileByBattingPercentage()) {
		retVal = -3;
	}
	if (!team.SaveStatsToFileByName()) {
		retVal = -3;
	}

	return retVal;
}