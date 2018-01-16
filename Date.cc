#include <iostream>
#include <iomanip>
#include <sstream>

#include "Date.h"

Date::Date(int d, int m, int y){
    setDate(d, m, y);
}

Date& Date::operator+=(int numDays){
    int tmpDays = this->convertToDays();
    tmpDays += numDays;
    this->setDate(tmpDays);

    return *this;
}

Date Date::operator+(int numDays){
    Date tmpDate = *this;

    tmpDate += numDays;
    return tmpDate;
}

bool Date::operator>(Date& d){
    return this->convertToDays() > d.convertToDays();
}

void Date::setDate(int d,int m,int y){
    day   = ( d > 0 && d <= 30) ? d : 0;
    month = ( m > 0 && m <= 12) ? m : 0;
    year = ( y > 0) ? y : 0;
}

void Date::setDate(int numDays){
    this->day   = (numDays % 360) % 30 ;
    this->month = (numDays % 360) / 30;
    this->year = numDays / 360;
    if(this->month == 0){
        this->month = 12;
        this->year -=1;
    }
}

int Date::convertToDays(){
    return (day + month*30 + year*360);
}

void Date::toString(string& outStr){
    ostringstream str;
    str << day << "/" << month << "/" << year;
    outStr += string(str.str());
}