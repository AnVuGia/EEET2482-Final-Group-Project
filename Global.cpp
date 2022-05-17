#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Member.h"
#include "Global.h"
#include "House.h"
#include "Request.h"
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
    std::stod(outp[5]), std::stod(outp[6]),std::stod(outp[7]), outp[8], outp[9], std::stoi(outp[10]),std::stod(outp[11]) 
    ,outp[12], outp[13], outp[14], outp[15]);
    int i = 16;
    // input house rating
    while(outp[i] !="EOHRATE"){
        cout << "in house rate";
        Rating house_rate(std::stod(outp[i]), outp[i+1]);
        user.add_house_rating(house_rate);
        i+=2;
    }
    i+=1;
    //input user rating
    while (outp[i] !="EOURATE")
    {   cout << "in user rate";
       Rating user_rate(std::stod(outp[i]), outp[i+1]);
       user.add_rating(user_rate);
       i+=2;
    }
    i+=1;
    //input peding/accepted request
    while(outp[i] != "END"){
        Request temp;
        temp.set_req(std::stoi(outp[i]),outp[i+1],std::stod(outp[i+2]),outp[i+3],outp[i+4]);
        user.set_request(temp);
        i+=5;
    }
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
        //output user
        myfile<< user.get_creds()<<","
        <<user.get_userName()<<","
        <<user.get_fullName()<<","
        <<user.get_phoneNumber()<<","
        <<user.get_pwd()<<","
        <<user.get_own_rating_score()<<","
        <<user.get_houserate()<<","
        <<user.get_minocrate()<<","
        <<user.get_house_loca()<<","
        <<user.get_house_des()<<","
        <<user.get_house_avail()<<","
        <<user.get_house_cons_point()<<","
        <<user.get_house_startdate()<<","
        <<user.get_house_enddate()<<","
        <<user.get_occupier_name()<<","
        <<user.get_occupying_name()<<",";
        //output house rating
        if(user.get_own_house().get_ratings().size() > 0){
            for (auto rate : user.get_own_house().get_ratings()){
                myfile << rate.getScore() <<","
                <<rate.getComment() << ",";
            }
        }
        myfile << "EOHRATE" <<",";
        //output user rating
        if(user.get_ratings().size() > 0){
            for (auto user_rate : user.get_ratings()){
                myfile << user_rate.getScore() <<","
                <<user_rate.getComment() <<",";
            }
        }
        myfile <<"EOURATE" <<",";
        //output requests
        for(auto req: user.get_req_list()){
            if(user.get_req_list().size() > 0 && req.get_status() != 0){
                myfile << req.get_status() <<","
                    << req.get_req_from() <<","
                    <<req.get_occ_rate()<<","
                    <<req.get_start_date()<<","
                    << req.get_end_date() <<",";
            }
        }
        myfile <<"END\n"; 
    }
    cout << "\n File saved!";
    myfile.close();
}
void Global::user_register(){
    stringstream ss;
    string temp;
    cout << "In register: \n";
    bool token = 1;
    do
    {  token = 0;
        cout <<"\nEnter new username: ";
        cin >> temp;
        for(auto user: this->users){
            if(temp == user.get_userName()){
                cout << "\nusername already exist\n";
                token = 1;
            }
        }
    } while (token);
    ss<<600<<",";
    ss<<temp<<",";
    cout <<"\nEnter your fullname: ";
    std::getline(cin >> std::ws, temp);
    ss<<temp<<",";
    cout << "\nEnter your phone number: ";
    cin >>  temp;
    ss<<temp<<",";
    cout <<"\nEnter your password: ";
    cin >> temp;
    ss<<temp<<",";
    ss<<"0"<<",";ss<<"0"<<","<<"0"<<","; //own rating, occ rate,houserate
    cout << "\nEnter your house location (Hanoi, Saigon, Da Nang): ";
    std::getline(cin >> std::ws, temp);
    ss<<temp<<",";
    cout << "\nEnter your house description : ";
    std::getline(cin >> std:: ws, temp);
    ss<<temp<<","; 
    ss<<0<<","<<"0"<<","<<"0 0 0"<<","<<"0 0 0"<<","<<"0"<<","<<"0"<<","
    <<"EOHRATE"<<","<<"EOURATE"<<","<<"END"; //avail,cons_point,startdate,enddate,occupier,occupiyng,END
    Member user_temp; 
    inputUserData(user_temp, ss.str());
    this->users.push_back(user_temp);
    this->CurrentUser = &user_temp;
}  

