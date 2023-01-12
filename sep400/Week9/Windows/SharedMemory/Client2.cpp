//Client2.cpp - process for reading data from shared memory

#include <windows.h>
#include <iostream>

//Data structure for testing
struct MyTestData
{
    int TestInt;        //Integer data for testing
    char TestStr[5];    //String data for testing
};

int main()
{
    //Name of FMO(file mapping object) (should be consistent between the two test processes)
    const std::wstring FMO_Name(L"TestFMO");

    //Open an FMO
    HANDLE hMap = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,    // Read/Write Permissions
        FALSE,                  // do not inherit the name
        FMO_Name.c_str());      // Name of FMO


    //Map to Buffer
    void* pBuffer = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    //Convert pointer to MyTestData type
    MyTestData* shared_data = (MyTestData*)pBuffer;


    //Reading data continuously in a loop
    while (1)
    {
        //Print information:
        std::cout << "Read shared memory:" << shared_data->TestInt << ' ' << shared_data->TestStr << std::endl;

        //Stay for 0.1 seconds
        Sleep(100);
    }


    //Unmap
    UnmapViewOfFile(pBuffer);
    //Turn off FMO's Handle
    CloseHandle(hMap);

    return 0;
}