#include <cstdint>
#include <ctime>
#include <iostream>
#include "implementation.h"

class TimeMeterLinux:public TimeMeterImplementation {
public:
    TimeMeterLinux(unsigned count);
    ~TimeMeterLinux();

    void setTimeStamp(unsigned num);
    double getSTimeStamp(unsigned num);
    int64_t getMSTimeStamp(unsigned num);

    double getSDiff(unsigned first, unsigned second);
    int64_t getMSDiff(unsigned first, unsigned second);

    bool isLess(unsigned first, unsigned second, int64_t expected);
    bool isLess(unsigned first, int64_t expected);

private:
    unsigned _count;
    timespec _start;
    timespec* _TimeStamps;
    
    void getCurrentTime(timespec& ts);
};


