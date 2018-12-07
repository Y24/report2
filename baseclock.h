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
    void increaseOneSecond(){
        currentDateTime=currentDateTime.addSecs(1);

    }
};

#endif // BASECLOCK_H
