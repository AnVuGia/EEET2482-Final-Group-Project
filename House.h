#include <iostream>
#ifndef HOUSE_H
#define HOUSE_H
using std::string;
class House{
    protected:
    double house_rating_score;
    string location;
    string description;
    public:
    string get_location();
    string get_description();
    void set_location(string location);
    void set_description(string des);
};
#endif