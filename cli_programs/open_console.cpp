//
// Created by bernam on 10/2/2019.
//
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <string>
using namespace std;

int main(void){
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // Get the handle

    CONSOLE_SCREEN_BUFFER_INFO cons_buff_info;
    if(!GetConsoleScreenBufferInfo(handle, &cons_buff_info))
        cout << "Failed to get console screen buffer info" << endl;

    cout << "dwMaximumWindowSize Y: " << cons_buff_info.dwMaximumWindowSize.Y
         << " X: " << cons_buff_info.dwMaximumWindowSize.X << endl;

    SetConsoleScreenBufferSize(handle, _COORD{200, 50});   // Set Buffer Size
    COORD maxSize = GetLargestConsoleWindowSize(handle);



    cout << "availableColumns: " << cons_buff_info.dwSize.Y
         << " availableRows: " << cons_buff_info.dwSize.Y << endl;

    short width = 200 - 1; // maxSize.X - 1;
    short height = maxSize.Y - 1;
    cout << "Height : " << height << ", width: " << width << endl;
    const _SMALL_RECT rect = {0, 0, width, height};
    if(!SetConsoleWindowInfo(handle, TRUE, &rect)) // Set Window Size
        cout << "Failed to set screen size" << endl;

    cout << "Max height: " << maxSize.Y << ", max width: " << maxSize.X << endl;
    this_thread::sleep_for(12000ms); // Delay a bit

    return EXIT_SUCCESS;
}