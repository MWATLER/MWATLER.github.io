// TicTacToeHelper.c: Helper files for the TicTacToe application
//
// 27-Nov-18  M. Watler         Created.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "TicTacToeHelper.h"

// DisplayGrid: Displays the TIC TAC TOE grid
//
// Parameters: IN: grid[][] - two dimensional array of the grid
//
// Returns: nothing.
//
// 27-Nov-18  M. Watler         Created.
void DisplayGrid(char grid[][3]) {
	system("cls");
	printf("TIC TAC TOE\n\n");
	for (int y = 0; y < 5; ++y) {//y==0 first row
								 //y==1 line
								 //y==2 second row
								 //y==3 line
								 //y==4 third row
		int yPos = y / 2;
		if (y % 2 == 1) {
			printf("------------------\n");
		}
		else {
			for (int x = 0; x < 17; ++x) {
				switch (x) {
				case 0:
				case 1://fall-through
					printf(" ");
					break;
				case 2:
					printf("%c", grid[yPos][0]);
					break;
				case 3:
				case 4://fall-through
					printf(" ");
					break;
				case 5:
					printf("|");
					break;
				case 6:
				case 7://fall-through
					printf(" ");
					break;
				case 8:
					printf("%c", grid[yPos][1]);
					break;
				case 9:
				case 10://fall-through
					printf(" ");
					break;
				case 11:
					printf("|");
					break;
				case 12:
				case 13://fall-through
					printf(" ");
					break;
				case 14:
					printf("%c", grid[yPos][2]);
					break;
				case 15:
					printf(" ");
					break;
				case 16://fall-through
					printf(" \n");
					break;
				default:
					break;
				}//switch bracket
			}//for loop
		}//if bracket
	}//for loop
	printf("\n\n");
}

// WinningPlayer: Determines the winning player.
//
// Parameters: IN: grid[][] - two dimensional array of the grid
//
// Returns: the winning player, or -1 otherwise.
//
// 27-Nov-18  M. Watler         Created.
int WinningPlayer(char grid[][3]) {
	int winningPlayer = -1;

	//Test each row
	for (int y = 0; y < 3 && winningPlayer == -1; ++y) {
		//Test for all X's
		if (grid[y][0] == 'X' &&
			grid[y][1] == 'X' &&
			grid[y][2] == 'X') winningPlayer = 1;
		//Test for all O's
		else if (grid[y][0] == 'O' &&
			     grid[y][1] == 'O' &&
			     grid[y][2] == 'O') winningPlayer = 2;
	}
	//Test each column
	for (int x = 0; x < 3 && winningPlayer == -1; ++x) {
		//Test for all X's
		if (grid[0][x] == 'X' &&
			grid[1][x] == 'X' &&
			grid[2][x] == 'X') winningPlayer = 1;
		//Test for all O's
		else if (grid[0][x] == 'O' &&
			     grid[1][x] == 'O' &&
			     grid[2][x] == 'O') winningPlayer = 2;
	}
	//Test the diagonals
	//Test for all X's
	if (grid[0][0] == 'X' &&
		grid[1][1] == 'X' &&
		grid[2][2] == 'X') winningPlayer = 1;
	else if (grid[0][2] == 'X' &&
		grid[1][1] == 'X' &&
		grid[2][0] == 'X') winningPlayer = 1;
	//Test for all Y's
	else if (grid[0][0] == 'Y' &&
		grid[1][1] == 'Y' &&
		grid[2][2] == 'Y') winningPlayer = 2;
	else if (grid[0][2] == 'Y' &&
		grid[1][1] == 'Y' &&
		grid[2][0] == 'Y') winningPlayer = 2;

	return winningPlayer;
}