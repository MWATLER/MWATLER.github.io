//Customer.h - Class declaration for the customer

#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_

#include <iostream>

enum Err_Status {
	Err_Success,
	Err_InvalidData,
	Err_ResourceNotAvailable
};

class Customer {
	//TODO: Add all variables, including any class variables. Your phone number has to be a long long int

public:
    //TODO: A default constructor

	//TODO: A constructor to accept the name, address and phone number of a customer

	//TODO: Get functions for name, address, the customer number, and the phone number

	//TODO: A get information function to return the customer's name, address, customer number and phone number

	//TODO: Set functions for name, address and phone number. These functions should return an error status

	//TODO: A function to zero all data

};

#endif// _CUSTOMER_H_
