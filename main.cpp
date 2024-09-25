#include <iostream>
#include "Timer.h"
#include <windows.h>

int main() {
    unsigned count = 5;
    Timer timer(count);
    for (int i = 0; i < count; ++i) {
        Sleep(100); 
        timer.setTimeStamp(i);
        std::cout << "Time stamp " << i << " install." << std::endl;
    }

    for (int i = 0; i < count; ++i) {
        double timeStamp = timer.getSTimeStamp(i);
        std::cout << "time stamp " << i << ": " << timeStamp << " seconds." << std::endl;
    }

    double diff = timer.getSDiff(0, 1);
    std::cout << " difference between stamps 0 и 1: " << diff << " seconds." << std::endl;

    if (timer.isLess(0, 1, 0.2)) {
        std::cout << "Metric 0 is less than metric 1, taking into account the expected value." << std::endl;
    }
    return 0;
}
