#include "Member.h"
#include <iostream>
#include <vector>
#include <sstream>
using std::string;
using std::cout;
using std::cin;
using std::vector;
void Member::show_info(){
    cout<< "[ User name: "<< this->userName <<"\n"
        << "Full name: "<< this->fullName <<"\n"
        <<"Credit: "<< this->creditPoints <<"\nHouse: ";
        this->own_house.show_info();
}
void Member::set_info(int creditPoints, string userName, string fullName, 
    string phoneNumber, string pwd,double own_rating, double houserate, double min_ocrate
    ,string loca,string des,bool avail,string startdate, string enddate){
        this->creditPoints = creditPoints;
        this->userName = userName;
        this->fullName = fullName;
        this->phoneNumber = phoneNumber;
        this->pwd = pwd;
        this->own_house.set_info(houserate,min_ocrate,loca,des,avail,startdate,enddate);
        this->own_rating_score = own_rating;
    }

//getter method
string Member::get_pwd(){
    return this->pwd;
}
string Member::get_fullName(){
    return this->fullName;
}
string Member::get_userName(){
    return this->userName;
}
string Member::get_phoneNumber(){
    return this->phoneNumber;
}
double Member::get_houserate(){
    return this->own_house.get_houserate();
}
double Member::get_minocrate(){
    return this->own_house.get_minoccrate();
}
string Member::get_house_loca(){
    return this->own_house.get_location();
}
string Member::get_house_des(){
    return this->own_house.get_description();
}
bool Member::get_house_avail(){
    return this->own_house.get_availalbe();
}
string Member::get_house_startdate(){
    return this->own_house.get_startdate();
}
string Member::get_house_enddate(){
    return this->own_house.get_enddate();
}
int Member::get_creds(){
    return this->creditPoints;
}
void Member::get_full_house_info(){
    this->own_house.show_info();
}
double Member::get_own_rating_score(){
    return this->own_rating_score;
}
int Member::get_start_value(){
    return this->own_house.get_start_day_rata();
}
int Member::get_end_value(){
    return this->own_house.get_end_day_rata();
}
//

vector <Request>Member:: get_req_list(){
    return this->requests;
}
void Member::list_house(){
    this->own_house.set_available();
}
//setter

void Member::set_credits(int creds){
    this->creditPoints = creds;
}

void Member::set_request(Request req){
    this->requests.push_back(req);
}
