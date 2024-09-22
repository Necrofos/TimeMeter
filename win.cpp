#include "implementation.h"
#include <windows.h>


TimeMeter::TimeMeter(unsigned count){
    _count = count;
    _TimeStamps = new LARGE_INTEGER[_count];
    QueryPerformanceFrequency(&_frequency);
    QueryPerformanceCounter(&_start);
}
void TimeMeter::setTimeStamp(unsigned num){
    QueryPerformanceCounter(&_TimeStamps[num]);
}
double TimeMeter::getSTimeStamp(unsigned num){
    return static_cast<double>((_TimeStamps[num].QuadPart - _start.QuadPart) / _frequency.QuadPart);
}
int64_t TimeMeter::getMSTimeStamp(unsigned num){
    return(_TimeStamps[num].QuadPart - _start.QuadPart) / _frequency.QuadPart * 1000;
}

double TimeMeter::getSDiff (unsigned first, unsigned second){
    return static_cast<double>((_TimeStamps[second].QuadPart - _TimeStamps[first].QuadPart) / _frequency.QuadPart);
}
int64_t TimeMeter::getMSDiff (unsigned first, unsigned second){
    return  static_cast<double>((_TimeStamps[second].QuadPart - _TimeStamps[first].QuadPart) / _frequency.QuadPart * 1000);
}
bool TimeMeter::isLess(unsigned first, unsigned second, int64_t expected){
    return (((_TimeStamps[second].QuadPart - _TimeStamps[first].QuadPart) / _frequency.QuadPart) <= expected);
}
bool TimeMeter::isLess(unsigned first, int64_t expected){
    return(((_TimeStamps[first].QuadPart - _start.QuadPart) / _frequency.QuadPart) <= expected);
}

