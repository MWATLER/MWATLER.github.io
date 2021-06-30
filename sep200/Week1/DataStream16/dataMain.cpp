// dataMain.cpp - main code for 16 bit data

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char16_t dataStream[] = { 4, 5, 32,
	0x1111, 0x1122, 0x1133, 0x1144, 0x1155, 0x1166, 0x1177, 0x1188,
	0x2211, 0x2222, 0x2233, 0x2244, 0x2255, 0x2266, 0x2277, 0x2288,
	0x3311, 0x3322, 0x3333, 0x3344, 0x3355, 0x3366, 0x3377, 0x3388,
	0x4411, 0x4422, 0x4433, 0x4444, 0x4455, 0x4466, 0x4477, 0x4488 };

int main() {
	int retVal = 0;
	const int MAX_SIZE = 255;
	struct DataPacket {
		int source;
		int destination;
		int dataSize;
		char16_t data[MAX_SIZE];
	} dataPacket;
	char16_t* dataPtr = dataStream;

	dataPacket.source = *dataPtr++;
	dataPacket.destination = *dataPtr++;
	dataPacket.dataSize = *dataPtr++;
	if (dataPacket.dataSize > MAX_SIZE) {
		cout << "Data overflow, aborting..." << endl;
		retVal = -1;
	}
	else {
		for (int i = 0; i < dataPacket.dataSize; ++i) {
			dataPacket.data[i] = *dataPtr++;
		}
	}

	if (retVal == 0) {
		cout << "The source is " << dataPacket.source << " and the destination is " << dataPacket.destination << endl;
		cout << "The data size is " << dataPacket.dataSize << ". The data is:" << endl;
		for (int i = 0; i < dataPacket.dataSize; ++i) {
			cout << " 0x" << hex << dataPacket.data[i];
			if ((i + 1) % 8 == 0) cout << endl;
		}
	}

	return retVal;
}
