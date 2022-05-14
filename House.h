#include <iostream>
#include <vector>
#include "Date.h"
#include "Member.h"
#ifndef HOUSE_H
#define HOUSE_H
using std::string;
using std::vector;
class House{
<<<<<<< HEAD
    protected:
    double house_rating_score = 0;
    double min_occupier_rating = 0;
    double consumming_point = 0;
=======
    double house_rating_score;
>>>>>>> origin/hung
    string location;
    string description;
    bool available = false;
    Date start_date;
    Date end_date;
    // Member renter;
    vector<string> house_comments;

    public:
    House();
    House(string location, string description);
    void show_info();
    void show_short_info(); // câu 2
    void set_available();

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
    vector<string> get_house_comments(); // câu 9 (để sẳn)

    //setter method
    void set_info(double houserate,double min_occ_rate, 
    string loca, string des, bool avail,string startdate,string enddate);
    void set_location(string location);
    void set_descrition(string des);
    void add_house_comments(string comment);
};
#endif