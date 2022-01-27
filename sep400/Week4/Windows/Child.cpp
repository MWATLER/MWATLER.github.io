//processChild.cpp - Child process for Parent.cpp
//
// 27-Jan-22  M. Watler         Created.

#include <iostream>
#include <windows.h>

using namespace std;

BOOL WINAPI ConsoleHandler(DWORD dwType);
bool isRunning;

int main(int argc, char* argv[]) {
    int childNo = atoi(argv[1]);

    int* seconds;
    if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE)) {
        cout << "Unable to install handler!" << endl;
        return -2;
    }

    seconds = new int;
    *seconds = 0;
    isRunning = true;
    while (isRunning) {
        cout << "ProcessChild(" << childNo << "): " << *seconds << " seconds" << endl;
        Sleep(1000);
        ++*seconds;
    }
    cout << "ProcessChild(" << childNo << "): Cleaning up" << endl;
    delete seconds;
    cout << "ProcessChild(" << childNo << "): DONE." << endl;

    return 0;
}

BOOL WINAPI ConsoleHandler(DWORD dwType)
{
    switch (dwType) {
    case CTRL_C_EVENT:
        cout << "Child: Ctrl-C intercepted" << endl;
        isRunning = false;
        break;
    case CTRL_BREAK_EVENT:
        cout << "Child: Ctrl-BREAK intercepted and thrown away" << endl;
        isRunning = false;
        break;
    default:
        cout << "Child: unhandled event " << dwType << endl;
    }
    return TRUE;
}
