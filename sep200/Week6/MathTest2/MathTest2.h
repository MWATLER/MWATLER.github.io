//MathTest2.h - class declarations for math base, math add, math subtract, math multiply, and math divide

template<class T>
class MathBase {
public:
	virtual T Calculate(T args[]) {
		T retVal = 0;
		return retVal;
	}
};

template<class T, int N>
class MathAdd : public MathBase<T> {
public:
	T Calculate (T args[]) {
		T retVal = args[0];
		for (int i = 1; i < N; ++i) {
			retVal += args[i];
		}
		return retVal;
	}
};

template<class T, int N>
class MathMultiply : public MathBase<T> {
public:
	T Calculate(T args[]) {
		T retVal = args[0];
		for (int i = 1; i < N; ++i) {
			retVal *= args[i];
		}
		return retVal;
	}
};
