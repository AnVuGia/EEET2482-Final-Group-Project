#include <iostream>
#include <vector>
#include "Member.h"
#ifndef COMMENT_H
#define COMMENT_H
using std::string;
using std::vector;

class Comment{
    protected:
        vector<string> comments;
        vector<Member> members;
    public:
        void add_comment(string comment, Member& member);
        void display_comment();
    //constructor
    Comment(){};
};


#endif