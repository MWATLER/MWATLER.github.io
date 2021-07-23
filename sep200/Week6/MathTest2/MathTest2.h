//MathTest2.h - class declarations for math base, math add, math subtract, math multiply, and math divide

template<class T, int N>
class MathBase {
public:
	virtual T AddSeries(T args[]) {
		T retVal = 0;
		return retVal;
	}
	virtual T MultiplySeries(T args[]) {
		T retVal = 0;
		return retVal;
	}
};

template<class T, int N>
class MathAdd : public MathBase<T, N> {
public:
	T AddSeries(T args[]) {
		T retVal = args[0];
		for (int i = 1; i < N; ++i) {
			retVal += args[i];
		}
		return retVal;
	}
};

template<class T, int N>
class MathMultiply : public MathBase<T, N> {
public:
	T MultiplySeries(T args[]) {
		T retVal = args[0];
		for (int i = 1; i < N; ++i) {
			retVal *= args[i];
		}
		return retVal;
	}
};
