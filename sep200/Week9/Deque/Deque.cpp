//Deque.cpp - A simple program showing deque

#include <iostream>
#include <deque>

using namespace std;

void showdata(deque<int> deque1)
{
    deque<int>::iterator iterator_1;
    for (iterator_1 = deque1.begin(); iterator_1 != deque1.end(); ++iterator_1)
        cout << "\t" << *iterator_1;
    cout << "\n";
}

void showdata2(deque<int> deque1)
{
//  deque<int>::iterator iterator_1;
    for (auto iterator_1 = deque1.begin(); iterator_1 != deque1.end(); ++iterator_1)
        cout << "\t" << *iterator_1;
    cout << "\n";
}

int main()
{
    deque<int> myqueue;
    myqueue.push_front(230); // pushing data to the front   230
    myqueue.push_front(240); // pushing data to the front   240 230
    myqueue.push_back(250);  // pushing data to the back    240 230 250
    myqueue.push_back(260);  // pushing data to the back    240 230 250 260
    cout << "Deque elements are: " << endl;
    showdata(myqueue);
    cout << endl << "Once again, Deque elements are: " << endl;
    showdata2(myqueue);

    return (0);
}