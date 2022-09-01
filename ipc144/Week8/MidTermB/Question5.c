//Question5.c - Source code for Part E of the MidTerm.

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define NUM 3//1 mark
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>//1 mark

struct PlayerInfo {//3 marks
	char name[21];
	int points;
	int games;
};

int main(void)
{
	struct PlayerInfo player[NUM];//1 mark
	int maxPoints = 0.0;//1 mark
	int indexMaxPoints = 0;//1 mark
	for (int i = 0; i < NUM; ++i) {//1 mark
		printf("Enter the player's name: ");//1 mark
		scanf("%s", player[i].name);//2 marks
		printf("Enter the number of points: ");//1 mark
		scanf("%d", &player[i].points);//2 marks
		printf("Enter the number of games: ");//1 mark
		scanf("%d", &player[i].games);//2 marks
		if (player[i].points > maxPoints) {//1 mark
			maxPoints = player[i].points;//1 mark
			indexMaxPoints = i;//1 mark
		}
		printf("\n");//0.5 mark
	}
	printf("\n");//0.5 mark
	for (int i = 0; i < NUM; ++i) {//1 mark
		float pointsPerGame = (float)player[i].points / player[i].games;//2 marks
		printf("%s had %d points playing %d games ", player[i].name, player[i].points, player[i].games);
		printf("for %.2f per game\n\n", pointsPerGame);//3 marks
	}

	printf("%s had the highest number of points: %d\n", player[indexMaxPoints].name, player[indexMaxPoints].points);//2 marks

	return 0;
}