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
        double creditPoints = 500;
        string userName;
        string fullName;
        string phoneNumber;
        string pwd;
        double own_rating_score;
        House own_house;
        vector<Rating> ratings;
        vector<Request> requests;
        string occupier_name = "0";
        string occupying_name = "0";
        Member *occupier = NULL; // thằng này đang thuê nhà 
        Member *occupying = NULL; // đang thuê nhà của thằng này
    public:
        Member(){};
        //methods
        void show_info();
        void set_info(double creditPoints, string userName, string fullName, string phoneNumber, string pwd,double own_rating,
        double houserate, double min_ocrate ,string loca,string des,bool avail,double cons_point,string startdate, string enddate, string occupier_name, string occupying_name);
        void list_house();
        void show_requests();
        void show_house_ratings();
        void show_user_ratings();
        double rating_score(vector<Rating> ratings);
        void reset_requests();

        //getter methods
        double get_creds();
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
        double get_house_cons_point();
        void get_full_house_info();
        void get_borrowed_house_from();
        vector <Request> get_req_list();
        int get_start_value();
        int get_end_value();
        vector<Rating> get_ratings();
        Member* get_occupier();
        Member* get_occupying();
        string get_occupier_name();
        string get_occupying_name();

        //setter
        void set_own_rating_score(double score);
        void set_house_rating_score(double score);
        void set_credits(double creds);
        void set_request(Request req);
        void set_occupier(Member *mem);
        void set_occupying(Member *mem);

        void add_rating(Rating rate);
        void add_house_rating(Rating rate);
        void minus_credit(double ammount);
        void add_credit(double ammount);
        void set_house_available(bool available);
};
#endif