// Swap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

#include <stdio.h>

void internal_swap(int a, int b);//pass by value
void internal_swap_ptr(int* a, int* b);//pass by address

int main()
{
	int a, b;

	printf("a is ");
	scanf_s("%d", &a);//4
	printf("b is ");
	scanf_s("%d", &b);//8

	internal_swap(a, b);//pass the values of a and b to internal_swap()
	//internal_swap(4, 8);
	//a=4, b=8
	printf("main: After internal_swap: a is %d, b is %d\n\n", a, b);

	printf("The addresses of a and b are %p %p\n", &a, &b);
	internal_swap_ptr(&a, &b);//pass the addresses of a and b to internal_swap_ptr()
	//a=8, b=4
	printf("main: After internal_swap_ptr: a is %d,  b is %d\n\n", a, b);

	return 0;
}

void internal_swap(int e, int f)//e=4, f=8
{
	int c;

	printf("internal_swap: before:     e is %d, f is %d\n", e, f);

	c = e;
	e = f;
	f = c;
	//e=8, f=4
	printf("internal_swap: after:      e is %d, f is %d\n", e, f);
}

void internal_swap_ptr(int* e, int* f)//int *e=&a, int *f=&b
//e is pointing to the address of a, and
//f is pointing to the address of b
{
	int c;
	printf("internal_swap_ptr: The addresses of e and f are %p %p\n", e, f);

	printf("internal_swap_ptr: before:    *e is %d, *f is %d\n", *e, *f);

	c = *e;
	*e = *f;
	*f = c;
	//*e=8, *f=4
	printf("internal_swap_ptr: after:     *e is %d, *f is %d\n", *e, *f);
}