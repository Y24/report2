#include "baseclock.h"
#include"qdatetime.h"
baseClock::baseClock()
{
    currentDateTime=QDateTime::currentDateTime();
}
QDateTime& baseClock::getTime(){
    return currentDateTime;
}
