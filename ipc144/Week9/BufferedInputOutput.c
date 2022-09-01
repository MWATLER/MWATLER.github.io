// BufferedInputOutput.c : This file contains the 'main' function. Program execution begins and ends here.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void clear(void);
void pause(char key);
int IsWorkingAge(int min, int max);

int main()
{
	char firstName[41];
	char lastName[41];
	char title[11];
	char entry;
	printf("Enter your full name: ");
	int ret = scanf(" %40s %40s", firstName, lastName);
	//	printf("ret=%d\n", ret);
	//	scanf(" %40[^\n]", name);
	printf("Do you want to enter a title such as Mr/Mrs/Dr/Sir/... (y/n)?: ");

	clear();//If this is removed, getchar() will return '\n' before the user can enter anything
	entry = getchar();
	if (entry == 'y' || entry == 'Y') {
		printf("Enter your title: ");
		scanf(" %10[^\n]", title);
		printf("Your full name is %s %s %s\n", title, firstName, lastName);
	}
	else {
		printf("Your full name is %s %s\n", firstName, lastName);
	}

	clear();
	printf("Press <Enter> to continue: ");
	pause('\n');

	int numItems;
	float priceItem;
	char after;
	printf("Enter the number of items and the price of each item: ");
	ret = scanf("%d %f", &numItems, &priceItem);

	printf("scanf() filled %d values\n", ret);
	printf("%s %s bought %d items for $%.2f total\n", firstName, lastName, numItems, numItems * priceItem);

	// 	printf("Press enter to continue: ");
	printf("Press 'c' to continue: ");
	pause('c');
	int valid = IsWorkingAge(16, 65);
	if (valid == 0)   printf("%s %s is not of working age\n", firstName, lastName);
	else if (valid == 1) printf("%s %s is of working age\n", firstName, lastName);
	return 0;
}

void clear(void)
{
	char entry;
	do {
		entry = getchar();
		//		printf("clear:%d 0x%x\n", entry, entry);
	} while (entry != '\n');
}

void pause(char key)//pause('c'), pause('\n')
{
	char entry;
	do {
		entry = getchar();

	} while (entry != key);//key='c',key='\n'
}

int IsWorkingAge(int min, int max)
{
	int age;
	int validData = -1;
	int rc;
	char after;
	do {
		printf("Enter your age: ");
		rc = scanf("%d%c", &age, &after);//fifteen
		if (rc == 0) {
			printf("Bad character(s)\n");
			do {//clear the buffer
				after = getchar();
				printf("after:%c %d 0x%x\n", after, after, after);
			} while (after != '\n');
		}
		else if (after != '\n') {
			printf("Trailing characters\n");
		}
		else if (age<min || age>max) {
			printf("Not working age\n");
			validData = 0;
		}
		else {
			validData = 1;
		}
	} while (validData == -1);

	return validData;
}
