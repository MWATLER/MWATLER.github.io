//LeftSpeaker.h - class definitions for the center back speaker

#ifndef _LEFTSPEAKER_H_
#define _LEFTSPEAKER_H_

#include "MusicSequencerCommon.h"

//QUESTION 23: Should the functions for the class LeftSpeaker be implemented in a header file?
template<class T>
class LeftSpeaker {
	T data[MAX_SEQUENCER_DATA_SIZE];
	//QUESTION 24: Why isn't filter declared here as a const?
	T filter;
public:
	T* Transform(const T* dataPtr, int len) {
		//QUESTION 25: What is the sizeof a char?
		int size = sizeof(T);
		int leftShift = size * 8 - 4;
		//QUESTION 26: What is this statement trying to do?
		filter = 0x0f << leftShift;
		//QUESTION 27: Why embedded debug?
#ifdef DEBUG
		//QUESTION 28: Will this code execute in this computer program?
		const int msgSize = 64;
		char msg[msgSize];
		sprintf_s(msg, msgSize, "LeftSpeaker: size:%d leftShift:%d filter:0x%x\n", size, leftShift, filter);
		Log(msg);
#endif DEBUG
		for (int i = 0; i < len && i < MAX_SEQUENCER_DATA_SIZE; ++i) {
			//QUESTION 29: If T is a short int (16 bits wide), what is the value of filter?
			data[i] = dataPtr[i] & filter;
		}
		return data;
	}
};

#endif// _LEFTSPEAKER_H_