//CalculateTax.c - main program for calculating tax (HST)

#include <stdio.h>

//CalculateTotalPrice - this function calculates the total price based on HST
//
//Input: the price (double)
//Output: the total price (double)
//Returns: error code (0 - no error)
//
//History:
// 09-Feb-22  M. Watler         Created.
//error = CalculateTotalPrice(price, &totalPrice);
int CalculateTotalPrice(double thePrice, double* theTotalPrice) {//thePrice takes on the value of price
	                                               //*theTotalPrice points to the address of totalPrice
	int err = 0;
	double tax = 0.0;
	const double HST = 0.13;
/*	int a = 5;
    int* b = &a;//b points to a
	printf("a is %d, b is %d\n", a, *b);//to get the value at an address that b is pointing to, use *
	                                    //to get the address of b, don't use *
	++(*b);//changes the value of the address b is pointing to, effectively changing the value of a
	printf("a is %d, b is %d\n", a, *b);
*/
	if (thePrice < 0) err = 1;//a negative price is an error
	tax = thePrice * HST;
	*theTotalPrice = thePrice + tax;//whatever I do to *theTotalPrice in CalculateTotalPrice
	                                //I also do to totalPrice in main()
	return err;
}

int main() {
	double price = 0.0;
	double totalPrice = 0.0;//theTotalPrice in CalculateTotalPrice points to the address of totalPrice
	int error = 0;

	printf("Enter the price of your grocery item: $");
	scanf_s("%lf", &price);
	error = CalculateTotalPrice(price, &totalPrice);//the value of price is passed through
	                                                //the address of totalPrice is passed through
	if(error==0)
		printf("Your grocery item with tax costs $%.2lf\n", totalPrice);

	printf("Enter the price of your clothing item: $");
	scanf_s("%lf", &price);
	error = CalculateTotalPrice(price, &totalPrice);
	if(error==0)
		printf("Your clothing item with tax costs $%.2lf\n", totalPrice);

	return 0;
}

