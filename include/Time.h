#ifndef _TIME_H_
#define _TIME_H_
#include <ctime>

namespace Clock
{
    class Time
    {
    private:
        int hour;
        int min;
        int sec;

    private:
        void
        GetTime();

    public:
        Time();
        ~Time();

        void Flush();

        int GetHour();
        int GetMin();

        int GetSec();
    };
}

#endif