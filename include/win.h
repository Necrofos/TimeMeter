#include "implementation.h"

class TimeMeterWin:public TimeMeterImplementation{
public:
    TimeMeterWin(unsigned count);

    void setTimeStamp(unsigned num);

    double getSTimeStamp(unsigned num);
    int64_t getMSTimeStamp(unsigned num);

    double getSDiff (unsigned first, unsigned second);
    int64_t getMSDiff (unsigned first, unsigned second);
    
    bool isLess(unsigned first, unsigned second, int64_t expected);
    bool isLess(unsigned first, int64_t expected);
private:
    unsigned _count;
    LARGE_INTEGER _start;
    LARGE_INTEGER* _TimeStamps;
    LARGE_INTEGER _frequency;
};