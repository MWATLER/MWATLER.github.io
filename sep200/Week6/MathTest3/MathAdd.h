//MathAdd.h - class declarations for adding a series of numbers

#ifndef _MATHADD_H_
#define _MATHADD_H_

template<class T>
class MathAdd {
public:
	T Calculate(T args[], int num) {
		T retVal = args[0];
		for (int i = 1; i < num; ++i) {
			retVal += args[i];
		}
		return retVal;
	}
};

#endif// _MATHADD_H_
