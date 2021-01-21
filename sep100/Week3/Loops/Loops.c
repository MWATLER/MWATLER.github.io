//Loops.c - sample loops

#include <stdio.h>

int main(void)
{
	int i;
	for (i = 10; i > 0; --i) {//The preference
		printf("i is %d\n", i);
	}
	printf("\n");

	i = 10;//initialization
	while (i > 0) {//test
		printf("i is %d\n", i);
		--i;//operation on the control variable
	}
	printf("\n");

	i = 10;//initialization
	do {
		printf("i is %d\n", i);
		--i;
	} while (i > 0);//test
	return 0;
}