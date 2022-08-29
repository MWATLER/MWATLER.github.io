// A.h
#ifndef A_H
#define A_H

struct A
{
public:
	double m_val;
public:
	A operator+=(const A& other)
	{
		this->m_val += other.m_val;
		return *this;
	}
	double getValue() const { return m_val; }
};

decltype(A().getValue()) operator+=(double& val, const A& other);

// "data" is an array of "N" elements of type "T"
//template < typename T, double N>
template < typename T, int N>
T process(const T* data)
{
	T sum{};
//	for (const auto& elem : data)//MW: probably want to use N
	for (int i = 0; i < N; ++i)//MW: probably want to use N
		sum += data[i];
	return sum;
}
#endif