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
    string get_location();
    string get_description();
    void set_available();
    void show_info();
    void set_info(double houserate,double min_occ_rate, 
    string loca, string des, bool avail,string startdate,string enddate);
};
#endif