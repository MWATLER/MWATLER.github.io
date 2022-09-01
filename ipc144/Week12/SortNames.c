// SortNames.c : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define USEMASK 1

int findName(char *search, char name[][30], int n);
int BubbleSortName(char name[][30], int n);

int main()
{
	char name[5][30];
	const int num = 5;

	printf("Enter five first names:\n");
	for (int i = 0; i < num; ++i) {
		printf("Name %d: ", i+1);
		scanf("%s", name[i]);
	}

	printf("\nThe names entered are:\n");
	for (int i = 0; i < num; ++i) printf("  %s\n", name[i]);

	char searchName[30];
	printf("\nEnter a name to search for: ");
	scanf("%s", searchName);
	int index = findName(searchName, name, num);

	if (index == -1) printf("%s not found\n", searchName);
	else             printf("%s appears at index %d\n", searchName, index);

	printf("\n");
	int error = BubbleSortName(name, num);

	if (error == -1) printf("Problem with sorting the names\n");
	else {
		printf("The sorted names are:\n");
		for (int i = 0; i < num; ++i) printf("  %s\n", name[i]);
	}
    return 0; 
}

int findName(char *search, char name[][30], int n) {
	int found = 0;
	int index = -1;
	for (int i = 0; i < n && found == 0; ++i) {
		if (strcmp(search, name[i]) == 0) {//&name[i][30]
			found = 1;
			index = i;
		}
	}
	return index;
}

int BubbleSortName(char name[][30], int n) {//Sort lowest to highest
	int retVal = -1;
	char temp[30];
	for (int i = n - 1; i > 0; i--) {//for(i=4; i>0; ++i)
		for (int j = 0; j < i; j++) {//for(j=0; j<i; ++j)
			if (strcmp(name[j], name[j+1]) > 0) {//if(name[0]>name[1]) swap places
				strcpy(temp, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], temp);
			}
		}
		retVal = 0;
	}
	return retVal;
}
