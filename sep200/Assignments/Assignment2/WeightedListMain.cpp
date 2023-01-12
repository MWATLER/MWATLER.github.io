//WeightedListMain.cpp - main program for testing the weighted list

#include "WeightedList.h"

using namespace std;

int main() {
	WeightedList<int> wList;

	//Build up a list
	wList.push_back(5);
	wList.push_back(4);
	wList.push_back(3);
	wList.push_back(2);
	wList.push_back(1);

	cout << "Original list:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//search for some elements
	wList.search(3);
	wList.search(2);
	wList.search(1);
	cout << "search 3, 2, 1:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//erase the first two
	auto e = wList.begin();
	wList.erase(e++);
	wList.erase(e++);
	cout << "erase first two:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//search for 4 three times
	wList.search(4);
	wList.search(4);
	wList.search(4);
	cout << "search 4, 4, 4:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//erase the second element
	e = wList.begin();
	++e;
	e = wList.erase(e);
	cout << "erase the second one:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//erase the second element again
	wList.erase(e);
	cout << "erase the second one again (should have advanced to the last):" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//add four elements to the list
	wList.push_back(10);
	wList.push_back(20);
	wList.push_back(30);
	wList.push_back(40);
	cout << "added 10, 20, 30, 40:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//search for 10
	wList.search(10);
	cout << "search for 10:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//erase the entire list
	wList.erase(wList.begin(), wList.end());
	cout << "erase the entire list:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//add 6 elements to the list
	wList.push_back(15);
	wList.push_back(16);
	wList.push_back(17);
	wList.push_back(18);
	wList.push_back(19);
	wList.push_back(20);
	cout << "added 15, 16, 17, 18. 19, 20:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//search 20 four times and search 18 once
	wList.search(20);
	wList.search(20);
	wList.search(20);
	wList.search(20);
	wList.search(18);
	cout << "seached 20 four times and 18 once:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//erase elements 1 and 2
	e = wList.begin();
	++e;
	WeightedList<int>::iterator f = e;
	++f;
	++f;
	wList.erase(e, f);//erase elements 1 through 3, excluding 3
	cout << "erased a range (1,3) excluding 3:" << endl;
	for (auto e = wList.begin(); e != wList.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//Test the copy constructor
	WeightedList<int> wList2(wList);
	wList2.search(19);
	cout << "create wList2 from wList by copy constructor with search 19:" << endl;
	for (auto e = wList2.begin(); e != wList2.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//Test empty() and size()
	cout << "wList2 empty:" << wList2.empty() << " wList2 size:" << wList2.size() << endl << endl;

	//Test the copy assignment
	WeightedList<int> wList3 = wList;
	wList3.search(18);
	cout << "create wList3 from wList by copy assignment with search 18:" << endl;
	for (auto e = wList3.begin(); e != wList3.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//test the move constructor
	WeightedList<int> wList4(std::move(wList3));
	cout << "create wList4 from wList3 by move constructor:" << endl;
	for (auto e = wList4.begin(); e != wList4.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//test the move assignment
	WeightedList<int> wList5 = std::move(wList2);
	cout << "create wList5 from wList2 by move assignment:" << endl;
	for (auto e = wList5.begin(); e != wList5.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;

	//print out wList2 and wList3
	cout << "wList2 now became:" << endl;
	for (auto e = wList2.begin(); e != wList2.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;
	cout << "wList3 now became:" << endl;
	for (auto e = wList3.begin(); e != wList3.end(); ++e) {
		cout << *e << endl;
	}
	cout << endl;


	return 0;
}