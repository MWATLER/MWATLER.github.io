// FileRecord.c : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Tabular Data
 // table.c

#include <stdio.h>

int main(void)
{
	FILE *fp = NULL;
	char label[14];
	int n;
	double price;

	char firstName[31];
	char enterMiddleInitial;
	char middleInitial[7];

	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", firstName);
//	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%c", &enterMiddleInitial);
	if (enterMiddleInitial == 'y' || enterMiddleInitial=='Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", middleInitial);
//		clearKeyboard();
	}

	printf("\nType 'c' to continue: ");
	while (getchar() != 'c');
	while (getchar() != '\n');//Clear the input buffer

	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]%*c", firstName);//%*c means discard the next characters
//	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%c%*c", &enterMiddleInitial);//%*c means discard the next characters
	if (enterMiddleInitial == 'y' || enterMiddleInitial == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]%*c", middleInitial);
//		clearKeyboard();
	}

	fp = fopen("spring.txt", "r");
	if (fp != NULL) {
		printf("    Spring Items\n");
		printf("    ============\n\n");
		printf("No Description  Price\n");
		printf("---------------------\n");
		int ret;
		do {
			ret = fscanf(fp, "%d;%13[^;];%lf%*c", &n, label, &price);//%*c means discard the next characters
 			if (ret==3) printf("%2d %-13s%5.2lf\n",	n, label, price);
		} while (ret == 3);
		fclose(fp);
	}

	printf("\nType 'c' to continue: ");
	while (getchar() != 'c');

	fp = fopen("spring.txt", "r");
	if (fp != NULL) {
		printf("    Spring Items\n"
			   "    ============\n\n"
			   "No Description  Price\n"
			   "---------------------\n");
		int ret;
		char c;
		do {
			ret = fscanf(fp, "%d;%13[^;]%c", &n, label, &c);
			if (c == ';') fscanf(fp, "%lf\n", &price);//Guard against memory overflow
			else fscanf(fp,	"%*[^;];%lf%*c", &price);//%*c means discard the next characters
			if(ret==3) printf("%2d %-13s%5.2lf\n",	n, label, price);
		} while (ret == 3);
		fclose(fp);
	}

	return 0;
}