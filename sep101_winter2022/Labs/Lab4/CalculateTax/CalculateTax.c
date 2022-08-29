//CalculateTax.c - main program for calculating tax (HST)

#include <stdio.h>

double CalculateTotalPrice(double price);//the function prototype tells you how to use the function

int main() {
	double price = 0.0;
	double totalPrice = 0.0;

	printf("Enter the price of your grocery item: $");
	scanf_s("%lf", &price);
	totalPrice = CalculateTotalPrice(price);
	printf("Your grocery item with tax costs $%.2lf\n", totalPrice);

	printf("Enter the price of your clothing item: $");
	scanf_s("%lf", &price);
	totalPrice = CalculateTotalPrice(price);
	printf("Your clothing item with tax costs $%.2lf\n", totalPrice);

	return 0;
}

//CalculateTotalPrice - this function calculates the total price based on HST
//
//Input: the price (double)
//Returns: the total price (double)
//
//History:
// 09-Feb-22  M. Watler         Created.
double CalculateTotalPrice(double thePrice) {//thePrice takes on the value of price
	double tax = 0.0;
	double theTotalPrice = 0.0;
	const double HST = 0.13;

	if (thePrice < 0) thePrice *= -1.0;//thePrice = -1.0*thePrice, convert negative numbers to positive
	tax = thePrice * HST;
	theTotalPrice = thePrice + tax;
	return theTotalPrice;
}