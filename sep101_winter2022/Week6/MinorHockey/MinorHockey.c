//MinorHockey.c - main code for a minor hockey tournament

#define _CRT_SECURE_NO_WARNINGS
#define NUM_TEAMS 5
#include <stdio.h>
#include "MinorHockey.h"

int main(void) {
	struct Team team[NUM_TEAMS] = { 0 };

	//User input
	printf("\nPlease enter the team names:\n");
	for(int i = 0; i < NUM_TEAMS; ++i) {
		printf("Team %d: ", i+1);
		scanf("%[^\n]s", team[i].name);//scan to the end of the line
		while (getchar() != '\n');//clear the input buffer ('\n' still remains in the input buffer)
	}

	//Play the tournament
	for (int i = 0; i < NUM_TEAMS; ++i) {
		for (int j = i+1; j < NUM_TEAMS; ++j) {
			//Enter the results for each game
			int goals1, goals2;
			printf("\n%s vs %s:\n", team[i].name, team[j].name);
			printf("Enter the goals for %s: ", team[i].name);
			scanf("%d", &goals1);
			printf("Enter the goals for %s: ", team[j].name);
			scanf("%d", &goals2);
			//Update team statistics
			++team[i].gamesPlayed;
			++team[j].gamesPlayed;
			if (goals1 > goals2) {
				++team[i].wins;
			}
			else if (goals1 == goals2) {
				++team[i].ties;
				++team[j].ties;
			}
			else {
				++team[j].wins;
			}
		}
	}

	//Calculate the points and winning percentage for each team
	//Keep track of which team has the most points
	int mostPoints = 0;
	int mostPointsIndex = 0;
	for (int i = 0; i < NUM_TEAMS; ++i) {
		CalculatePoints(&team[i]);
		CalculateWinningPercentage(&team[i]);
		if (team[i].points > mostPoints) {
			mostPoints = team[i].points;
			mostPointsIndex = i;
		}
	}

	//Report the winner of the tournament
	printf("%s has won the tournament with %d points and a winning percentage of %.2f",
		team[mostPointsIndex].name, team[mostPointsIndex].points, team[mostPointsIndex].winningPercentage);
}
void CalculatePoints(struct Team* team) {
	team->points = 2 * team->wins + team->ties;
}
void CalculateWinningPercentage(struct Team* team) {
	int maxPoints = 2 * team->gamesPlayed;
	if (maxPoints > 0) {
		team->winningPercentage = (float)100.0 * team->points / maxPoints;
	}
	else {
		team->winningPercentage = 0.0;
	}
}

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