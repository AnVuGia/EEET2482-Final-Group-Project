#include <iostream>
#include <vector>
#include "Date.h"
#include "Rating.h"
#include "Comment.h"
#include "Member.h"
#include <vector>
#ifndef HOUSE_H
#define HOUSE_H
using std::string;
using std::vector;
class House{
    protected:
    double house_rating_score = 0;
    double min_occupier_rating = 0;
    double consumming_point = 0;
    string location;
    string description;
    bool available = false;
    Date start_date;
    Date end_date;
    vector<Rating> ratings;
    Comment house_comments;
    public:
    House();
    House(string location, string description);
    void show_info();
    void set_available();
    void show_ratings();
    void show_short_info();
    void put_comment(string comment, Member& member);

    //getter method
    string get_location();
    string get_description();
    double get_houserate();
    double get_minoccrate();
    bool get_availalbe();
    string get_startdate();
    string get_enddate();
    int get_start_day_rata();
    int get_end_day_rata();
    Comment get_house_comments();
    
    //setter method
    void set_info(double houserate,double min_occ_rate, 
    string loca, string des, bool avail,string startdate,string enddate);
    void set_location(string location);
    void set_descrition(string des);
    void set_rating(Rating rate);
};
#endif