//nhlStats.c - Midterm review on writing full code

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 4
#define MAX_STR 32

struct PlayerInfo {
	char name[MAX_STR];
	int goals;
	int assists;
	int points;
	int games;
	float pointsPerGame;
};
int main(void) {
	struct PlayerInfo player[SIZE] = { 0 };
	float maxPointsPerGame = 0.0;
	int indexMaxPointsPerGame = -1;

//   Name      Games Goals Assists Points
//O'Reilly	    82	  28	 49	     77
//Tarasenko	    76    33	 35	     68
//Schenn	    72	  17	 37	     54
//Perron	    57	  23	 23	     46
//Pietrangelo	71	  13	 28	     41
//Bozak	    	72	  13	 25	     38
	for (int i = 0; i < SIZE; ++i) {
		printf("Enter the player's last name: ");
		scanf("%s", player[i].name);
		printf("Enter the number of goals: ");
		scanf("%d", &player[i].goals);
		printf("Enter the number of assists: ");
		scanf("%d", &player[i].assists);
		printf("Enter the number of games: ");
		scanf("%d", &player[i].games);
		player[i].points = player[i].goals + player[i].assists;
		player[i].pointsPerGame = (float)player[i].points / player[i].games;
		printf("\n");
	}

	for (int i = 0; i < SIZE; ++i) {
		printf("%s played %d games with %d points and %.3f points per game\n", player[i].name, player[i].games, player[i].points, player[i].pointsPerGame);
		maxPointsPerGame = player[0].pointsPerGame;
		indexMaxPointsPerGame = 0;
		if (player[i].pointsPerGame > maxPointsPerGame) {
			maxPointsPerGame = player[i].pointsPerGame;
			indexMaxPointsPerGame = i;
		}
	}
	printf("\n");
	printf("%s has the most points per game with %.3lf\n", player[indexMaxPointsPerGame].name, player[indexMaxPointsPerGame].pointsPerGame);
	
	return 0;
}