//SetUnsetBit.cpp - demo program to set/unset fields of a flag

#include <iostream>
#include "FileOperations.h"

using namespace std;

int main() {
	string msg;
	bool retVal;
	FileOperations file;

	file.SetFlags(file.ACCESS);
	retVal = file.Open("Sample.txt");
	if (retVal) {
		file.SetFlags(file.WRITE | file.READ);

		retVal = file.Write("Hello World\n");
		if (!retVal) cout << "Error writing to the file" << endl;

		retVal = file.Read(msg);
		if (!retVal) cout << "Error reading from the file" << endl;
		else cout << msg << endl;

		file.UnsetFlags(file.WRITE);
		
		retVal = file.Write("Goodbye World\n");
		if (!retVal) cout << "Error writing to the file" << endl;

		file.Close();
	}
	else {
		cout << "Error opening the file" << endl;
	}

	return 0;
}