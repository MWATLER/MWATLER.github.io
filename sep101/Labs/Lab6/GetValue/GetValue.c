//GetValue.c - main function for getting values from the keyboard

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void clearKeyboard(void) {
	while (getchar() != '\n');
}

void pause(void) {
	printf("(Press Enter to continue)");
	clearKeyboard();
}

int getInt(void)
{
	int val;
	int rc = 0;
	char nextChar = '\n';
	do {
		rc = scanf("%d%c", &val, &nextChar);
		if (rc == 0 || nextChar != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (rc == 0 || nextChar != '\n');
	return val;
}

double getDouble(void) {
	double val;
	int rc = 0;
	char nextChar = '\n';
	do {
		rc = scanf("%lf%c", &val, &nextChar);
		if (rc == 0 || nextChar != '\n') {
			clearKeyboard();
			printf("*** INVALID DOUBLE *** <Please enter a double>: ");
		}
	} while (rc == 0 || nextChar != '\n');
	return val;
}

int main() {
	int intVal = 0;
	double doubleVal = 0.0;

	do {
		printf("Enter an integer value (-99 to quit): ");
		intVal = getInt();
		if (intVal != -99) {
			printf("Enter a double value (-99 to quit): ");
			doubleVal = getDouble();
		}
		pause();
	} while (intVal != -99 && doubleVal != -99.0);

	return 0;
}