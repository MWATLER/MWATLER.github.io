//Customer.cpp - Function definitions for the customer

#include <string>
#include "Customer.h"

using namespace std;

//TODO: Initialize the number of customers to zero

//TODO: Create all function definitions for those declared in class Customer

//GIVEN: An operator that expresses how to order data
bool Customer::operator<(const Customer& rhs) const noexcept {
	return this->phoneNo < rhs.phoneNo;
}
