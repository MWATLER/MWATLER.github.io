//CardGame.cpp - main function for the card game
//
// 15-Feb-21  M. Watler         Created.

#include <iostream>
#include "Player.h"

using namespace std;

int main(void) {
	const int NUM = 3;
	Player* player[NUM];

	player[0] = new Player("Tony Soprano", 100);
	player[1] = new Player("Pauli \"Walnuts\" Gualtieri", 100);
	player[2] = new Player("Furio Guinta", 100);

	while (player[0]->GetTokens() < 300 && player[1]->GetTokens() < 300 && player[2]->GetTokens() < 300) {
		for (int i = 0; i < NUM; ++i) {
			player[i]->PlayCard();
		}

		if (*player[0] > *player[1] && *player[0] > *player[2]) {
			*player[0] << *player[1];
			*player[0] << *player[2];
		}
		else if (*player[1] > *player[0] && *player[1] > *player[2]) {
			*player[1] << *player[0];
			*player[1] << *player[2];
		}
		else if (*player[2] > *player[0] && *player[2] > *player[1]) {
			*player[2] << *player[0];
			*player[2] << *player[1];
		}
		else {
			cout << "No clear winner" << endl;
		}

		for (int i = 0; i < NUM; ++i) {
			player[i]->DisplayInfo();
		}
		cout << endl;
	}

	cout << "Furio steals the tokens from everyone" << endl;
	*player[0] >> *player[2];
	*player[1] >> *player[2];
	for (int i = 0; i < NUM; ++i) {
		player[i]->DisplayInfo();
	}

	for (int i = 0; i < NUM; ++i) {
		delete player[i];
	}

	return 0;
}