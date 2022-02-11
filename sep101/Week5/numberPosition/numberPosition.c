// numberPosition.c : Demonstrates searching for an integer in an integer array
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 32

//SearchForInt - searches for an integer in an integer
//
//Parameters:
//  theInt - the integer
//  theIntArray - the integer array
//
//Returns: location, or
//        -1 - not found
int SearchForInt(int theInt, const int theIntArray[], int len) {//88, {11, 22, 33, 44, 55, 66, 77, 88, 99, 100, -1}
	int found = 0;
	int location = -1;
	for (int i = 0; (i < len) && (found == 0); ++i) {
		if (theInt == theIntArray[i]) {//88
			location = i;
			found = 1;
		}
	}
	return location;
}

int main()
{
	int intArray[SIZE];
	int seekInt;
	int seekIntIndex;

	printf("Enter a number to search for: ");
	scanf("%d", &seekInt);//88
	int size = 0;
	int done = 0;
	do {
		printf("Enter a number at intArray[%d] (enter negative to quit): ", size);
		scanf("%d", &intArray[size]);
		if (intArray[size] < 0) {
			done = 1;
		}
		else {
			++size;
		}
	} while (done == 0 && size < SIZE);
	//Let's say intArray is {11, 22, 33, 44, 55, 66, 77, 88, 99, 100}
	//then size should be 8
	seekIntIndex = SearchForInt(seekInt, intArray, size);
//	seekIntIndex = SearchForInt(seekInt, &intArray[0]);//same as above

	if (seekIntIndex == -1)
		printf("The number %d appears does not appear in the array\n", seekInt);
	else
		printf("The number %d appears at index %d in the array\n", seekInt, seekIntIndex);

	return 0;
}