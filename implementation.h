#pragma once
#include <cstdint>
#include <windows.h>

class TimeMeterImplementation{
public:

    virtual void setTimeStamp(unsigned num) = 0;

    virtual double getSTimeStamp(unsigned num) = 0;
    virtual int64_t getMSTimeStamp(unsigned num) = 0;

    virtual double getSDiff (unsigned first, unsigned second) = 0;
    virtual int64_t getMSDiff (unsigned first, unsigned second) = 0;
    
    virtual bool isLess(unsigned first, unsigned second, int64_t expected) = 0;
    virtual bool isLess(unsigned first, int64_t expected) = 0;
};