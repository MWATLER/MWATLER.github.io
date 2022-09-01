// BubbleSort.c - Code that demonstrates bubble sort

//Miguel Watler
//miguel.watler@senecacollege.ca
//123456890
//Section: XXY

#include <stdio.h>

// bubbleSort sorts the elements of a[n] in ascending order 
//
void bubbleSort(int a[], int n)
{
	int i, j;
	int temp;

	//Bubble Sort is the simplest sorting algorithm that works by repeatedly
	//swapping the adjacent elements if they are in wrong order.
	//For an animation, see: http://www.cs.armstrong.edu/liang/animation/web/BubbleSort.html
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int i;
	int sku[] = { 2156, 4633, 3122, 5611 };
	const int n = 4;

	bubbleSort(sku, n);
	for (i = 0; i < n; i++)
		printf("%6d\n", sku[i]);

	return 0;
}