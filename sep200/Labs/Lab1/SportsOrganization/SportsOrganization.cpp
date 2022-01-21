//SportsOrganization.cpp - main function for sports organizations.

#include "Team.h"

using namespace std;

int main() {
	const int NUM_TEAMS = 4;
	Team* team[NUM_TEAMS];
	team[0] = new Team("Toronto Maple Leafs", "Ice Hockey", "Maple Leaf Square, 15 York St, Toronto, ON M5J 0A3", 1800.00);
	team[1] = new Team("New York Rangers", "Ice Hockey", "Pennsylvania Station, Pennsylvania Plaza, New York, NY 10121, United States", 2000.00);
	team[2] = new Team("Toronto Raptors", "Basketball", "Maple Leaf Square, 15 York St, Toronto, ON M5J 0A3", 2100.00);
	team[3] = new Team("Montreal Canadiens", "Ice Hockey", "1909, avenue des Canadiens-de-Montréal Montreal, Quebec H3B 5E8", 1340.00);
	//*team[0] - object of type Team
	// team[0] - the address of the object of type Team

	for (int i = 0; i < NUM_TEAMS; ++i) {
		cout << *team[i];//Why '*', because operator<< expects an object of type Team
	}

	for (int i = 0; i < NUM_TEAMS; ++i) {
		for (int j = i+1; j < NUM_TEAMS; ++j) {
			if (*team[i] == *team[j]) {//Why '*', operator== expects objects on both sides of the ==
				cout << "The " << team[i]->GetName() << " and the " << team[j]->GetName() << " belong to the same sports organization." << endl;
			}
		}
	}

	//Why not "delete[] team" ?
//	delete[] team;//Will not work - each team in the array is a different size, 
				  //                so you have to delete each team separately.
	for (int i = 0; i < NUM_TEAMS; ++i) {
		delete team[i];
	}
	return 0;
}