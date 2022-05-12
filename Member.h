#include <iostream>
#include "House.h"
#ifndef MEMBER_H
#define MEMBER_H
using std::string;
class Member {
    protected:
    int creditPoints;
    string userName;
    string fullName;
    string phoneNumber;
    string pwd;
    double occupier_rating_score;
    House own_house;
    public:
    Member(){};
    void show_info();
    void set_info(int creditPoints, string userName, string fullName, 
    string phoneNumber, string pwd, double houserate, double min_ocrate
    ,string loca,string des,bool avail,string startdate, string enddate);
    void list_house();
    //getter methods
    int get_creds();
    string get_pwd();
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
};
#endif