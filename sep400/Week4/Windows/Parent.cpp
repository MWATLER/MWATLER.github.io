//Parent.cpp - Parent creates four children and shuts them down one by one
//
// 27-Jan-22  M. Watler         Created.

#include <iostream>
#include <windows.h>

using namespace std;

const int NUM = 4;
PROCESS_INFORMATION* pi = new PROCESS_INFORMATION[NUM];

BOOL WINAPI ConsoleHandler(DWORD dwType);

int main(VOID)
{
    int retVal = 0;
    const int BUF_LEN = 512;
    STARTUPINFO* si = new STARTUPINFO[NUM];
    HANDLE* hProcesses = new HANDLE[NUM];
    wchar_t childPath[BUF_LEN];

    if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE)) {
        cout << "Unable to install handler!" << endl;
        retVal = -1;
    }

    /* allocate memory */
    for (int i = 0; i<NUM && retVal==0; ++i) {
        ZeroMemory(&si[i], sizeof(si[i]));
        si[i].cb = sizeof(si[i]);
        ZeroMemory(&pi[i], sizeof(pi[i]));
        /* create child process */
        swprintf(childPath, BUF_LEN, L"C:\\Seneca\\Year2021-2022\\SEP400OperatingSystems\\Week3\\Windows\\Signals\\Child\\Debug\\Child.exe %d", i + 1);
        if (!CreateProcess(NULL, /* use command line */
            childPath, /* command */
            NULL, /* don’t inherit process handle */
            NULL, /* don’t inherit thread handle */
            FALSE, /* disable handle inheritance */
            0, /* no creation flags */
            NULL, /* use parent’s environment block */
            NULL, /* use parent’s existing directory */
            &si[i],
            &pi[i]))
        {
            cout << "Parent: Create Process Failed" << endl;
            retVal = -2;
        }
        else {
            hProcesses[i] = pi[i].hProcess;
        }
    }

    if (retVal == 0) {
        Sleep(1000);
        cout << "Parent: Processes created" << endl;
        /* parent will wait for the children to complete */
        WaitForMultipleObjects(NUM, hProcesses, TRUE, INFINITE);
        Sleep(1000);
        cout << "Parent: Children Complete" << endl;
    }
    /* close handles */
    for(int i=0; i<NUM; ++i) {
        CloseHandle(pi[i].hProcess);
        CloseHandle(pi[i].hThread);
    }
    delete[] si;
    delete[] pi;
    delete[] hProcesses;

    cout << "Parent: return " << retVal << endl;
    return retVal;
}

BOOL WINAPI ConsoleHandler(DWORD dwType)
{
    switch (dwType) {
    case CTRL_C_EVENT:
        cout << "Parent: Ctrl-C intercepted and thrown away" << endl;
        break;
    case CTRL_BREAK_EVENT:
        cout << "Parent: Ctrl-BREAK" << endl;
        for (int i = 0; i < NUM; ++i) {
            Sleep(1000);
            GenerateConsoleCtrlEvent(CTRL_C_EVENT, pi[i].dwProcessId);
        }
        break;
    default:
        cout << "unhandled event " << dwType << endl;
    }
    return TRUE;
}










/*
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

void ProcessChild(int childNo);
void ProcessParent(int child[]);
bool isRunning;

int main() {
    const int numChildren = 4;
    int childPid[numChildren];

    for (int i = 0; i < numChildren; ++i) {
        pid_t id = fork();
        if (id == 0) {
            char childNo[5];
            sprintf(childNo, "%d", i);
            execlp("./processChild", "./processChild", childNo, NULL);
        }
        else {
            childPid[i] = id;
        }
    }

    sleep(10);
    //Stop child 2
    cout << "ProcessParent: Stopping child 2" << endl;
    kill(childPid[2], SIGINT);
    sleep(10);
    //Stop child 1
    cout << "ProcessParent: Stopping child 1" << endl;
    kill(childPid[1], SIGINT);
    sleep(10);
    //Stop child 3
    cout << "ProcessParent: Stopping child 3" << endl;
    kill(childPid[3], SIGINT);
    sleep(10);
    //Stop child 0
    cout << "ProcessParent: Stopping child 0" << endl;
    kill(childPid[0], SIGINT);
    cout << "ProcessParent: DONE." << endl;

    return 0;
}
*/