// Pointers.c : This program demostrates pointers
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>

int main()
{
	int x;
//	int* p = NULL;
	int* p = &x; //p points to the address of x
	//value at p:  *p
	//address of p: p
	printf("Enter x : ");
	scanf_s("%d", &x);//Note we pass the address of x to scanf_s()
	                  //so scanf_s() can change the value there
	printf("Value stored in x : %d\n", x);
	printf("Value stored in *p : %d\n", *p);
	printf("Address of x      : %p\n", &x);
	printf("Address of p      : %p\n", p);
	printf("\n");
	printf("If you change *p you change x, and vice versa.\n");
	printf("Enter a value for *p: ");
	scanf_s("%d", p);//Note that p by itself is already an address
	printf("Value stored in x : %d\n", x);
	printf("Value stored in *p : %d\n", *p);
	printf("Note that the address has not changed:\n");
	printf("Address of x      : %p\n", &x);
	printf("Address of p      : %p\n", p);

	return 0;
}