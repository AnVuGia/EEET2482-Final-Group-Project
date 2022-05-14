#ifndef RATING_H
#define RATING_H
#include <iostream>
using std::string;

class Rating{
    double score;
    string comment;
    public:
    Rating();
    Rating(int score, string comment);
    double getScore();
    string getComment();
};
#endif