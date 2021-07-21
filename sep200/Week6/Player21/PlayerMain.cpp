//PlayerMain.cpp - main program for the card player

#include<iostream>
#include"PlayerYouth.h"
#include "PlayerAdult.h"

using namespace std;

int main(void) {
	const int MAX = 21;
	const int NUM = 2;
	PlayerBase<int>* player[NUM];
	string mode;
	player[0] = new PlayerYouth<int>("Noah");
	player[1] = new PlayerAdult<int>("Kenneth");

	bool gameOver = false;
	do {
		double amount;
		cout << "How much do you both want to bet? (min$10, max $300): $";
		cin >> amount;
		if (amount > 300) amount = 300;
		if (amount < 0) amount = 10;
		int numCards;
		for (int i = 0; i < NUM; ++i) {
			cout << player[i]->GetName() << ", how many dependent cards to you want? ";
			cin >> numCards;
			player[i]->AddDependentCards(numCards);
			cout << player[i]->GetName() << ", how many attack cards to you want? ";
			cin >> numCards;
			player[i]->AddAttackCards(numCards);
			cout << player[i]->GetName() << ", the sum of your cards is " << player[i]->SumCards() << endl;
			cout << "Do you want to add a dependent card? [Y,N]";
			cin >> mode;
			if (mode == "Y" || mode =="y") {
				player[i]->AddDependentCard();
			}
			cout << player[i]->GetName() << ", the sum of your cards is " << player[i]->SumCards() << endl;
			cout << "Do you want to add an attack card? [Y,N]";
			cin >> mode;
			if (mode == "Y" || mode == "y") {
				player[i]->AddAttackCard();
			}
			cout << player[i]->GetName() << ", the sum of your cards is " << player[i]->SumCards() << endl;
			cout << endl;
		}

		//Report the points for each
		for (int i = 0; i < NUM; ++i) {
			cout << player[i]->GetName() << " has " << player[i]->SumCards() << " points." << endl;
		}
		cout << endl;

		//Determine a winner
		bool player1Disqualified = false;
		bool player2Disqualified = false;
		if (player[0]->SumCards() > MAX) {
			cout << player[0]->GetName() << " has a sum of " << player[0]->SumCards() << ", which is over the limit." << endl;
			player1Disqualified = true;
		}
		if (player[1]->SumCards() > MAX) {
			cout << player[1]->GetName() << " has a sum of " << player[1]->SumCards() << ", which is over the limit." << endl;
			player2Disqualified = true;
		}

		if (player1Disqualified && player2Disqualified) {
			cout << "Both players are over the limit and have been disqualified." << endl;
		}
		else if (player1Disqualified) {
			cout << player[0]->GetName() << " has been disqualified for going over the limit. " << player[1]->GetName() << " has won." << endl;
			*player[1] << amount;
			*player[0] >> amount;
		}
		else if (player2Disqualified) {
			cout << player[1]->GetName() << " has been disqualified for going over the limit. " << player[0]->GetName() << " has won." << endl;
			*player[0] << amount;
			*player[1] >> amount;
		}
		else if (*player[0] == *player[1]) {
			cout << "Both players drew the same number of points. No winner." << endl;
		}
		else if (*player[0] > *player[1]) {
			cout << player[0]->GetName() << " has won!" << endl;
			*player[0] << amount;
			*player[1] >> amount;
		}
		else if (*player[0] < *player[1]) {
			cout << player[1]->GetName() << " has won!" << endl;
			*player[1] << amount;
			*player[0] >> amount;
		}
		cout << endl;

		//Report the cash for each
		for (int i = 0; i < NUM; ++i) {
			cout << player[i]->GetName() << " has $" << player[i]->GetCash() << "." << endl;
		}
		cout << endl;

		for (int i = 0; i < NUM && !gameOver; ++i) {//Determine whether it's time to quit
			if (player[i]->GetCash() < 0) gameOver = true;
		}
	} while (!gameOver);

	cout << "The game is over." << endl;
	for (int i = 0; i < NUM; ++i) {//The final report
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << player[i]->GetName() << " has $" << player[i]->GetCash() << endl;
		delete player[i];
	}

	return 0;
}