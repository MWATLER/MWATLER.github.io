//Library.h - class declarations and function definitions for a library

#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include "BookObserver.h"

template <class T>
class Library {
	std::string name;
	T* m_item{ nullptr };
	int m_count{ 0 };//number of items
	const int BLOCK_SIZE = 5;//resize array in blocks of 5
//	const int BLOCK_SIZE = 1000000000000;//Provoke a std::bad_alloc exception
	BookObserver* bookObserver;
	void (*onItemAdded)(BookObserver* bObserver, Book::Type type) = nullptr;
public:
	Library(std::string name) {
		this->name = name;
	}
	std::string GetName() const { return name; }
	void RegisterObserver(BookObserver* bObserver, void (*observer)(BookObserver* bObserver, Book::Type type)) {
		bookObserver = bObserver;
		onItemAdded = observer;
	}
	Library& operator+=(const T& item) {
		bool found = false;
		for (int i = 0; i < m_count && !found; ++i) {
			if (item.GetName() == m_item[i].GetName()) {
				found = true;
				std::cout << "Item already exists, not added..." << std::endl;
			}
		}
		if(!found) {//add to our library
			if (m_count % BLOCK_SIZE == 0) {//resize our array
				T* tmp = new T[m_count + BLOCK_SIZE];//add space for another 5 items
				if (tmp == nullptr) {
					throw std::bad_alloc();
				}
				else {
					for (int i = 0; i < m_count; ++i) {
						tmp[i] = m_item[i];
					}
					tmp[m_count] = item;

					delete[] m_item;
					m_item = tmp;
					++m_count;
					if(onItemAdded!=nullptr) onItemAdded(bookObserver, item.GetType());
				}
			}
			else {
				m_item[m_count] = item;
				++m_count;
				if (onItemAdded != nullptr) onItemAdded(bookObserver, item.GetType());
			}
		}
		return *this;
	}
	T& operator[](size_t idx) const
	{
		if (idx > m_count) {
			std::string msg = "Index out of range";
			throw std::out_of_range(msg);
		}
		return m_item[idx];
	}
	~Library() {
		if (m_item != nullptr) {//MW: We actually no longer need this check
			delete[] m_item;
			m_item = nullptr;
		}
	}
};

#endif// _LIBRARY_H_
