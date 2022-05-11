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
    string get_pwd();
    string get_userName();
};
#endif