//PlayerMain.cpp - main function for card player

#include <iostream>
#include "Player.h"

using namespace std;

int main(void) {
	Player player1("Street Smarts");
	Player player2("New York State of Mind");
	bool endGame = false;
	const int MAX = 21;
	int numCards;
	string stealCards;
	double amount;

	do {
		cout << "How much do you want to bet? $";
		cin >> amount;
		cout << player1.GetName() << ", how many cards do you want to draw? ";
		cin >> numCards;
		player1.DrawCards(numCards);
		cout << player2.GetName() << ", how many cards do you want to draw? ";
		cin >> numCards;
		player2.DrawCards(numCards);

		cout << endl;
		cout << player1.GetName() << ", you have " << player1.SumCards() << " points. Do you wish to steal the cards from " << player2.GetName() << "? [Y/N]";
		cin >> stealCards;
		if (stealCards == "Y" || stealCards == "y") {
			player1.StealCards(player2);
			cout << player2.GetName() << ", your cards have been stolen. How many cards do you want to draw? ";
			cin >> numCards;
			player2.DrawCards(numCards);
		}

		cout << endl;
		cout << player2.GetName() << ", you have " << player2.SumCards() << " points. Do you wish to steal the cards from " << player1.GetName() << "? [Y/N]";
		cin >> stealCards;
		if (stealCards == "Y" || stealCards == "y") {
			player2.StealCards(player1);
			cout << player1.GetName() << ", your cards have been stolen. How many cards do you want to draw? ";
			cin >> numCards;
			player1.DrawCards(numCards);
		}

		cout << endl;
		cout << player1.GetName() << " has drawn " << player1.SumCards() << " points and " << player2.GetName() << " has drawn " << player2.SumCards() << " points." << endl;

		cout << endl;
		bool player1Disqualified = false;
		bool player2Disqualified = false;
		if (player1.SumCards() > MAX) {
			cout << player1.GetName() << " has gone over the limit." << endl;
			player1Disqualified = true;
		}
		if (player2.SumCards() > MAX) {
			cout << player2.GetName() << " has gone over the limit." << endl;
			player2Disqualified = true;
		}
		if (!player1Disqualified && player2Disqualified) {
			cout << player1.GetName() << " has won!" << endl;
			bool ret = player1.AddCash(amount);
			ret = player2.AddCash(-amount);
			if (!ret) {
				endGame = true;
			}
		}
		else if (!player2Disqualified && player1Disqualified) {
			cout << player2.GetName() << " has won!" << endl;
			bool ret = player2.AddCash(amount);
			ret = player1.AddCash(-amount);
			if (!ret) {
				endGame = true;
			}
		}
		else if (player1.SumCards() > player2.SumCards() && !player1Disqualified) {
			cout << player1.GetName() << " has won!" << endl;
			bool ret = player1.AddCash(amount);
			ret = player2.AddCash(-amount);
			if (!ret) {
				endGame = true;
			}
		}
		else if (player2.SumCards() > player1.SumCards() && !player2Disqualified) {
			cout << player2.GetName() << " has won!" << endl;
			bool ret = player2.AddCash(amount);
			ret = player1.AddCash(-amount);
			if (!ret) {
				endGame = true;
			}
		}
		else if (player1.SumCards() == player2.SumCards() && !player1Disqualified && !player2Disqualified) {
			cout << player1.GetName() << " and " << player2.GetName() << " have stayed within the limits and have tied." << endl;
		}

		cout << endl;
		player1.Report();
		player2.Report();
		cout << endl;
	} while (!endGame);

	return 0;
}