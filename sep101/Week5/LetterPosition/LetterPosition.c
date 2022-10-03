// LetterPosition.c : Demonstrates searching for a character in a character array
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>

#define SIZE 32

int TestForAlphaNumeric(char c);
//int SearchForChar(char, const char*, int, int*);
int SearchForChar(char theChar, const char theString[], int len, int* location);

int main()
{
	char streamStr[SIZE];//streamStr is actually a pointer to the first value in the char array
	                     //streamStr and &streamStr[0] are actually the same thing
	char seekChar;
	int seekCharIndex = 0;

	printf("Enter a character to search for: ");
	scanf_s("%c", &seekChar);//'c'
	printf("Enter a string: ");
	scanf_s("%s", streamStr, SIZE);//"abcd1234" + null terminator
	int length = strlen(streamStr);//strlen() is from the stdio.h library
	// Look for 'c'   in   "abcd1234"
	int err = SearchForChar(seekChar, streamStr, length, &seekCharIndex);//int *location = &seekCharIndex;

	if (err == -1) {
		printf("The character %c does not appear in %s", seekChar, streamStr);
	}
	else {
		printf("The character %c appears at index %d in %s", seekChar, seekCharIndex, streamStr);
	}

	return 0;
}

//TestForAlphaNumeric - utility function that tests a character against the Ascii table
//
//Parameters:
//  c - a character
//
//Returns: 0 - found
//        -1 - not found
int TestForAlphaNumeric(char c) {
	int found;
	//See Ascii table at https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
	if (c < ' ' || c>'~') {
		found = -1;
	}
	else {
		found = 0;
	}
	return found;
}

//SearchForChar - searches for a character in a character array
//
//Parameters:
//  theChar - the character [IN]
//  theString - the string [IN]
//  len - the length of the string [IN]
//  location - the location [OUT]
//
//Returns: 0 - found
//        -1 - not found
int SearchForChar(char theChar, const char theString[], int len, int* location) {//'c', "abcd1234", 8,
	int result = -1;//status variable
	for (int i = 0; (i < len) && (result == -1); ++i) {
		if (TestForAlphaNumeric(theString[i]) == 0) {
			if (theChar == theString[i]) {//'c'
				*location = i;//seekCharIndex is also equal to i here
				result = 0;
			}
		}
	}
	return result;
}
