#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H
#include <iostream>

using namespace std;

class TimeSpan {
    long hours;
    long minutes;
    long seconds;
    bool positive;

    long getInSeconds() const;

public:
    TimeSpan();
    TimeSpan(double hours);
    TimeSpan(double hours, double minutes);
    TimeSpan(double hours, double minutes, double seconds);

    long getHour();
    long getMinute();
    long getSecond();
    bool isPositive();

    friend ostream& operator << (ostream& out, const TimeSpan& c);

    bool operator==(TimeSpan const& ts);
    bool operator!=(TimeSpan const& ts);
    bool operator>(TimeSpan const& ts);
    bool operator<(TimeSpan const& ts);
    bool operator>=(TimeSpan const& ts);
    bool operator<=(TimeSpan const& ts);

    TimeSpan operator+(TimeSpan const& ts);
    TimeSpan operator-(TimeSpan const& ts);

    TimeSpan& operator+=(TimeSpan const& ts);
    TimeSpan& operator-=(TimeSpan const& ts);

    TimeSpan operator*(int val);
};

#endif 