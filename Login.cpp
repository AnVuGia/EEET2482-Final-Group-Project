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


void login(Global &program){
    Member *temp;
    int is_valid = 0;
    string username;string pwd;
    cout << "Enter username: ";
    cin >> username;
    for(size_t i = 0; i < program.users.size(); i++){
        if(username == program.users[i].get_userName()){
            is_valid = 1;
            temp = &program.users[i];
        }
    }
    if(is_valid == 1){
        cout << "Enter your password: ";
        cin >> pwd;
        if(pwd == temp->get_pwd()){
            cout << "Log in success full!\n";
            cout <<"This is your menu: \n";
            cout <<"0. Exit \n";
            cout <<"1. View infomation \n";
            int choice = program.choice();
            if(choice == 1){
                temp->show_info();
            } else{
                cout << "Exit!";
            }
            
        } else{
            cout << "Wrong password!";
        }
    } else if(username == program.admin_username){
        cout << "Enter your password: ";
        cin >> pwd;
        if(pwd == program.admin_pwd){
            cout << "Welcome admin!\n";
            cout <<"User info: ";
        }
        for(size_t i = 0; i < program.users.size(); i++){
            program.users[i].show_info();
            cout << "\n";
        }
    }
    else{
        cout << "No user found...";
    }
}