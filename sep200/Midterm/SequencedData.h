//SequencedData.h - class definition for sequenced data

#ifndef _SEQUENCEDDATA_H_
#define _SEQUENCEDDATA_H_

#include "MusicSequencerCommon.h"

//QUESTION 36: Why is MusicSequencerCommon.h being included?
//QUESTION 37: Will this computer program work for all types of T?
template<class T>
class SequencedData {
	//QUESTION 38: Why are we multiplying MAX_SEQUENCER_DATA_SIZE by 4?
	//QUESTION 39: What does sequencedData[] contain?
	T sequencedData[4 * MAX_SEQUENCER_DATA_SIZE];
	int len = 0;
public:
	void AddData(const T data[], int dataLen) {
		if (len + dataLen < MAX_SEQUENCER_DATA_SIZE) {
			memcpy(&sequencedData[len], data, dataLen);
			len += dataLen;
		}
	}
	int GetLen() {
		return len;
	}
	//QUESTION 40: Explain this operator overload when the following line is executed in main(): printf(" 0x%02x", sequencedData[i]);
	T& operator[](int index) {
		return sequencedData[index];
	}
};

#endif _SEQUENCEDDATA_H_