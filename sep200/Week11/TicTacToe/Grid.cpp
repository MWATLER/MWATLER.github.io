//Grid.cpp - function definitions for a grid

#include <iostream>
#include <stdlib.h>
#include "Grid.h"

using namespace std;

void Grid::DisplayGrid() {
	system("cls");
	cout << "   TIC TAC TOE" << endl << endl;
	for (int y = 0; y < 5; ++y) {//y==0 first row
								 //y==1 line
								 //y==2 second row
								 //y==3 line
								 //y==4 third row
		int yPos = y / 2;
		if (y % 2 == 1) {
			cout << "------------------" << endl;
		}
		else {
			for (int x = 0; x < 17; ++x) {
				switch (x) {
				case 0:
				case 1://fall-through
					cout<<" ";
					break;
				case 2:
					cout << grid[yPos][0];
					break;
				case 3:
				case 4://fall-through
					cout << " ";
					break;
				case 5:
					cout << "|";
					break;
				case 6:
				case 7://fall-through
					cout << " ";
					break;
				case 8:
					cout << grid[yPos][1];
					break;
				case 9:
				case 10://fall-through
					cout << " ";
					break;
				case 11:
					cout << "|";
					break;
				case 12:
				case 13://fall-through
					cout << " ";
					break;
				case 14:
					cout << grid[yPos][2];
					break;
				case 15:
					cout << " ";
					break;
				case 16://fall-through
					cout << " " << endl;
					break;
				default:
					break;
				}//switch bracket
			}//for loop
		}//if bracket
	}//for loop
	cout << endl << endl;
}

bool Grid::SetGrid(int ypos, int xpos, int playerNo) {
	bool ret = true;
	char play;

	if (grid[ypos][xpos] != ' ') {
		ret = false;
	}
	else {
		if (playerNo == 1) {
			play = 'X';
		}
		else if (playerNo == 2) {
			play = 'Y';
		}
		else {
			ret = false;
		}
	}
	if (ret) {
		grid[ypos][xpos] = play;
	}
	return ret;
}

Grid::Winner Grid::WinningPlayer() {
	Grid::Winner winningPlayer = Winner::NoOne;

	//Test each row
	for (int y = 0; y < 3 && winningPlayer == Winner::NoOne; ++y) {
		//Test for all X's
		if (grid[y][0] == 'X' &&
			grid[y][1] == 'X' &&
			grid[y][2] == 'X') winningPlayer = Winner::PlayerOne;
		//Test for all O's
		else if (grid[y][0] == 'O' &&
			grid[y][1] == 'O' &&
			grid[y][2] == 'O') winningPlayer = Winner::PlayerTwo;
	}
	//Test each column
	for (int x = 0; x < 3 && winningPlayer == Winner::NoOne; ++x) {
		//Test for all X's
		if (grid[0][x] == 'X' &&
			grid[1][x] == 'X' &&
			grid[2][x] == 'X') winningPlayer = Winner::PlayerOne;
		//Test for all O's
		else if (grid[0][x] == 'O' &&
			grid[1][x] == 'O' &&
			grid[2][x] == 'O') winningPlayer = Winner::PlayerTwo;
	}
	//Test the diagonals
	//Test for all X's
	if (grid[0][0] == 'X' &&
		grid[1][1] == 'X' &&
		grid[2][2] == 'X') winningPlayer = Winner::PlayerOne;
	else if (grid[0][2] == 'X' &&
		grid[1][1] == 'X' &&
		grid[2][0] == 'X') winningPlayer = Winner::PlayerOne;
	//Test for all O's
	else if (grid[0][0] == 'O' &&
		grid[1][1] == 'O' &&
		grid[2][2] == 'O') winningPlayer = Winner::PlayerTwo;
	else if (grid[0][2] == 'O' &&
		grid[1][1] == 'O' &&
		grid[2][0] == 'O') winningPlayer = Winner::PlayerTwo;

	return winningPlayer;
}