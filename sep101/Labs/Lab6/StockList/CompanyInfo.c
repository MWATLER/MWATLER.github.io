//CompanyInfo.c - main function for company information

#include <stdio.h>
#include <stdlib.h>//atof, atoi
#include "CompanyInfo.h"
#define NUM_COMPANIES 4

int main() {
	struct CompanyInfo company[NUM_COMPANIES];
	const char streamingData[] = "Telus Corp,T.TO,28.70,3573258,Transalta Corp,TA.TO,11.56,1011631,Trican Well,TCW.TO,3.82,337364,Toronto-Dominion Bank,TD.TO,87.97,3648894,";

	char* dataPtr = streamingData;//&streamingData[0]

	for (int i = 0; i < NUM_COMPANIES; ++i) {
		//extract the name
		int index = 0;
		while (*dataPtr != ',') {
//			company[i].name[index++] = *dataPtr++;
			company[i].name[index] = *dataPtr;
			++index;
			++dataPtr;
		}
		//At this point, dataPtr points to a comma. Set company[i].name[index] to the null terminator instead
		company[i].name[index] = '\0';

		//extract the symbol
		index = 0;//set the index back to 0 
		++dataPtr;//and advance the pointer beyond the comma
		while (*dataPtr != ',') {
//			company[i].symbol[index++] = *dataPtr++;
			company[i].symbol[index] = *dataPtr;
			++index;
			++dataPtr;
		}
		//At this point, dataPtr points to a comma. Set company[i].symbol[index] to the null terminator instead
		company[i].symbol[index] = '\0';

		//extract the price
		index = 0;//set the index back to 0 
		++dataPtr;//and advance the pointer beyond the comma
		char tmp[SIZE];//we have to extract the price as a string first, then convert to a double
		while (*dataPtr != ',') {
//			tmp[index++] = *dataPtr++;
			tmp[index] = *dataPtr;
			++index;
			++dataPtr;
		}
		//At this point, dataPtr points to a comma. Set tmp[index] to the null terminator instead
		tmp[index] = '\0';
		//call the utility function atof() to convert from a character array to a double float
		//https://cplusplus.com/reference/cstdlib/atof/
		company[i].price = atof(tmp);

		//extract the volume
		index = 0;//set the index back to 0 
		++dataPtr;//and advance the pointer beyond the comma
		tmp[0] = '\0';//we have to extract the volume as a string first, then convert to an int
		while (*dataPtr != ',') {
//			tmp[index++] = *dataPtr++;
			tmp[index] = *dataPtr;
			++index;
			++dataPtr;
		}
		//At this point, dataPtr points to a comma. Set tmp[index] to the null terminator instead
		tmp[index] = '\0';
		//call the utility function atoi() to convert from a character array to an integer
		//https://cplusplus.com/reference/cstdlib/atoi/
		company[i].volume = atoi(tmp);

		++dataPtr;//advance the pointer beyond the comma
	}

	printf("%25s %7s %7s %10s\n", "COMPANY NAME", "SYMBOL", "PRICE", "VOLUME");
	for (int i = 0; i < NUM_COMPANIES; ++i) {
		printf("%25s %7s %7.2lf %10d\n", company[i].name, company[i].symbol, company[i].price, company[i].volume);
	}

	return 0;
}