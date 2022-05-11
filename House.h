#include <iostream>
#include "Date.h"
#ifndef HOUSE_H
#define HOUSE_H
using std::string;
class House{
    protected:
    double house_rating_score;
    double min_occupier_rating;
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
    void set_location(string location);
    void set_description(string des);
    void set_available();
    void show_info();
};
#endif