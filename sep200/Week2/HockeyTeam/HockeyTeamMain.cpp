//HockeyTeamMain.cpp - Main program for hockey teams
//
// 09-Feb-21  M. Watler         Created.

#include "HockeyTeam.h"

using namespace std;

const int NUM_TEAMS = 4;

int main(void) {
	HockeyTeam *team[NUM_TEAMS];

	team[0] = new HockeyTeam("Erindale Spitfires", 3, 2, 0, 1, 8, 4);
	team[1] = new HockeyTeam("Clarkson Hurricane", 3, 2, 1, 0, 7, 4);
	team[2] = new HockeyTeam("Streetsville Sabres", 3, 1, 2, 0, 5, 7);
	team[3] = new HockeyTeam("Meadowvale Hawks", 3, 0, 2, 1, 4, 9);

	for (int i = 0; i < NUM_TEAMS; ++i) {
		team[i]->PrintReport() << endl;
	}

	cout << "--------------------------------------------" << endl << endl;

	team[0]->AddGame(*team[1], 3, 4);
	team[3]->AddGame(*team[2], 6, 2);

	for (int i = 0; i < NUM_TEAMS; ++i) {
		team[i]->PrintReport() << endl;
	}

	cout << "--------------------------------------------" << endl << endl;

	team[3]->AddGame(*team[1], 5, 4);
	team[2]->AddGame(*team[0], 1, 1);

	for (int i = 0; i < NUM_TEAMS; ++i) {
		team[i]->PrintReport() << endl;
	}

	if (*team[0] == *team[1]) {
		cout << team[0]->GetName() << " is equal with " << team[1]->GetName() << endl;
	}
	if (*team[2] != *team[3]) {
		cout << team[2]->GetName() << " is not equal with " << team[3]->GetName() << endl;
	}

	*team[0] = *team[0] + 2;
	*team[1] = *team[1] - 2;

	cout << "--------------------------------------------" << endl << endl;

	for (int i = 0; i < NUM_TEAMS; ++i) {
		team[i]->PrintReport() << endl;
	}

	for (int i = 0; i < NUM_TEAMS; ++i) {
		delete team[i];
	}

	return 0;
}