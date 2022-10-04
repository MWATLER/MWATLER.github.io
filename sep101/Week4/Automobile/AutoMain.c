//AutoMain.c - main function for automobiles

#include <stdio.h>
#include "Auto.h"

int main() {
	struct Automobile automobile = { 0 };
	/*	struct Automobile {
			char model[MAX_STR];
			char make[MAX_STR];
			int year;
			float price;
		};*/

	printf("What is the make: ");
	scanf_s("%s", automobile.make, MAX_STR);
	printf("What is the model: ");
	scanf_s("%s", automobile.model, MAX_STR);
	printf("What is its year: ");
	scanf_s("%d", &automobile.year);
	printf("What is the price: $");
	scanf_s("%f", &automobile.price);

	printf("The %d %s %s costs $%.2f\n",
		automobile.year, automobile.make, automobile.model, automobile.price);

	return 0;
}