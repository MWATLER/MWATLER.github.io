//Lab1Sample.c - sample code for lab1
//
// 16-Sep-21  M. Watler         Created.

/*
This is a multi-line comment

*/

//This is a single line comment

#include <stdio.h>//include the standard C input/output library

int main() {
	float price1 = 1.00;
	float price2 = 1.00;
	float price3 = 2.99;//2.99000001
	float total_cost = price1 + price2 + price3;//4.99
	//On my visual studio, total_cost is actually 4.98999977
	//float's and double's introduce a slight error
	//This has to be compensated for when converting to an int
//	int remainder = total_cost * 100;//498.999977 -> 498, wrong!
	int remainder = total_cost * 100 + 0.0001;//499.000077 -> 499, correct!
	int numQuarters;

	printf("The total cost as a float is $%.2f\n", total_cost);
	printf("the total cost in cents as an integer is %d\n\n", remainder);

	numQuarters = remainder / 25;//25 pennies in one quarter
	                             //499/25=19.96 -> 19 quarters
	remainder = remainder % 25;//499%25=19 rem 24 -> remainder becomes 24

	// 499 / 25 = 19 rem 24, 19*25 + 24 = 475 + 24 = 499

	printf("You used %d quarters with a remainder of %d\n", 
		numQuarters, remainder);

	return 0;
}