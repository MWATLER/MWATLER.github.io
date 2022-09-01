// Logic.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890

#define _CRT_SECURE_NO_WARNINGS//Get rid of warnings connected with scanf()
#include <stdio.h>

int main()
{
	float guess1, guess2, guess3;//A variable for each guess

	printf("Guess the price of a brand new Buick Regal without going over.\n");
	printf("Contestant 1 what is your guess: ");
	scanf("%f", &guess1);
	printf("Contestant 2 what is your guess: ");
	scanf("%f", &guess2);
	printf("Contestant 3 what is your guess: ");
	scanf("%f", &guess3);

	const float price = 51913.76;//Taxes and delivery included
	float diff;//The difference between the guess and the price
	float smallestDiff = price;//Have a variable representing the closest guess
	int bestContestant = -1;//Have a variable representing the contestant with the closest guess.
	                        //Set the default value to something ridiculous
	if (guess1 <= price) {
		diff = price - guess1;
		smallestDiff = diff;
		bestContestant = 1;
		printf("Contestant 1 you were within %.2f of the real price\n", diff);
	}
	else {
		printf("Contestant 1 you guessed over the real price\n");
	}

	if (guess2 <= price) {
		diff = price - guess2;
		if (diff < smallestDiff) {
			smallestDiff = diff;
			bestContestant = 2;
		}
		printf("Contestant 2 you were within %.2f of the real price\n", diff);
	}
	else {
		printf("Contestant 2 you guessed over the real price\n");
	}

	if (guess3 <= price) {
		diff = price - guess3;
		if (diff < smallestDiff) {
			smallestDiff = diff;
			bestContestant = 3;
		}
		printf("Contestant 3 you were within %.2f of the real price\n", diff);
	}
	else {
		printf("Contestant 3 you guessed over the real price\n");
	}

	if (bestContestant > 0)
		printf("Contestant %d was the closest without going over.\n", bestContestant);
	else//Corner case: everyone guessed above the price
		printf("All contestants guessed above the price.\n");

	if (guess1 <= price && guess2 <= price && guess3 <= price) {
		printf("None of the contestants went above the price.\n");
    }
	return 0;
}
