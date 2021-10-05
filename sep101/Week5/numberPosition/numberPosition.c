// numberPosition.c : Demonstrates searching for an integer in an integer array
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

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

int SearchForInt(int theInt, int* theIntArray, int len) {
	                   //88, {11, 22, 33, 44, 55, 66, 77, 88, 99, 100, -1}
	int found = -1;
	int location = -1;
	for (int i = 0; (i < len) && (found == -1); ++i) {
//		if (theInt == *(theIntArray+i)) {//88
		if(theInt==theIntArray[i]){//88
			location = i;
			found = 0;
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
	scanf_s("%d", &seekInt);//88
	int size = 0;
	int done = 0;
	do {
		printf("Enter a number at intArray[%d] (enter negative to quit): ", size);
		scanf_s("%d", &intArray[size]);
		if (intArray[size] < 0) {
			done = 1;
		}
		else {
			++size;
		}
	} while (done == 0 && size<SIZE);
	seekIntIndex = SearchForInt(seekInt, intArray, size);
//	seekIntIndex = SearchForInt(seekInt, &intArray[0]);//same as above

	if (seekIntIndex == -1)
		printf("The number %d appears does not appear in the array\n", seekInt);
	else
		printf("The number %d appears at position %d in the array\n", seekInt, seekIntIndex);

	return 0;
}