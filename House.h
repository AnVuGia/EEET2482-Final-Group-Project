#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>
#include "Date.h"
#include "Rating.h"
#include <vector>
#include "Request.h"
using namespace std;

class Member;

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
        // vector <Member>occupiers;
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
        bool get_availalbe();
        string get_startdate();
        string get_enddate();
        int get_start_day_rata();
        int get_end_day_rata();
        vector <Member> get_occupiers();

        //setter method
        void set_info(double houserate,double min_occ_rate, 
        string loca, string des, bool avail,string startdate,string enddate);
        void set_location(string location);
        void set_descrition(string des);
        void set_rating(Rating rate);
        void add_occupier(Member occupier);
};

// class Member {
//     protected:
//         int creditPoints;
//         string userName;
//         string fullName;
//         string phoneNumber;
//         string pwd;
//         double own_rating_score;
//         House own_house;
//         vector<Rating> ratings;
//         vector <Request> requests;
//     public:
//         Member(){};
//         //methods
//         void show_info();
//         void set_info(int creditPoints, string userName, string fullName, 
//         string phoneNumber, string pwd,double own_rating, double houserate, double min_ocrate
//         ,string loca,string des,bool avail,string startdate, string enddate);
//         void list_house();
//         void show_requests();
//         void show_house_ratings();
//         //getter methods
//         int get_creds();
//         string get_pwd();
//         House get_own_house();
//         string get_userName();
//         string get_fullName();
//         string get_phoneNumber();
//         double get_houserate();
//         double get_minocrate();
//         string get_house_loca();
//         string get_house_des();
//         bool get_house_avail();
//         string get_house_startdate();
//         string get_house_enddate();
//         double get_own_rating_score();
//         void get_full_house_info();
//         void get_borrowed_house_from();
//         vector <Request> get_req_list();
//         int get_start_value();
//         int get_end_value();
//         vector<Rating> get_ratings();
//         //setter
//         void set_credits(int creds);
//         void set_request(Request req);
//         void set_rating(Rating rate);
//         void set_house_rating(Rating rate);
//         void accept_request();

//         void rate_occupiers();
// };

#endif