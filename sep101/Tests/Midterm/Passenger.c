//Passenger.c - function definitions for a passenger

#include <stdio.h>
#include "Passenger.h"

//QUESTION 12: Why is passenger passed through via a pointer?
int determineTotalWeight(struct Passenger* passenger) {
	int retVal = 0;

	//QUESTION 13: Why is totalWeight being initialized to 0.0?
	passenger->baggage.totalWeight = 0.0;
	for (int i = 0; i < passenger->baggage.numberOfPieces && retVal == 0; ++i) {
		if (passenger->baggage.weight[i] < 0) {
			//QUESTION 14: If an invalid weight is entered, will the for-loop terminate or continue?
			retVal = -1;
			printf("Incorrect data entered for baggage %d for passenger %s.\n", i + 1, passenger->name);
		}
		else {
			passenger->baggage.totalWeight += passenger->baggage.weight[i];
		}
	}

	//QUESTION 15: What does this function return? An error status, a value, or something else? If a value, what is that value?
	return retVal;
}

//QUESTION 16: Why is passenger not passed through via a pointer?
int isOverweight(struct Passenger passenger) {
	int retVal = 0;
	//QUESTION 17: From the below if-statement, will a passenger ever be overweight if (s)he paid $3000 for a ticket?
	if ((passenger.ticket.price < 1000.00 && passenger.baggage.totalWeight>100) ||
		(passenger.ticket.price < 2000.00 && passenger.baggage.totalWeight>200)) {
		retVal = 1;
	}

	//QUESTION 18: What does this function return? An error status, a value, or something else? If a value, what is that value?
	return retVal;
}

//QUESTION 19: Who is calling this function?
double determineFine(struct Passenger passenger) {
	double retVal = 0.0;
	//QUESTION 20: If a passenger paid $500 for a ticket and had baggage of 110kg total weight, what fine does (s)he pay?
	if (passenger.ticket.price < 1000.00) {
		retVal = 10.00 * (passenger.baggage.totalWeight - 100.0);
	}
	else if (passenger.ticket.price < 2000.00) {
		retVal = 10.00 * (passenger.baggage.totalWeight - 200.0);
	}
	if (retVal < 0.0) retVal = 0.0;
	//QUESTION 21: What does this function return? An error status, a value, or something else? If a value, what is that value?
	return retVal;
}

void PrintTicket(struct Passenger passenger) {
	printf("%s age %d is travelling from %s to %s.\n", passenger.name, passenger.age, passenger.ticket.origin, passenger.ticket.destination);
	printf("%s has %d piece(s) of luggage weighing %lf kg in total.\n", passenger.name, passenger.baggage.numberOfPieces, passenger.baggage.totalWeight);
	//QUESTION 22: What function is being called in this if-statement?
	if (isOverweight(passenger) == 1) {
		printf("%s's baggage is over weight!\n", passenger.name);
		//QUESTION 23: What does the format %.2lf mean?
		printf("%s has to pay a fine of $%.2lf.\n", passenger.name, determineFine(passenger));
	}
	printf("\n");
}