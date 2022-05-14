#include "Request.h"
#include <sstream>
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
void Request::set_req(int status, string req_from, double occ_rate, string start_date, string end_date){
    this->status = status;
    this->req_from = req_from;
    this->occ_rate = occ_rate;
    std::stringstream sstart(start_date);
    int day,month,year;
    sstart >>day>>month>>year;
    this->start_date.set_date(day,month,year);
    std::stringstream ssend(end_date);
    ssend>>day>>month>>year;
    this->end_date.set_date(day,month,year);
}
void Request::show_req(){
    cout <<"[ From: " << this->req_from << " || "
        <<"Occupier rating: " << this->occ_rate <<" || "
        <<"Period: " << this->start_date.format()<< " - " << this->end_date.format() <<" || ";
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