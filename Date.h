#include <iostream>
#ifndef DATE_H
#define DATE_H
using std::string;
class Date{
    int day = 0;
    int month = 0;
    int year = 0;
    public:
    Date();
    Date(int day, int month, int year);    
    int rata_die_days();
    void set_date(int day, int month, int year);
    string get_date();
    int get_day();
    string format();
};


#endif