//MinorHockey.c - main code for a minor hockey tournament

#define NUM_TEAMS 5
#include <stdio.h>
#include "MinorHockey.h"

int main(void) {
	struct Team team[NUM_TEAMS] = { 0 };

	//User input
	printf("\nPlease enter the team names:\n");
	for(int i = 0; i < NUM_TEAMS; ++i) {
		printf("Team %d: ", i+1);
		scanf_s("%[^\n]s", team[i].name, STR_LEN);//scan to the end of the line
		while (getchar() != '\n');//clear the input buffer ('\n' still remains in the input buffer)
	}

	//Play the tournament
	for (int i = 0; i < NUM_TEAMS; ++i) {
		for (int j = i+1; j < NUM_TEAMS; ++j) {
			//Enter the results for each game
			int goals1, goals2;
			printf("\n%s vs %s:\n", team[i].name, team[j].name);
			printf("Enter the goals for %s: ", team[i].name);
			scanf_s("%d", &goals1);
			printf("Enter the goals for %s: ", team[j].name);
			scanf_s("%d", &goals2);
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