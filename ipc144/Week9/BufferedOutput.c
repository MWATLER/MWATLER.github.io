// BufferedOutput.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#define NUM_SUBJECTS 5
#include <stdio.h>

void pause(void);

int main()
{
	struct Marks {
		double score;
		double total;
		double percent;
	};

	struct Marks mark[NUM_SUBJECTS] = { 44, 50, 0,
										55, 60, 0,
										35, 40, 0,
										53, 60, 0,
										61, 70, 0 };

	for (int i = 0; i < NUM_SUBJECTS; ++i) {
		mark[i].percent = 100 * mark[i].score / mark[i].total;
	}
	for (int i = 0; i < NUM_SUBJECTS; ++i) {
		printf("mark %d: score:%lf total:%lf percent:%.2lf%%\n", i + 1, mark[i].score, mark[i].total, mark[i].percent);
	}
	printf("\n");
	printf("MARK   SCORE    TOTAL    PERCENT\n");
	for (int i = 0; i < NUM_SUBJECTS; ++i) {//TODO: Fix the formatting
		printf("%4d %7.2lf %8.2lf %10.2lf\n", i + 1, mark[i].score,
			mark[i].total, mark[i].percent);
	}

	pause();
	printf("\n");

	char tvQuote[] = " It's not pining, it's passed on! This parrot is no more!\n It has ceased to be! \
It's expired and gone to meet its maker!\n This is a late parrot! It's a stiff! \
Bereft of life,\n it rests in peace! If you hadn't nailed it to the perch,\n \
it would be pushing up the daisies!\n It's rung down the curtain and joined \
the choir invisible.\n This is an ex-parrot!";
	int i = 0;
	for (i = 0; tvQuote[i] != '\0'; ++i) {
		//	while(tvQuote[i] != '\0') {
		char upperCase = toupper(tvQuote[i]);
		putchar(upperCase);
		//		++i;
	}
	printf("\n\n");
	printf("tvQuote is %d characters long\n", i);
	int len = strlen(tvQuote);//strlen() does not include the null terminator
	printf("Using strlen() tvQuote is %d characters long\n", i);
	return 0;
}

void pause(void) {
	char entry;
	printf("Press 'c' to continue: ");
	do {
		entry = getchar();
	} while (entry != 'c');

}
