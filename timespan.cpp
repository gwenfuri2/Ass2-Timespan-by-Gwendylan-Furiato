#include "timespan.h"
#include <iomanip> // this is the library in C++ to manipulate the parametric output

TimeSpan::TimeSpan()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

TimeSpan::TimeSpan(double hours)
{
    this->hours = hours;
    minutes = 0;
    seconds = 0;

    positive = this->hours >= 0;
    this->hours = abs(this->hours);
}

TimeSpan::TimeSpan(double hours, double minutes)
{
    this->minutes = minutes + hours * 60;

    positive = this->minutes >= 0;
    this->minutes = abs(this->minutes);

    this->hours = this->minutes / 60;
    this->minutes %= 60;
    seconds = 0;
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
    this->seconds = hours * 3600 + minutes * 60 + seconds;

    positive = this->seconds >= 0;
    this->seconds = abs(this->seconds);

    this->minutes = this->seconds / 60;
    this->seconds %= 60;
    this->hours = this->minutes / 60;
    this->minutes %= 60;
}

long TimeSpan::getHour()
{
    return hours;
}

long TimeSpan::getMinute()
{
    return minutes;
}

long TimeSpan::getSecond()
{
    return seconds;
}

bool TimeSpan::isPositive()
{
    return positive;
}

long TimeSpan::getInSeconds() const
{
    return (hours * 3600 + minutes * 60 + seconds) * (positive ? 1 : -1);
}

ostream& operator<<(ostream& out, const TimeSpan& ts)
{
    out << (ts.positive ? "" : "-");
    out << ts.hours << ":" << setw(2) << setfill('0') << ts.minutes;
    out << ":" << setw(2) << setfill('0') << ts.seconds;

    return out;
}

bool TimeSpan::operator==(TimeSpan const& ts)
{
    return getInSeconds() == ts.getInSeconds();
}

bool TimeSpan::operator!=(TimeSpan const& ts)
{
    return !(*this == ts);
}

bool TimeSpan::operator>(TimeSpan const& ts)
{
    return getInSeconds() > ts.getInSeconds();
}

bool TimeSpan::operator<(TimeSpan const& ts)
{
    return getInSeconds() < ts.getInSeconds();
}

bool TimeSpan::operator>=(TimeSpan const& ts)
{
    return (*this >= ts);
}

bool TimeSpan::operator<=(TimeSpan const& ts)
{
    return (*this <= ts);
}

TimeSpan TimeSpan::operator+(TimeSpan const& ts)
{
    long sec;
    sec = getInSeconds() + ts.getInSeconds();

    TimeSpan res(0, 0, sec);

    return res;
}

TimeSpan TimeSpan::operator-(TimeSpan const& ts)
{
    long sec;
    sec = getInSeconds() - ts.getInSeconds();

    TimeSpan res(0, 0, sec);

    return res;
}

TimeSpan& TimeSpan::operator+=(TimeSpan const& ts)
{
    long sec;
    sec = getInSeconds() + ts.getInSeconds();

    TimeSpan res(0, 0, sec);

    this->hours = res.hours;
    this->minutes = res.minutes;
    this->seconds = res.seconds;

    return *this;
}

TimeSpan& TimeSpan::operator-=(TimeSpan const& ts)
{
    long sec;
    sec = getInSeconds() - ts.getInSeconds();

    TimeSpan res(0, 0, sec);

    this->hours = res.hours;
    this->minutes = res.minutes;
    this->seconds = res.seconds;

    return *this;
}

TimeSpan TimeSpan::operator*(const int val) {
    return TimeSpan(0, 0, getInSeconds() * val);
}