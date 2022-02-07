//Petstore.c - main program for the petstore

#include <stdio.h>
#include "Pet.h"

int main() {
	struct Pet pet;
/*	struct Pet {
		char type[LEN];
		char colour[LEN];
		int age;
		double price;
		double weight;
		char behaviourGrade[LEN];
	};*/
	printf("What type of pet is this? ");
	scanf_s("%s", pet.type, LEN);
	printf("What colour? ");
	scanf_s("%s", pet.colour, LEN);
	printf("How old is this pet? ");
	scanf_s("%i", &pet.age);
	printf("How much? ");
	scanf_s("%lf", &pet.price);
	printf("How heavy? ");
	scanf_s("%lf", &pet.weight);
	printf("Give the pet a behaviour grade (A,B,C,D,F): ");
	scanf_s("%s", pet.behaviourGrade, LEN);

	printf("\n\n");
	printf("The %s %s is %d years old. It costs $%.2lf, weighs %lfkg and has a(n) %s behaviour\n",
		pet.colour, pet.type, pet.age, pet.price, pet.weight, pet.behaviourGrade);

	return 0;
}
