//TicTacToeMain.cpp - main program for tictactoe

#include <iostream>
#include "Grid.h"

using namespace std;

int main() {
	bool validPlay = false;
	int ypos, xpos;
	Grid::Winner winningPlayer = Grid::Winner::NoOne;
	Grid ourGrid;

	int count = 0;
	const int MaxPlays = 9;
	do {
		if (count < MaxPlays && winningPlayer == Grid::Winner::NoOne) {
			ourGrid.DisplayGrid();
			do {
				cout << "Player 1 enter the location of your X (ypos xpos): ";
				cin >> ypos;
				cin >> xpos;
				validPlay = ourGrid.SetGrid(ypos, xpos, 1);
			} while (!validPlay);
			++count;
		}
		winningPlayer = ourGrid.WinningPlayer();

		if (count < MaxPlays && winningPlayer == Grid::Winner::NoOne) {
			ourGrid.DisplayGrid();
			do {
				cout << "Player 2 enter the location of your Y (ypos xpos): ";
				cin >> ypos;
				cin >> xpos;
				validPlay = ourGrid.SetGrid(ypos, xpos, 2);
			} while (!validPlay);
			++count;
		}
		winningPlayer = ourGrid.WinningPlayer();
	} while (winningPlayer == Grid::Winner::NoOne && count<MaxPlays);

	ourGrid.DisplayGrid();
	cout << "The winner is ";
	switch (winningPlayer) {
	case Grid::Winner::NoOne:
		cout << "no one!!" << endl;
		break;
	case Grid::Winner::PlayerOne:
		cout << "player one!!" << endl;
		break;
	case Grid::Winner::PlayerTwo:
		cout << "player two!!" << endl;
		break;
	default:
		cout << "...oops! Oh dear, don't know how we got here..." << endl;
	}
	
	return 0;
}