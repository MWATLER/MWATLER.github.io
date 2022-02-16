//InputBuffer.c - main program to demonstrate frustrations with the input buffer

#include <stdio.h>
#define MAX_STR 32

void utilClearInputBuffer(void);

int main() {
	char name[MAX_STR];
	char address[MAX_STR];
	int age;

	for (int i = 0; i < 2; ++i) {
		printf("Enter your name: ");//I will enter "Miguel Watler\n"
		scanf_s("%[^\n]s", name, MAX_STR);//I want to scan an entire line
		utilClearInputBuffer();//I need to clear out the '\n' for the next scanf_s which expects a character array
		printf("Enter your address: ");
		scanf_s("%[^\n]s", address, MAX_STR);//I want to scan an entire line
		utilClearInputBuffer();//not necessary, the '\n' does not affect an int
		printf("Enter your age: ");
		scanf_s("%d", &age);
		utilClearInputBuffer();//inside a loop this is necessary because the next scanf_s expects a character array

		printf("%s lives at %s and is %d years old.\n", name, address, age);
	}
	return 0;
}

void utilClearInputBuffer(void) {
//	while (getchar() != '\n');
	char c;
	do {
		c = getchar();//gets one character from the input buffer
	} while (c != '\n');
}