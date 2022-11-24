//AudioEncoder.h - class declaration for an audio encoder

#ifndef _AUDIOENCODER_H_
#define _AUDIOENCODER_H_

#include <iostream>

#define DEBUG
#define Log(msg) std::cout<<msg<<std::endl;

class Encoder {
public:
	unsigned char operator()(unsigned char in, int key) const {
		return in + key;
	}
};

class AudioEncoder {
	unsigned char* data;
	unsigned char* encodedData;
	int size;
	int key;
public:
	AudioEncoder(std::string filename);
	void Encode(int _key);
	unsigned char* GetData() const {
		return data;
	}
	unsigned char* GetEncodedData() const {
		return encodedData;
	}
	int GetSize() const {
		return size;
	}
	~AudioEncoder();
};

void EncodeThread(unsigned char* dataPtr, unsigned char* encodedDataPtr, int key, int len, const Encoder& encoder);
#endif// _AUDIOENCODER_H_
