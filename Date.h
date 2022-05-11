#include <iostream>
#ifndef DATE_H
#define DATE_H
using std::string;
class Date{
    int day;
    int month;
    int year;
    public:
    Date();
    Date(int day, int month, int year);    
    int rata_die_days();
    void set_date(int day, int month, int year);
    string get_date();
};


#endif