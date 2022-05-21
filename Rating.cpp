#include "Rating.h"
#include <cstring>
using std::cout;
Rating::Rating(){};

//setup for rating
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
// show rating function
void Rating::show_rating(){
    cout << "[ Score: "<< this->score <<" || "<< "Comment: " << this->comment << " ]\n";
}