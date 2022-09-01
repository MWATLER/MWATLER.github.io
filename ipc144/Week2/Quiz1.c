//Quiz1.c - Code for quiz 1.

#include <stdio.h>

int main(void)
{
	const int x = 0x14;
	const int y = 18;
	printf("Question 4: x=%d y=%d\n", x, y);

	float length = 5.0;
	float width = 5.0;
	float height = 2.0;
	float volume = length * width * height;
	printf("Question 5: volume = %f\n", volume);

	volume = 326.5;
	printf("Question 6: Volume=%f\n", volume);

	int j = 10;
	int k = 11;
	int l = 12;
	int m = k / j;
	int n = 6 + j * k;
	int p = j / l;
	int q = j % k;
	printf("Question 7: m=%d n=%d p=%d q=%d\n", m, n, p, q);

	return 0;
}