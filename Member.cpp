#include "Member.h"
#include <iostream>
using std::string;
using std::cout;
using std::cin;
void Member::change_password(){
    cout << "Input ";
}
void Member::show_info(){
    cout<< "[ User name: "<< this->userName <<"\n"
        << "Full name: "<< this->fullName <<"\n"
        <<"Credit: "<< this->creditPoints <<"\nHouse: "
        << this->own_house.location<<"\ndescription: " << this->own_house.description << "]";
}
