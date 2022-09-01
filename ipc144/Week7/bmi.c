//bmi.c - Midterm review question for filling out the code
//        This program asks the user for his/her name, height in meters
//        and weight in kgs. It then calculates the body mass index (bmi)
//        according to the formula: bmi = height/(weight*weight)
//        If the bmi is higher than 30.0, that person is considered obese.
//        
//        To end the program, enter 0 for name. The program then reports
//        how many users there are and how many are obese.

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_STR 32

int main(void)
{
	int numUsers = 0;
	int numObeseUsers = 0;
	char name[MAX_STR];
	float height, weight, bmi;
	int done = 0;

	do {
		printf("Enter the user's name: ");
		scanf("%s", name);
		if (name[0] == '0') {//end the program if '0' is entered
			done = 1;
		}
		else {
			//prompt the user for the height and weight
			printf("Enter %s's height in meters: ", name);
			scanf("%f", &height);
			printf("Enter %s's weight in kg: ", name);
			scanf("%f", &weight);
			bmi = weight / (height * height);//bmi equals the height divided by the weight squared
			if (bmi > 30) {//test for obesity, bmi greater than 30
				printf("%s is obese\n", name);
				++numObeseUsers;//increment the obesity count
			}
			++numUsers;//increment the user count
			printf("\n");
		}
	} while (done == 0);

	printf("There is/are %d users and %d is/are obese\n", numUsers, numObeseUsers);

	return 0;
}