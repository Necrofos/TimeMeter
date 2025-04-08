#include "win.h"
#include <windows.h>

TimeMeterWin::TimeMeterWin(unsigned count){
    _count = count;
    _TimeStamps = new LARGE_INTEGER[_count];
    QueryPerformanceFrequency(&_frequency);
    QueryPerformanceCounter(&_start);
}

void TimeMeterWin::setTimeStamp(unsigned num){
    QueryPerformanceCounter(&_TimeStamps[num]);
}

double TimeMeterWin::getSTimeStamp(unsigned num){
    return static_cast<double>(_TimeStamps[num].QuadPart - _start.QuadPart) / _frequency.QuadPart;
}

int64_t TimeMeterWin::getMSTimeStamp(unsigned num){
    return (_TimeStamps[num].QuadPart - _start.QuadPart) * 1000 / _frequency.QuadPart;
}

double TimeMeterWin::getSDiff(unsigned first, unsigned second){
    return static_cast<double>(_TimeStamps[second].QuadPart - _TimeStamps[first].QuadPart) / _frequency.QuadPart;
}

int64_t TimeMeterWin::getMSDiff(unsigned first, unsigned second){
    return (_TimeStamps[second].QuadPart - _TimeStamps[first].QuadPart) * 1000 / _frequency.QuadPart;
}

bool TimeMeterWin::isLess(unsigned first, unsigned second, int64_t expected){
    return ((_TimeStamps[second].QuadPart - _TimeStamps[first].QuadPart) * 1000 / _frequency.QuadPart) <= expected;
}

bool TimeMeterWin::isLess(unsigned first, int64_t expected){
    return ((_TimeStamps[first].QuadPart - _start.QuadPart) * 1000 / _frequency.QuadPart) <= expected;
}
