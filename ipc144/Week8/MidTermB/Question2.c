//Question2.c - Source code for Part B of the MidTerm

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#define LEN 20
#include <stdio.h>

int main(void)
{
	int birthYear;//The year of birth
	float birthWeight;//in kilograms
	char lastName[LEN];//The last name
	int numEntries = 0;//The number of entries
	int numInvalidEntries = 0;//The number of invalid entries
	int endCensus = 0;//The end census flag

	do {
		printf("Enter the last name of the new-born: ");
		scanf("%s", lastName);//3 marks
		if (lastName[0] == '0') {//End the census if '0' is entered, 2 marks
			endCensus = 1;
		}
		else {
			//Prompt for the birth year and the birth weight
			printf("%s's birth year: ", lastName);//3 marks
			scanf("%d", &birthYear);//2 marks
			printf("%s's birth weight: ", lastName);//3 marks
			scanf("%f", &birthWeight);//2 marks
			if (birthYear > 2019 || birthWeight < 0) {//Validity test, 3 marks
				printf("Invalid census data noted, please continue\n");
				//Increment the number of invalid entries
				++numInvalidEntries;//1 mark
			}
			++numEntries;//Increment the number of entries, 1 mark
		}
		printf("\n");
	} while (endCensus == 0);//2 marks

	printf("I have received %d invalid entry(entries) and %d entry(entries) in total.\n", numInvalidEntries, numEntries);//4 marks

	return 0;
}