#ifndef RATING_H
#define RATING_H
#include <iostream>
using std::string;
// g++ Date.cpp Global.cpp House.cpp Login.cpp MainPage.cpp Member.cpp

class Rating{
    
    double score;
    string comment;

    public:
    Rating();
    Rating(double score, string comment);
    double getScore();
    string getComment();
};
#endif