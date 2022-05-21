#include <iostream>
#include <sstream>
#include "Date.h"
// constructor
Date::Date(){};

//date setup
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

// 
int Date::rata_die_days(){
    if(this->month < 3) {
        year--;
        month += 12;
    }
    return 365*this->year + this->year/100 + this->year/400 + (153*this->month - 457 )/5 +this->day-306;
};

//get date from user input when add house
string Date::get_date(){
    std::stringstream ss;
    ss << this->day <<" " <<this->month <<" "<<this->year;
    return ss.str();
}

// get date when user find suitable location
int Date::get_day(){
    return this->day;
}

// format for date input
string Date::format(){
    std::stringstream ss;
    ss << this->day <<"/" <<this->month <<"/"<<this->year;
    return ss.str();
}