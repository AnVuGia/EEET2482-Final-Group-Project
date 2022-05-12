#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Member.h"
#include "Global.h"
#include "Login.h"
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::stringstream;


void login(Global *program){
    int is_valid = 0;
    string username;string pwd;
    cout << "Enter username: ";
    cin >> username;
    for(size_t i = 0; i < program->users.size(); i++){
        if(username == program->users[i].get_userName()){
            is_valid = 1;
            program->CurrentUser = &program->users[i];
        }
    }
    if(is_valid == 1){
        cout << "Enter your password: ";
        cin >> pwd;
        if(pwd == program->CurrentUser->get_pwd()){

            cout << "Log in success full!\n";
            cout <<"This is your menu: \n";
            cout <<"0. Exit \n";
            cout <<"1. View infomation \n";
            int choice = program->choice();
            if(choice == 1){
                program->CurrentUser->show_info();
            } else{
                cout << "Exit!";
            }
            
        } else{
            cout << "Wrong password!";
        }
    } else if(username == program->admin_username){
        cout << "Enter your password: ";
        cin >> pwd;
        if(pwd == program->admin_pwd){
            cout << "Welcome admin!\n";
            cout <<"User info: ";
        }
        for(size_t i = 0; i < program->users.size(); i++){
            program->users[i].show_info();
            cout << "\n";
        }
    }
    else{
        cout << "No user found...";
    }
};
void user_register(Global *program){
    vector <string> inp;
    string temp;
    cout << "In register: \n";
    bool token = 1;
    while (token)
    {
       cout <<"\nEnter username: ";
        cin >> temp;
        for(auto user: program->users){
            if(temp == user.get_userName()){
                cout << "\nusername already exist\n"
                return;
            }
        }
        inp.push_back(temp);
        cout <<"\nEnter your fullname: "
        std::getline(cin, temp);
        inp.push_back(temp);
        cout << "\nEnter your phone number: ";
        cin >>  temp;
        inp.push_back(temp);
        cout << "\nEnter your house location: ";
        std::getline(cin, temp);
        inp.push_back(temp);
        cout << "\nEnter your house description : ";
        std::getline(cin, temp);
        inp.push_back(temp); 
    }  
}