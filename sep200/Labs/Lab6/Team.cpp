//Team.cpp - Function for creating teams through the abstract interface

#include <string>
#include "BaseballTeam.h"
#include "HockeyTeam.h"

using namespace std;

Team* CreateTeam() {
	Team* team = nullptr;
	int select = 0;

	string name;
	int wins;
	int ties;
	int losses;
	do {
		cout << endl;
		cout << "Enter 1 for a baseball team, or" << endl;
		cout << "enter 2 for a hockey team." << endl;
		cin >> select;
		cin.ignore(1000, '\n');

		switch (select) {
		case 1:
			cout << "What's the team's name? ";
			getline(cin, name);
			cout << "Enter the number of wins: ";
			cin >> wins;
			cout << "Enter the number of losses: ";
			cin >> losses;
			team = new BaseballTeam(name, wins, losses);
			break;
		case 2:
			cout << "What's the team's name? ";
			getline(cin, name);
			cout << "Enter the number of wins: ";
			cin >> wins;
			cout << "Enter the number of ties: ";
			cin >> ties;
			cout << "Enter the number of losses: ";
			cin >> losses;
			team = new HockeyTeam(name, wins, ties, losses);
			break;
		}
	} while (select < 1 || select>2);

	return team;
}