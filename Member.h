#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <vector>
#include "House.h"
#include "Request.h"
#include "Rating.h"
using std::string;
using std::vector;

class Member {
    protected:
        int creditPoints;
        string userName;
        string fullName;
        string phoneNumber;
        string pwd;
        double own_rating_score;
        House own_house;
        vector<Rating> ratings;
        vector <Request> requests;
        Member *occupier; // thằng này đang thuê nhà của super
        Member *occupying; // super đang thuê nhà của thằng này
    public:
        Member(){};
        //methods
        void show_info();
        void set_info(int creditPoints, string userName, string fullName, 
        string phoneNumber, string pwd,double own_rating, double houserate, double min_ocrate
        ,string loca,string des,bool avail,string startdate, string enddate);
        void list_house();
        void show_requests();
        void show_house_ratings();

        //getter methods
        int get_creds();
        string get_pwd();
        House get_own_house();
        string get_userName();
        string get_fullName();
        string get_phoneNumber();
        double get_houserate();
        double get_minocrate();
        string get_house_loca();
        string get_house_des();
        bool get_house_avail();
        string get_house_startdate();
        string get_house_enddate();
        double get_own_rating_score();
        void get_full_house_info();
        void get_borrowed_house_from();
        vector <Request> get_req_list();
        int get_start_value();
        int get_end_value();
        vector<Rating> get_ratings();
        string get_occupier_name();
        string get_occupying_name();
        void return_house();

        //setter
        void set_credits(int creds);
        void set_request(Request req);
        void set_rating(Rating rate);
        void set_house_rating(Rating rate);
        void set_occupier(Member mem);
        void set_occupying(Member mem);
    
        void rate_occupiers();
};
#endif