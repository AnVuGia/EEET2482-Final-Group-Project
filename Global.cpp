#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Member.h"
#include "Global.h"
#include "House.h"
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
    user.set_info(stoi(outp[0]), outp[1], outp[2], outp[3], outp[4], outp[5], outp[6]);
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

