//Loops.c - sample loops

#include <stdio.h>

int main(void)
{
	int i;
	int foundFlag = 0;
	for (i = 10; i > 0 && foundFlag==0; --i) {//The preference
		printf("i is %d\n", i);
		if (i == 5) foundFlag = 1;
		//--i occurs at the end of the for-loop
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