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
	float salary;
	int games;
};

int main(void)
{
	struct PlayerInfo player[NUM];//1 mark
	float maxSalary = 0.0;//1 mark
	int highestSalary = 0;//1 mark
	for (int i = 0; i < NUM; ++i) {//1 mark
		printf("Enter the player's name: ");//1 mark
		scanf("%s", player[i].name);//2 mark
		printf("Enter the player's annual salary: $");//1 mark
		scanf("%f", &player[i].salary);//2 mark
		printf("Enter the number of games: ");//1 mark
		scanf("%d", &player[i].games);//2 mark
		if (player[i].salary > maxSalary) {//1 mark
			maxSalary = player[i].salary;//1 mark
			highestSalary = i;//1 mark
		}
		printf("\n");//0.5 mark
	}
	printf("\n");//0.5 mark
	for (int i = 0; i < NUM; ++i) {//1 mark
		float salaryPerGame = player[i].salary / player[i].games;//2 marks
		printf("%s earned $%.2f playing %d games ", player[i].name, player[i].salary, player[i].games);
		printf("for $%.2f per game\n\n", salaryPerGame);//3 marks
	}

	printf("%s earned the highest annual salary: $%.2f\n", player[highestSalary].name, player[highestSalary].salary);//2 marks

	return 0;
}