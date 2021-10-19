//insertAtEnd.h

#ifndef _INSERTATEND_H_
#define _INSERTATEND_H_

template <class T>
class InsertAtEnd {
	T* m_val = nullptr;
	int size{ 0 };
public:
	T* getArray() const {
		return m_val;
	}
	int getSize() const { return size; }
	T* operator()(T elem) {//The calling code expects T* InsertAtEnd(T elem);
		T* newArray = new T[size + 1];
		for (int i = 0; i < size; ++i) {
			newArray[i] = m_val[i];
		}
		newArray[size] = elem;
		delete[] m_val;
		m_val = newArray;
		++size;
		return m_val;
	}
};

#endif _INSERTATEND_H_
