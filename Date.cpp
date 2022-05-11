#include <iostream>
#include <sstream>
#include "Date.h"
Date::Date(){};
Date::Date(int day, int month, int year){
       this->day = day;
        this->month = month;
        this->year = year;
}
void Date::set_date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}
int Date::rata_die_days(){
    if(this->month < 3) {
        year--;
        month += 12;
    }
    return 365*this->year + this->year/100 + this->year/400 + (153*this->month - 457 )/5 +this->day-306;
};
string Date::get_date(){
    std::stringstream ss;
    ss << this->day <<" " <<this->month <<" "<<this->year;
    return ss.str();
}
int Date::get_day(){
    return this->day;
}