//PassengerMain.c - main function for passengers

#include <stdio.h>
#include "Passenger.h"

int main() {
	int ret = 0;
	//QUESTION 24: What is Mo Salah's age?
	struct Passenger passenger1 = { "Mo Salah", 29, "Liverpool", "Berlin", 800.00, 2, 30.0, 60.0, 0.0, 0.0 };
	//QUESTION 25: How many pieces of baggage does Kevin De Bruyne have?
	struct Passenger passenger2 = { "Kevin De Bruyne", 30, "Manchester", "Kiev", 1200.00, 3, 80.0, 60.0, 90.0, 0.0 };
	//QUESTION 26: Where is Harry Kane leaving from?
	struct Passenger passenger3 = { "Harry Kane", 28, "Tottenham", "Dubai", 2200.00, 4, 80.0, 90.0, 110.0, 70.0 };
	//QUESTION 27: Where is Sadio Mane going?
	struct Passenger passenger4 = { "Sadio Mane", 30, "Liverpool", "Berlin", 800.00, 3, 30.0, 60.0, 50.0, 0.0 };

    //QUESTION 28: How are passenger1, passenger2, passenger3, passenger4 being passed to the function determineTotalWeight()? By value or by address?
	int ret1 = determineTotalWeight(&passenger1);
	int ret2 = determineTotalWeight(&passenger2);
	int ret3 = determineTotalWeight(&passenger3);
	int ret4 = determineTotalWeight(&passenger4);
	//QUESTION 29: If passenger3 alone has invalid data, will we abort this program?
	if (ret1 != 0 || ret2 != 0 || ret3 != 0 || ret4 != 0) {
		ret = -1;
		printf("Invalid data input, aborting...\n");
	}
	else {
		//QUESTION 30: How are passenger1, passenger2, passenger3, passenger4 being passed to the function PrintTicket()? By value or by address?
		PrintTicket(passenger1);
		PrintTicket(passenger2);
		PrintTicket(passenger3);
		PrintTicket(passenger4);
	}

	return ret;
}