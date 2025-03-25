#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{
  int totalMins = this->getMinutes() + other.getMinutes();
  int totalHours = this->getHours() + other.getHours() + totalMins / 60;
  totalMins %= 60;
  return Time(totalHours, totalMins);
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{
  this->minutes += other.minutes;
  this->hours += other.hours + this->minutes / 60;
  this->minutes %= 60;
  return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
  if (this->hours != other.hours){
    return this->hours < other.hours;
  }
  return this->minutes < other.minutes;
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
  if(this->hours != other.hours){
    return this->hours > other.hours;
  }
  return this->minutes > other.minutes;
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
  if (this->hours != other.hours)
  {
    return false;
  }
  return this->minutes == other.minutes;
  
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
  os << (tm.hours < 10 ? "0" : "") << tm.hours << ":" << (tm.minutes < 10 ? "0" : "") << tm.minutes;
  return os;
}
