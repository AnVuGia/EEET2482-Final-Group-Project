#ifndef GLOBAL_H
#define GLOBAL_H
#include <iostream>
#include <vector>
#include "Member.h"
using std::string;
using std::vector;
using std::stringstream;
class Global{
    public:
    const string admin_username = "admin";
    const string admin_pwd = "admin";
    Global();
    vector <Member>users;
    Member *CurrentUser;
    void inputUserData(Member &user, string line);
    void inputData();
    int choice();
    void user_register();
    void end();
};
#endif