#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Member.h"
#include "Global.h"
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::stringstream;

Global::Global(){};
void Global::inputUserData(Member &user, string line){
    stringstream ss(line);
    vector<string> outp;
    string token;
    while(std::getline(ss, token, ',')){
        outp.push_back(token);
    }
    user.creditPoints = stoi(outp[0]);
    user.userName = outp[1];
    user.fullName = outp[2];
    user.phoneNumber = outp[3];
    user.pwd = outp[4];
}
void Global::inputData(){
    std::fstream myfile;
    myfile.open("data.txt", std::ios::in);
    if(!myfile){
        cout << "Cannot open file!";
    }
    string inp;
    while (!myfile.eof())
    {   
        std::getline(myfile, inp);
        Member temp;
        inputUserData(temp, inp);
        this->users.push_back(temp);
    }
    myfile.close();
}
int Global::choice(){
    int choice;
    cout << "\nEnter your choice: ";
    cin >> choice;
    return choice;
}

