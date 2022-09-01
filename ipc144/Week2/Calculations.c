// Calculations.c - A simple program to demonstrate calculations

#include <stdio.h>

int main(void)
{

	//The following code calculates the area of a circle
	const float pi = 3.14159f;//The value of "pi" cannot be changed
	float radius=5.0;//The value of "radius" can be changed
	float area = pi * radius * radius;// PI times Radius squared
	printf("The area of a circle with radius %f is %f\n", radius, area);
	int intArea = pi * radius * radius;// PI times Radius squared
	printf("The area (as an int) of a circle with radius %f is %d\n", radius, intArea);

	radius = 10.0;
	area = pi * radius * radius;// PI times Radius squared
	printf("The area of a circle with radius %f is %f\n", radius, area);

	// Let the user enter the radius
	printf("Enter the radius of the circle: ");
	scanf("%f", &radius);//The address of the variable radius is passed to scanf
	area = pi * radius * radius;// PI times Radius squared
	printf("The area of a circle with radius %.2f is %.2f\n", radius, area);

	//The following code calculates how much tax you have to pay
	const float taxRate = 0.316257;//A tax rate of 31.6257%
	float annualIncome;
	float annualTaxes;
	printf("What is your annual income: ");
	scanf("%f", &annualIncome);
	annualTaxes = taxRate * annualIncome;
	printf("With an income of %.2f you pay %.2f in taxes\n",
		annualIncome, annualTaxes);

	//The following code demonstrates the backslash (\) escape sequence
	printf("Welcome to \"The C Programming Language\".\n");

	return 0;
}