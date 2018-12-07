#ifndef BASECLOCK_H
#define BASECLOCK_H

#include"qdatetime.h"
class baseClock
{
private:
    QDateTime currentDateTime;

public:
    baseClock();
    QDateTime& getTime() ;
    void increaseOneSecond();
};

#endif // BASECLOCK_H
