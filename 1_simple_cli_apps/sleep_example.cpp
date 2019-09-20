#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif // _WIN32

using namespace std;

void sleepcp(int milliseconds);

void sleepcp(int milliseconds){
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        usleep(milliseconds * 1000);
    #endif // _WIN32
}
int main() {
    cout << "Going to sleep for 3 seconds!" << endl;
    sleepcp(3000);
    cout << "I woke up. Fresh and ready!" << endl;
}