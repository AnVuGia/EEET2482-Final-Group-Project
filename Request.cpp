#include "Request.h"

using std::string;
using std::cout;
using std::cin;

//getter
string Request::get_req_from(){
    return this->req_from;
};
string Request::get_start_date(){
    return this->start_date.get_date();
};
string Request::get_end_date(){
    return this->end_date.get_date();
};
double Request::get_occ_rate(){
    return this->occ_rate;
}
int Request::get_status(){
    return this->status;
}
//setter
void Request::set_req_from(string username){
    this->req_from = username;
}
void Request::set_start_date(int day, int month, int year){
    this->start_date.set_date(day,month,year);
}
void Request::set_end_date(int day, int month, int year){
    this->end_date.set_date(day,month,year);
}
void Request::set_occ_rate(double rating){
    this->occ_rate = rating;
}
void Request::set_status(int stat){
    this->status = stat;
}
//
void Request::show_req(){
    cout <<"[ From: " << this->req_from << "\n"
        <<"Occupier rating: " << this->occ_rate <<"\n"
        <<"Period: " << this->get_start_date()<< " - " << this->get_end_date() <<"\n";
        switch (this->status)
        {
        case 0:
            cout << "Rejected ]";
            break;
        case 1:
            cout << "Pending ]";
            break;
        case 2:
            cout << "Accepted ]";
            break;
        default:
            cout << "Not valid ]";
            break;
        }
}   