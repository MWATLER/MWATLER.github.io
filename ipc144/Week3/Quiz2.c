//Quiz2.c - Source code for part of Quiz 2

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int age = 35;
	if (age < 18) {
		printf("You are not yet an adult\n");
	}
	else if (age >= 18 && age < 30) {
		printf("You are a young adult\n");
	}
	else {
		printf("You are an adult\n");
	}

	int count=3;
    do {
	    printf("count is %d\n", count);
	    --count;
    } while (count>1);

	for(int i=0; i<3; ++i) {
	    printf("I have gone through this loop %d times\n", i);
    }
/*
	int count=20;
    while(count>0) {//Simply indent the code within the while loop
        --count;
        printf("count is %d\n", count);
    }
*/

	return 0;
}