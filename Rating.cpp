#include "Rating.h"
#include <cstring>
Rating::Rating(){};
Rating::Rating(double score, string comment){
    this->score = score;
    this->comment = comment;
};

double Rating::getScore(){
    return this->score;
};
string Rating::getComment(){
    return this->comment;
};