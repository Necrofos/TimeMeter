#include "lin.h"
TimeMeterLinux::TimeMeterLinux(unsigned count) {
    _count = count;
    _TimeStamps = new timespec[_count];
    getCurrentTime(_start);
}

TimeMeterLinux::~TimeMeterLinux() {
    delete[] _TimeStamps;
}

void TimeMeterLinux::getCurrentTime(timespec& ts) {
    clock_gettime(CLOCK_MONOTONIC, &ts);
}

void TimeMeterLinux::setTimeStamp(unsigned num) {
    getCurrentTime(_TimeStamps[num]);
}

double TimeMeterLinux::getSTimeStamp(unsigned num) {
    timespec diff;
    diff.tv_sec = _TimeStamps[num].tv_sec - _start.tv_sec;
    diff.tv_nsec = _TimeStamps[num].tv_nsec - _start.tv_nsec;
    if (diff.tv_nsec < 0) {
        diff.tv_sec--;
        diff.tv_nsec += 1000000000L;
    }

    return diff.tv_sec + diff.tv_nsec / 1e9;
}

int64_t TimeMeterLinux::getMSTimeStamp(unsigned num) {
    timespec diff;
    diff.tv_sec = _TimeStamps[num].tv_sec - _start.tv_sec;
    diff.tv_nsec = _TimeStamps[num].tv_nsec - _start.tv_nsec;
    
    if (diff.tv_nsec < 0) {
        diff.tv_sec--;
        diff.tv_nsec += 1000000000L;
    }

    return static_cast<int64_t>(diff.tv_sec * 1000 + diff.tv_nsec / 1000000L);
}

double TimeMeterLinux::getSDiff(unsigned first, unsigned second) {
    timespec diff;
    diff.tv_sec = _TimeStamps[second].tv_sec - _TimeStamps[first].tv_sec;
    diff.tv_nsec = _TimeStamps[second].tv_nsec - _TimeStamps[first].tv_nsec;

    if (diff.tv_nsec < 0) {
        diff.tv_sec--;
        diff.tv_nsec += 1000000000L;
    }

    return diff.tv_sec + diff.tv_nsec / 1e9;
}

int64_t TimeMeterLinux::getMSDiff(unsigned first, unsigned second) {
    timespec diff;
    diff.tv_sec = _TimeStamps[second].tv_sec - _TimeStamps[first].tv_sec;
    diff.tv_nsec = _TimeStamps[second].tv_nsec - _TimeStamps[first].tv_nsec;

    if (diff.tv_nsec < 0) {
        diff.tv_sec--;
        diff.tv_nsec += 1000000000L;
    }

    return static_cast<int64_t>(diff.tv_sec * 1000 + diff.tv_nsec / 1000000L);
}

bool TimeMeterLinux::isLess(unsigned first, unsigned second, int64_t expected) {
    return getMSDiff(first, second) <= expected;
}

bool TimeMeterLinux::isLess(unsigned first, int64_t expected) {
    return getMSTimeStamp(first) <= expected;
}