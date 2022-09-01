//Evaluation.c - Midterm review on walk-through tables

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 5
#define PASS_GRADE 50

int main(void)
{
	//Midterm marks for five courses
	int midTerm[NUM] = { 23, 34, 41, 33, 40 };
	//Final exam marks for five courses
	int finalExam[NUM] = { 26, 30, 40, 12, 45 };
	int finalMark[NUM] = { 0 };
	int numFailed = 0;
	int numPassed = 0;

	for (int i = 0; i < NUM; ++i) {
		finalMark[i] = midTerm[i] + finalExam[i];
		if (finalMark[i] < PASS_GRADE) {
			++numFailed;
		}
		else {
			++numPassed;
		}
	}

	printf("This student has passed %d course(s) and failed %d course(s).\n", numPassed, numFailed);

	return 0;
}