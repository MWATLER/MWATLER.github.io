//playerHelper.c - Function definitions for player information

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>//for strlen()
#include "player.h"

//GetName - prompt the user for the player's name
//IN: name - pointer to a struct Name
//
//OUT: status - 0: no error
//             -1: error
int GetName(struct Name* name)
{//struct Name *name = &player[i].name;
	int status;

	printf("Enter the user's first name: ");
	scanf(" %32[^\n]", name->firstName);//Space empties the scanf() buffer.
	                                    //scan up to 32 characters or to the end of a line
	printf("Enter the user's last name: ");
	scanf(" %32[^\n]", name->lastName);

	//Validation tests
	if (strlen(name->firstName)==0) {
		printf("Lacking the first name");
		status = -1;
	}
	else if (strlen(name->lastName) == 0) {
		printf("Lacking the last name");
		status = -1;
	}
	else {
		status = 0;
	}

	return status;
}

//GetPosition - prompt the user for the player's position
//IN: pos - pointer to a character array containing the player's position
//
//OUT: status - 0: no error
//             -1: error
int GetPosition(char* pos)
{//char *pos = player[i].position;//position is an array, so the apersand '&' is not needed
	int status;

	printf("Enter the player's position: ");
	scanf(" %16[^\n]", pos);

	//Validation test
	if (strlen(pos) == 0) {
		printf("No position entered.\n");
		status = -1;
	}
	else {
		status = 0;
	}

	return status;
}

//GetStats - prompt the user for the player's statistics
//IN: player - pointer to a struct PlayerInfo
//
//OUT: 0: no error
int GetStats(struct PlayerInfo* player)
{//struct PlayerInfo *player = &player[i];
	printf("Enter the player's goals: ");
	scanf("%d", &player->goals);
	printf("Enter the player's assists: ");
	scanf("%d", &player->assists);
	player->points = player->goals + player->assists;

	return 0;
}