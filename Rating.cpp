#include "Rating.h"
#include <cstring>
using std::cout;
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

void Rating::show_rating(){
    cout << "[ Score: "<< this->score <<" || "<< "Comment: " << this->comment << " ]\n";
}