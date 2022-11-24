//AudioEncoder.cpp - function definitions for the audio encoder

#include <fstream>
#include <functional>//bind()
#include <thread>
#include "AudioEncoder.h"

using namespace std;
/*class Encoder {
public:
	char operator()(char in, int key) const {
		return in + key;
	}
};*/
void EncodeThread(unsigned char* dataPtr, unsigned char* encodedDataPtr, int key, int len, const Encoder& encoder) {
#ifdef DEBUG
	Log("EncodeThread:");
#endif
	for (int i = 0; i < len; ++i) {
		encodedDataPtr[i] = encoder(dataPtr[i], key);
	}
}

AudioEncoder::AudioEncoder(std::string filename) {
	key = 0;
	fstream input(filename, ios::in);
	if (!input) {
		throw string("Failed to open file");
	}

	//copy from file to memory
	input.seekg(0, ios::end);
	size = (int)input.tellg() / 5;

	data = new unsigned char[size];
	encodedData = new unsigned char[size];

	input.seekg(ios::beg);//return to the beginning of the file
	for (int i = 0; i < size; ++i) {//read the data
		int intData;
		input >> hex >> intData;
		data[i] = intData;
//		cout << data[i];
	}
}

void AudioEncoder::Encode(int _key) {
	//Divide the data into four parts and call the encode thread
	//TEST: if size=19
	int begin1 = 0;//0
	int begin2 = size / 4;//19/4 = 4.75 -> 4
	int begin3 = size / 2;//19/2 = 9.5 -> 9
	int begin4 = 3 * size / 4;//19*3/4 = 57/4 = 14.25 -> 14
	//bind is used to bind the EncodeThread to the parameters
	// See https://www.geeksforgeeks.org/bind-function-placeholders-c/
	//void EncodeThread(char* dataPtr, char* encodedDataPtr, int key, int len, const Encoder& encoder) {
	std::thread t1(bind(EncodeThread, &data[begin1], &encodedData[begin1], _key, begin2 - begin1, Encoder()));
	std::thread t2(bind(EncodeThread, &data[begin2], &encodedData[begin2], _key, begin3 - begin2, Encoder()));
	std::thread t3(bind(EncodeThread, &data[begin3], &encodedData[begin3], _key, begin4 - begin3, Encoder()));
	std::thread t4(bind(EncodeThread, &data[begin4], &encodedData[begin4], _key, size - begin4, Encoder()));
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}

AudioEncoder::~AudioEncoder() {
	delete[] data;
	delete[] encodedData;
	data = nullptr;
	encodedData = nullptr;
}
