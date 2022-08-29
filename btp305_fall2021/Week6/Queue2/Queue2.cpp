//Queue2.cpp - A simple program showing queues in printing a message to the screen.

#include <iostream>
#include <queue>

using namespace std;

void showdata(queue<char>& buf)
{
    cout << endl << endl << "Data entered: ";
    while (buf.size() > 0) {
        cout << buf.front() << endl;
        buf.pop();
    }
    cout << endl << "Continue entering data to the screen. Hit '*' to finish." << endl;
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