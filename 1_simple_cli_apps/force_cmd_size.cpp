//
// Created by bernam on 10/2/2019.
//

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <thread>
using namespace std;


// int nScreenWidth = 80;			// Console Screen Size X (columns)
// int nScreenHeight = 30;			// Console Screen Size Y (rows)
int nScreenWidth = 25;			// Console Screen Size X (columns)
int nScreenHeight = 25;			// Console Screen Size Y (rows)

int main(){

    // Create Screen Buffer
    // wchar_t * screen = new wchar_t[nScreenWidth * nScreenHeight];
    // for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    DWORD dwBytesWritten = 0;



    _COORD coord; coord.X = nScreenWidth; coord.Y = nScreenHeight;
    SetConsoleScreenBufferSize(hConsole, coord);
    SetConsoleActiveScreenBuffer(hConsole);

    _SMALL_RECT Rect;
    Rect.Top = 0; Rect.Left = 0;
    Rect.Bottom = nScreenHeight - 1;
    Rect.Right = nScreenWidth - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &Rect);
    // WriteConsoleOutputCharacter(hConsole, reinterpret_cast<LPCSTR>(screen), nScreenWidth * nScreenHeight, {0, 0 }, &dwBytesWritten);

    COORD maxSize = GetLargestConsoleWindowSize(hConsole);
    cout << "Max height: " << maxSize.Y << ", max width: " << maxSize.X << endl;
    this_thread::sleep_for(8000ms); // Delay a bit

    return EXIT_SUCCESS;
}



//
// void SetWindow(int Width, int Height)
// {
//     _COORD coord;
//     coord.X = Width;
//     coord.Y = Height;
//
//     _SMALL_RECT Rect;
//     Rect.Top = 0;
//     Rect.Left = 0;
//     Rect.Bottom = Height - 1;
//     Rect.Right = Width - 1;
//
//
//
//     HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
//     SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
//     SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
// }
//
// int main(void)
// {
//     SetWindow(80,40);
//     int dx=1,i=5,l=0;
//
//     while(l<5)
//     {
//         i=i+dx;
//         if((i<1) || (i>10)){ dx=-dx; l++;}
//
//         SetWindow(10*i,5*i);
//         Sleep(10);
//     }
//
//     cout <<" \nPress any key to continue\n";
//     cin.ignore();
//     cin.get();
//     return 0;
// }