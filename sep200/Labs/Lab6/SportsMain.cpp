//SportsMain.cpp - main function for the sports association

#include "SportsAssociation.h"
#include "BaseballTeam.h"
#include "HockeyTeam.h"

using namespace std;

int main() {
	SportsAssociation assoc("Rexdale Sports Association");

	for (int i = 0; i < MAX; ++i) {
		Team* team = CreateTeam();
		assoc += *team;
	}
	assoc.display();

	return 0;
}