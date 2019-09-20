#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {    
    int milliseconds = 1000;
    cout << "Going to sleep for " << milliseconds << " milliseconds now ..." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    cout << "... I just woke up." << endl;
    
    return 0;
}