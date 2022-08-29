//AudioEncoder.h - class declaration for an audio encoder

#ifndef _AUDIOENCODER_H_
#define _AUDIOENCODER_H_

#include <iostream>

class Encoder {
public:
	char operator()(char in, int key) const {
		return in + key;
	}
};

class AudioEncoder {
	char* data;
	char* encodedData;
	int size;
	int key;
public:
	AudioEncoder(std::string filename);
	void Encode(int _key);
	char* GetData() const {
		return data;
	}
	char* GetEncodedData() const {
		return encodedData;
	}
	int GetSize() const {
		return size;
	}
	~AudioEncoder();
};

void EncodeThread(char* dataPtr, char* encodedDataPtr, int key, int len, const Encoder& encoder);
#endif// _AUDIOENCODER_H_
