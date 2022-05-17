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
        <<"Credit: "<< this->creditPoints << "\n"
        << "Rating: " << this->own_rating_score
        <<"\nHouse: ";
        this->own_house.show_info();
}
void Member::set_info(double creditPoints, string userName, string fullName, string phoneNumber, string pwd,double own_rating,
 double houserate, double min_ocrate ,string loca,string des,bool avail,double cons_point,
 string startdate, string enddate, string occupier_name, string occupying_name){
        this->creditPoints = creditPoints;
        this->userName = userName;
        this->fullName = fullName;
        this->phoneNumber = phoneNumber;
        this->pwd = pwd;
        this->own_house.set_info(houserate,min_ocrate,cons_point,loca,des,avail,startdate,enddate);
        this->own_rating_score = own_rating;
        this->occupier_name = occupier_name;
        this->occupying_name = occupying_name;
    }
void Member::show_requests(){
    cout << "\nCurrent requests: " << std::endl;
    int i = 1;
    for(Request r: this->requests){
        cout << i << ". ";
        r.show_req();
        i++;
    }
}
void Member::show_user_ratings(){
    int i =1;
    cout << "User's ratings: " << std::endl;
    for (Rating r: this->ratings) {
        cout << i << ". Score: " << r.getScore() << " || Comment: " << r.getComment() << std::endl;
        i++; 
    }
}
double Member::rating_score(vector<Rating> ratings){
        double num, sum, rating;
        if(ratings.size()>0){
            for(Rating r: ratings){
                sum += r.getScore();
                num++; 
            }
            rating = sum/num;
        }else{return rating;}
        return rating;
        }
void Member::show_house_ratings(){
    this->own_house.show_ratings();
}
//getter method
string Member::get_pwd(){
    return this->pwd;
}
House Member::get_own_house(){
    return this->own_house;
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
double Member::get_creds(){
    return this->creditPoints;
}
void Member::get_full_house_info(){
    this->own_house.show_info();
}
double Member::get_own_rating_score(){
    return this->own_rating_score;
}
double Member::get_house_cons_point(){
    return this->own_house.get_conspoint();
};
int Member::get_start_value(){
    return this->own_house.get_start_day_rata();
}
int Member::get_end_value(){
    return this->own_house.get_end_day_rata();
}

vector<Rating> Member::get_ratings(){
    return this->ratings;
}
//

vector <Request>Member:: get_req_list(){
    return this->requests;
}
void Member::list_house(){
    this->own_house.set_available();
}
//setter
void Member::set_own_rating_score(double score){
    this->own_rating_score = score;
}
void Member::set_house_rating_score(double score){
    this->own_house.set_house_rating_score(score);
};

void Member::set_credits(double creds){
    this->creditPoints = creds;
}

void Member::set_request(Request req){
    this->requests.push_back(req);
}

void Member::set_occupier(Member mem){
    this->occupier = &mem;
};
void Member::set_occupying(Member mem){
    this->occupying = &mem;
};

string Member::get_occupier_name(){
    if(this->occupier == NULL){
        return "0";
    } else{
        return this->occupier->get_fullName();
    }
};
string Member::get_occupying_name(){
    if(this->occupying == NULL){
        return "0";
    } else{
        return this->occupying->get_fullName();
    };
}
    

void Member::add_rating(Rating rate){
    this->ratings.push_back(rate);
}
void Member::add_house_rating(Rating rate){
    this->own_house.add_rating(rate);
};
void Member::minus_credit(double ammount){
    this->creditPoints -= ammount;
};
void Member::add_credit(double ammount){
    this->creditPoints += ammount;
};


