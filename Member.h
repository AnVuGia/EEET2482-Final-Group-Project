#include <iostream>
#include "House.h"
#ifndef MEMBER_H
#define MEMBER_H
using std::string;
class Member {
    public:
    int creditPoints;
    string userName;
    string fullName;
    string phoneNumber;
    string pwd;
    double occupier_rating_score;
    House own_house;
    Member(){};
    void change_password();
    void show_info();
};
#endif