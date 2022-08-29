//Grid.h - grid for tictactoe

#ifndef _GRID_H_
#define _GRID_H_

class Grid {
	char grid[3][3] = {
		' ', ' ', ' ',  //row 1, cols 1-3
		' ', ' ', ' ',  //row 2, cols 1-3
		' ', ' ', ' '   //row 3, cols 1-3
	};
public:
	enum class Winner {
		NoOne,
		PlayerOne,
		PlayerTwo
	};
	void DisplayGrid();
	bool SetGrid(int ypos, int xpos, int playerNo);
	Winner WinningPlayer();
};

#endif _GRID_H_
