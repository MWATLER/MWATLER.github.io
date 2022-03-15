//Queue2.cpp - A simple program showing queues in printing a message to the screen.

#include <iostream>
#include <queue>

using namespace std;

void showdata(queue<char>& buf)
{
    cout << endl << endl << "Data entered: " << endl;
    while (buf.size() > 0) {
        cout << buf.front() << endl;//get the front value
        buf.pop();//remove it from the queue
    }
}

int main()
{
    queue<char> buffer;
    char c;

    cout << "Enter data to the screen. Hit '*' to finish." << endl;
    do {
        cin>>c;
        buffer.push(c);
        if (buffer.size() >= 10) {
            showdata(buffer);
        }
    } while (c != '*');
    showdata(buffer);

    return 0;
}