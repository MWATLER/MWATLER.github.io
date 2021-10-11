//Queue.cpp - A simple program showing queues
//Queues are especially useful in threaded applications. One thread is pushing data on to the queue
//and another is popping the data off the queue for processing.

#include <iostream>
#include <queue>

using namespace std;

void showdata(queue<int> queue1)
{
    while (queue1.size() > 0) {
        cout << queue1.front() << endl;
        queue1.pop();
    }
}

int main()
{
    queue<int> myqueue;
    myqueue.push(230); // pushing data to the back
    myqueue.push(240); // pushing data to the back
    myqueue.push(250);  // pushing data to the back
    myqueue.push(260);  // pushing data to the back
    cout << "Queue elements are: ";
    showdata(myqueue);

    return (0);
}