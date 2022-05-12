#include <iostream>
#include "Date.h"
#ifndef HOUSE_H
#define HOUSE_H
using std::string;
class House{
    protected:
    double house_rating_score = 0;
    double min_occupier_rating = 0;
    string location;
    string description;
    bool available = false;
    Date start_date;
    Date end_date;
    public:
    House();
    House(string location, string description);
    void show_info();
    
    void set_available();
    //getter method
    string get_location();
    string get_description();
    double get_houserate();
    double get_minoccrate();
    bool get_availalbe();
    string get_startdate();
    string get_enddate();
    //setter method
    void set_info(double houserate,double min_occ_rate, 
    string loca, string des, bool avail,string startdate,string enddate);
    void set_location(string location);
    void set_descrition(string des);
};
#endif