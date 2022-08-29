//ErrorDetection.cpp - main function for error detection using a parity bit

#include <bitset>//binary format
#include <iomanip>//setw()
#include <iostream>

using namespace std;

int main() {
	const int SIZE = 127;
	short int data[SIZE];
	short int parity = 0;

	for(int i=0; i<SIZE; ++i) {//generate the 7-bit data
		data[i] = i;//0=0x00, 127=0x7F=0111 1111
	}

	const short int BIT0_MASK = 0x01;//0000 0001
	const short int BIT1_MASK = 0x02;//0000 0010
	const short int BIT2_MASK = 0x04;//0000 0100
	const short int BIT3_MASK = 0x08;//0000 1000
	const short int BIT4_MASK = 0x10;//0001 0000
	const short int BIT5_MASK = 0x20;//0010 0000
	const short int BIT6_MASK = 0x40;//0100 0000
	const short int BIT7_MASK = 0x80;//1000 0000
	cout << "THE DATA STREAM:" << endl;
	for (int i = 0; i < SIZE; ++i) {//generate the parity bit then add to the data
//		short int bit0 = (data[i] & BIT0_MASK) / BIT0_MASK;
		short int bit0 = (data[i] & BIT0_MASK) >> 0;
		short int bit1 = (data[i] & BIT1_MASK) >> 1;
		short int bit2 = (data[i] & BIT2_MASK) >> 2;//1100 0110 & 0000 0100 = 0000 0100 >> 2 = 0000 0001
		short int bit3 = (data[i] & BIT3_MASK) >> 3;
		short int bit4 = (data[i] & BIT4_MASK) >> 4;
		short int bit5 = (data[i] & BIT5_MASK) >> 5;
		short int bit6 = (data[i] & BIT6_MASK) >> 6;
		parity = (((((bit6 ^ bit5) ^ bit4) ^ bit3) ^ bit2) ^ bit1) ^ bit0;
		cout << "Data: " << bitset<8>(data[i]) << " Parity: " << bitset<8>(parity);
		data[i] = (data[i] << 1) + parity;//There is always an even number of 1's in the data stream
		cout << " Data+Parity: " << bitset<8>(data[i]) << endl;
	}
	cout << endl;

	cout << "THE DATA STREAM WITH PARITY ERROR DETECTION:" << endl;
	for(int i=0; i<SIZE; ++i) {//test the data stream for errors
		short int bit0 = (data[i] & BIT0_MASK) >> 0;
		short int bit1 = (data[i] & BIT1_MASK) >> 1;
		short int bit2 = (data[i] & BIT2_MASK) >> 2;
		short int bit3 = (data[i] & BIT3_MASK) >> 3;
		short int bit4 = (data[i] & BIT4_MASK) >> 4;
		short int bit5 = (data[i] & BIT5_MASK) >> 5;
		short int bit6 = (data[i] & BIT6_MASK) >> 6;
		short int bit7 = (data[i] & BIT7_MASK) >> 7;
		short int error = ((((((bit7 ^ bit6) ^ bit5) ^ bit4) ^ bit3) ^ bit2) ^ bit1) ^ bit0;
		cout << "Data: " << bitset<8>(data[i]) << " Error: " << error << endl;
	}
	cout << endl;

	for (int i = 0; i < SIZE; ++i) {//add a 1 bit error to some parts of the data stream
		if (i % 10 == (rand() % 10) + 1) 
			data[i] -= 2;
	}
	cout << "THE DATA STREAM WITH RANDOM ERRORS AND PARITY ERROR DETECTION:" << endl;
	for (int i = 0; i < SIZE; ++i) {//test the data stream for errors
		short int bit0 = (data[i] & BIT0_MASK) >> 0;
		short int bit1 = (data[i] & BIT1_MASK) >> 1;
		short int bit2 = (data[i] & BIT2_MASK) >> 2;
		short int bit3 = (data[i] & BIT3_MASK) >> 3;
		short int bit4 = (data[i] & BIT4_MASK) >> 4;
		short int bit5 = (data[i] & BIT5_MASK) >> 5;
		short int bit6 = (data[i] & BIT6_MASK) >> 6;
		short int bit7 = (data[i] & BIT7_MASK) >> 7;
		short int error = ((((((bit7 ^ bit6) ^ bit5) ^ bit4) ^ bit3) ^ bit2) ^ bit1) ^ bit0;
		cout << "Data: " << bitset<8>(data[i]) << " Error: " << error << endl;
	}

	return 0;
}