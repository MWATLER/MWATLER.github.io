//Client1.cpp - process for writing to shared memory

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

    //Create an FMO
    HANDLE hMap = CreateFileMapping(
        INVALID_HANDLE_VALUE,       // use paging file
        NULL,                       // default security
        PAGE_READWRITE,             // read-write permission
        0,                          // maximum object size (high-order DWORD)
        sizeof(MyTestData),         // maximum object size (low-order DWORD)
        FMO_Name.c_str());          // Name of FMO

    //Map to Buffer
    void* pBuffer = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

    //Convert pointer to MyTestData type
    MyTestData* shared_data = (MyTestData*)pBuffer;


    //Changing data in a loop
    while (1)
    {
        //Write a random data
        shared_data->TestInt = rand() % 10;
        for (int i = 0; i < 4; i++)
            shared_data->TestStr[i] = 'a' + rand() % 26;
        shared_data->TestStr[4] = '\0';

        //Print information:
        std::cout << "Write to shared memory:" << shared_data->TestInt << ' ' << shared_data->TestStr << std::endl;

        //Stay for 1 second
        Sleep(1000);
    }


    //Unmap
    UnmapViewOfFile(pBuffer);
    //Turn off FMO's Handle
    CloseHandle(hMap);

    return 0;
}