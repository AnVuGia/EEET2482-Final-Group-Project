#include <iostream>
#ifndef DATE_H
#define DATE_H
using std::string;
class Date{
    int day;
    int month;
    int year;
    public:
    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }
    int rata_die_days();
};


#endif