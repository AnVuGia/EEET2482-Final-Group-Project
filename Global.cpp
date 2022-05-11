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
    user.set_info(std::stoi(outp[0]), outp[1], outp[2], outp[3], outp[4], 
    std::stod(outp[5]), std::stod(outp[6]),outp[7], outp[8], std::stoi(outp[9]), outp[10], outp[11]);
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

void Global::end(){
    std::fstream myfile;
    myfile.open("output.txt", std::ios::out);
    if(!myfile){
        cout << "Cannot open File";
    }
    string outp;
    for(auto user: this->users){
        myfile<< user.get_creds()<<","
        <<user.get_userName()<<","
        <<user.get_fullName()<<","
        <<user.get_pwd()<<","
        <<user.get_houserate()<<","
        <<user.get_minocrate()<<","
        <<user.get_house_loca()<<","
        <<user.get_house_des()<<","
        <<user.get_house_avail()<<","
        <<user.get_house_startdate()<<","
        <<user.get_house_enddate()<<"\n";
    }
    cout << "\n File saved!";
    myfile.close();
}

