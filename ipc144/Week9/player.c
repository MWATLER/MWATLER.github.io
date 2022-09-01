//player.c - Main function for player information

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define NUM 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "player.h"

int main(void)
{
	int status=0;
	int i;
	struct PlayerInfo player[NUM];

	//Gather information for all players, checking for valid data along the way
	for (i = 0; i < NUM && status==0; ++i) {
		status = GetName(&player[i].name);//Only need the "struct Name" portion of "struct PlayerInfo"
		if (status == 0) {
			status = GetPosition(player[i].position);//Only need the "position" portion of "struct PlayerInfo"
		}
		if (status == 0) {
			status = GetStats(&player[i]);//Needs all of "struct PlayerInfo"
		}
		printf("\n");
	}

	if (status == 0) {
		//Report on all the players
		for (i = 0; i < NUM; ++i) {
			printf("%s %s plays %s and scored %d goals and %d assists for %d points.\n",
				player[i].name.firstName, player[i].name.lastName, player[i].position,
				player[i].goals, player[i].assists, player[i].points);
		}
	}
	else {
		printf("Error in recording a player's statistics\n");
	}

	return status;
}