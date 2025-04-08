#include <cstdint>
#include <windows.h>
#include "lin.h"
#include "win.h"
enum OS{
    Windows,
    Linux
};

class TimeMeterImplementation;

class Timer{
public:
    Timer(unsigned count, OS system = Windows);

    virtual void setTimeStamp(unsigned num);

    virtual double getSTimeStamp(unsigned num);
    virtual int64_t getMSTimeStamp(unsigned num);

    virtual double getSDiff (unsigned first, unsigned second);
    virtual int64_t getMSDiff (unsigned first, unsigned second);
    
    virtual bool isLess(unsigned first, unsigned second, int64_t expected);
    virtual bool isLess(unsigned first, int64_t expected);
private:
    TimeMeterImplementation* _pimpl = nullptr;
    OS _system;
};