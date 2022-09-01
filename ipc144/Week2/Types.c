//Types.c - Demonstrates some of the variable types in C
#include <stdio.h>
#include <windows.h>//For the Sleep() function

int main(void)
{

    // The "char" data type
	char letter;
	for (int i = 0; i < 128; ++i) {
		letter = i;
		printf("letter: %3d %c\n", letter, letter);
		Sleep(100);//Sleep for 100ms
	}

	// Negative numbers, the highest bit is the sign bit
	for (int i = 0; i < 256; ++i) {
		letter = i;
		printf("letter: %3d %c\n", letter, letter);
		Sleep(100);//Sleep for 100ms
	}

	// The "unsigned char" data type
	unsigned char letter2;
	for (int i = 0; i < 256; ++i) {
		letter2 = i;
		printf("letter2: %3d %c\n", letter2, letter2);
		Sleep(100);
	}

	// The "short", "int", "long" and "long long" data types
	short num1=1;
	int num2=1;
	long num3=1;
    long long num4=1;

	for (int i = 0; i < 64; ++i) {
		printf("%hd %d %ld %lld\n", num1, num2, num3, num4);
		num1 *= 2;//num1 = num1*2;
		num2 *= 2;//num2 = num2*2;
		num3 *= 2;//num3 = num3*2;
		num4 *= 2;//num4 = num4*2;
		Sleep(100);
	}

	// The "float" and "double" data types
	float num5=1.0;
	double num6=1.0;
	for (int i = 0; i < 256; ++i) {
		printf("%f\n%lf\n\n", num5, num6);
		num5 *= 2;
		num6 *= 2;
		Sleep(100);
	}

	return 0;
}