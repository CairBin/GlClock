#include "Time.h"

namespace Clock
{
    void Time::GetTime()
    {
        time_t nowtime;
        time(&nowtime);
        struct tm *tm = localtime(&nowtime);
        this->hour = tm->tm_hour;
        this->min = tm->tm_min;
        this->sec = tm->tm_sec;
        // delete p;
    }
    Time::Time()
    {
        GetTime();
    }

    Time::~Time()
    {
    }

    void Time::Flush()
    {
        GetTime();
    }

    int Time::GetHour()
    {
        return this->hour;
    }

    int Time::GetMin()
    {
        return this->min;
    }

    int Time::GetSec()
    {
        return this->sec;
    }
}