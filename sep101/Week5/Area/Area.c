// Area.c : Demonstrates pointers and functions
//
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int AreaCircle(double r, double* a);//belongs in a header file along with structure declarations

int main()
{
	double radius;
	double area = 0.0;

	printf("Enter the radius: ");
	scanf_s("%lf", &radius);
	int err = AreaCircle(radius, &area);
	if (err == 0) {
		printf("A circle of radius %.2lf has an area of %.2lf\n", radius, area);
	}
	else {
		printf("Invalid value\n");
	}
	return 0;
}

// AreaCircle - Calculates the area of a circle
//
// double r - the radius[IN]
// double *a - pointer to the area[OUT]
//
// returns: 0 - success
//         -1 - failure
int AreaCircle(double r, double* a) {//double *a = &area;
	int res;
	const double pi = 3.14159;
	if (r < 0) {
		printf("ERROR: Radius less than zero\n");
		res = -1;//Error
	}
	else {
		*a = pi * r * r;//change the value at the address that 'a' points to
		res = 0;//Success
	}
	return res;
}