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

void CalculatePoints(struct Team* team);
void CalculateWinningPercentage(struct Team* team);
