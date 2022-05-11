#include "Member.h"
#include <iostream>
using std::string;
using std::cout;
using std::cin;
void Member::show_info(){
    cout<< "[ User name: "<< this->userName <<"\n"
        << "Full name: "<< this->fullName <<"\n"
        <<"Credit: "<< this->creditPoints <<"\nHouse: "
        << this->own_house.get_location()<<"\ndescription: " << this->own_house.get_description() << "]";
}
void Member::set_info(int creditPoints, string userName, string fullName, 
    string phoneNumber, string pwd, double houserate, double min_ocrate
    ,string loca,string des,bool avail,string startdate, string enddate){
        this->creditPoints = creditPoints;
        this->userName = userName;
        this->fullName = fullName;
        this->phoneNumber = phoneNumber;
        this->pwd = pwd;
        this->own_house.set_info(houserate,min_ocrate,loca,des,avail,startdate,enddate);
    }
string Member::get_pwd(){
    return this->pwd;
}
string Member::get_userName(){
    return this->userName;
}

