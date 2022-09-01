// SelectSort.c - Code that demonstrates selection sort

// Miguel Watler
// miguel.watler@senecacollege.ca
// 1234567890
// Section XXY

#include <stdio.h>

// selectSort sorts the elements of a[n] in ascending order
//
void selectSort(int a[], int n)
{
	int i, j, minIndex;
	int temp;

	//The selection sort algorithm sorts an array by repeatedly finding the minimum element
	//(considering ascending order) from unsorted part and putting it at the beginning.
	//The algorithm maintains two subarrays in a given array.
	//	1) The subarray which is already sorted.
	//	2) Remaining subarray which is unsorted.

	//In every iteration of selection sort, the minimum element (considering ascending order)
	//from the unsorted subarray is picked and moved to the sorted subarray.

	//For an animation see: http://www.cs.armstrong.edu/liang/animation/web/SelectionSort.html

	for (i = 0; i < n; i++) {
		minIndex = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			temp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = temp;
		}
	}
}

int main(void)
{
	int i;
	int sku[] = { 2156, 4633, 3122, 5611 };
	const int n = 4;

	selectSort(sku, n);
	for (i = 0; i < n; i++)
		printf("%6d\n", sku[i]);

	return 0;
}