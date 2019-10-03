//
// Created by Mindaugas Bernatavičius on 10/2/2019.
//
#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <string>
using namespace std;

int main(void){
    // 0. Get the handle of std out
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    // 1. Get the console buffer info
    CONSOLE_SCREEN_BUFFER_INFO cons_buff_info;
    if(!GetConsoleScreenBufferInfo(handle, &cons_buff_info))
        cout << "Failed to get console screen buffer info" << endl;

    cout << "dwMaximumWindowSize Y: " << cons_buff_info.dwMaximumWindowSize.Y
         << " X: " << cons_buff_info.dwMaximumWindowSize.X << endl;

    // 2. Get the largest window
    COORD maxSize = GetLargestConsoleWindowSize(handle);
    cout << "Max height: " << maxSize.Y << ", max width: " << maxSize.X << endl;

    // 3. Set the buffer size to the largest window size
    SetConsoleScreenBufferSize(handle, _COORD{ maxSize.X, maxSize.Y });   // Set Buffer Size

    cout << "availableColumns: " << cons_buff_info.dwSize.Y
         << " availableRows: " << cons_buff_info.dwSize.Y << endl;

    // 4. Set the window size to the largest size -1
    short width = maxSize.X - 1;
    short height = maxSize.Y - 1;
    cout << "Height : " << height << ", width: " << width << endl;
    const _SMALL_RECT rect = {0, 0, width, height};
    if(!SetConsoleWindowInfo(handle, TRUE, &rect)) // Set Window Size
        cout << "Failed to set screen size" << endl;

    // 5. Add some delay mechanisms
    // this_thread::sleep_for(12000ms);
    cin.get();

    return EXIT_SUCCESS;
}