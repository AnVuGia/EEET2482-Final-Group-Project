#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>
#include "Date.h"
#include "Rating.h"
#include <vector>
#include "Request.h"
using namespace std;

class House{
    protected:
        double house_rating_score = 0;
        double min_occupier_rating = 0;
        double consuming_point = 0;
        string location;
        string description;
        bool available = false;
        Date start_date;
        Date end_date;
        vector<Rating> ratings;
    public:
        House() {};
        House(string location, string description);
        void show_info();
        void set_available();
        void show_ratings();
        void show_short_info();

        //getter method
        string get_location();
        string get_description();
        double get_houserate();
        double get_minoccrate();
        double get_conspoint();
        bool get_availalbe();
        string get_startdate();
        string get_enddate();
        int get_start_day_rata();
        int get_end_day_rata();
        vector<Rating> get_ratings();

        //setter method
        void set_info(double houserate,double min_occ_rate,double consuming_point, 
        string loca, string des, bool avail,string startdate,string enddate);
        void set_location(string location);
        void set_descrition(string des);
        void set_house_rating_score(double score);
        void add_rating(Rating rate);
};

#endif