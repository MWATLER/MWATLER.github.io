//CustomerBase.cpp - The main function for a map of customers

#include <map>
#include "Customer.h"

using namespace std;

int main() {
	map<long long int, Customer> customerMap;
	char firstname[]="Aaaa";
	char lastname[]="Bbbb";
	int streetNo=0;
	char streetname[]="Cccc";
	long long int phoneNo=1111111110;

	//Build a database of 160,000 entries
	for (int i = 0; i < 20; ++i) {
		++firstname[0];
		++lastname[0];
		++streetname[0];
		firstname[1] = 'a';
		lastname[1] = 'b';
		streetname[1] = 'c';
		for (int j = 0; j < 20; ++j) {
			++firstname[1];
			++lastname[1];
			++streetname[1];
			firstname[2] = 'a';
			lastname[2] = 'b';
			streetname[2] = 'c';
			for (int k = 0; k < 20; ++k) {
				++firstname[2];
				++lastname[2];
				++streetname[2];
				++streetNo;
				firstname[3] = 'a';
				lastname[3] = 'b';
				streetname[3] = 'c';
				for (int l = 0; l < 20; ++l) {
					++firstname[3];
					++lastname[3];
					++streetname[3];
					++phoneNo;
					char name[16];
					char addr[32];
					sprintf_s(name, 16, "%s %s", firstname, lastname);
					sprintf_s(addr, 32, "%d %s Drive", streetNo, streetname);
//					cout << name << " " << addr << " " << phoneNo << endl;
                    //TODO: Insert this customer into the customerMap database
					//      You have enough information to create a customer object
				}
			}
		}
	}

	//TODO: Find and print out information for the customer with phone number 1111112222
	//      Print an error if you cannot find the customer

	//TODO: Change that customer's name to "Darryl Smith", the phone number to 9051112222,
	//      and the address to "1 Bloor Street"
	//      Then print out the information for this customer

	//TODO: Remove this customer from the database

	//TODO: Try to find this customer, print an error if you cannot, print the customer information if you can

	//TODO: Zero all data before exiting

	//TODO: Now try to find and print out information for the customer with phone number 1111111112
	//      Print an error if you cannot find the customer

	return 0;
}