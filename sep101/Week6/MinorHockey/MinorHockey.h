//MinorHockey.h - header file for a minor hockey tournament

#define STR_LEN 32

struct Team {
	char name[STR_LEN];
	int  gamesPlayed;
	int  wins;
	int  losses;
	int  ties;
	int  points;
	float winningPercentage;
};

void CalculatePoints(struct Team* team);//pass by address
void CalculateWinningPercentage(struct Team* team);//pass by address
/*We want to write software that generates the standings for a minor hockey tournament. 
There are five teams and each team will play four games, playing each other once. The 
team with the most points at the end of the tournament wins. If two teams are tied with 
the most points, those teams will play each other again.

For each team, the team name, games played, the wins, losses, ties, points and winning 
percentage will be tracked. The points will be generated from the wins (2 points for a win) 
and ties (1 point for a tie). The winning percentage will be points divided by maximum 
possible points (2 times games played) times 100%.

The user will be prompted to enter the score for each game by entering the name and goals 
of the first team, then the name and goals of the second team. */