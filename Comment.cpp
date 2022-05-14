#include <iostream>
#include <vector>
#include "Comment.h"
using namespace std;


void Comment::add_comment(string comment, Member& member){
    this->comments.push_back(comment);
    this->members.push_back(member);
}

void Comment::display_comment(){
    for(int i=0; i<this->members.size(); i){
        cout << this->members[i].get_fullName() << " " << this->comments[i] << endl;
    }
}