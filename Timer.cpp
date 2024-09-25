#include "Timer.h"


Timer::Timer(unsigned count, OS system ){
    if (system == Windows){
        _pimpl = new TimeMeterWin(count);
        _system = system;
    }
    else if (system == Linux){
        _pimpl = new TimeMeterLinux(count);
        _system = system;
    }
};

void Timer::setTimeStamp(unsigned num){
    return _pimpl->setTimeStamp(num);
}

int64_t Timer::getMSTimeStamp(unsigned num){
    return _pimpl->getMSTimeStamp(num);
}

double Timer::getSTimeStamp(unsigned num){
    return _pimpl->getSTimeStamp(num);
}

int64_t Timer::getMSDiff (unsigned first, unsigned second){
    return _pimpl->getMSDiff(first, second);
}

double Timer::getSDiff(unsigned first, unsigned second){
     return _pimpl->getSDiff(first, second);
}
    
bool Timer::isLess(unsigned first, unsigned second, int64_t expected){
     return(_pimpl->isLess(first, second, expected));
}
bool Timer::isLess(unsigned first, int64_t expected){
    return _pimpl->isLess(first, expected);
}