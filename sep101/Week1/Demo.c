//Demo.c - A demonstration program

#include <stdio.h>

int main() {
	printf("Hello\n\n");
	int num;

	for (int i = 0; i < 10; ++i) {
		printf("i=%d\n", i);
		num = i / 10.0;
	}

	return 0;
}