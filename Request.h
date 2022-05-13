#include <iostream>
#ifndef REQUEST_H
#define REQUEST_H
#include "Date.h"
using std::string;
class Request{
    //status 0: reject, 1: Pending, 2:Accepted
    int status = 1;
    string req_from;
    double occ_rate;
    Date start_date;
    Date end_date;
    public:
    //getter
    string get_req_from();
    string get_start_date();
    string get_end_date();
    double get_occ_rate();
    int get_status();
    //setter
    void set_req_from(string username);
    void set_start_date(int day, int month, int year);
    void set_end_date(int day, int month, int year);
    void set_occ_rate(double rating);
    void set_status(int stat);
    //
    void show_req();
};

#endif