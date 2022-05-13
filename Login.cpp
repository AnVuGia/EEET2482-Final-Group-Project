#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Member.h"
#include "Global.h"
#include "Login.h"
#include "Member.h"
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
void choose_house(Member *currenUser, Member *chosenUser){
  
}
void find_suitable_house(Member *currentUser,Global *program){
    //vector_ptr để lưu địa chỉ của obj user
    vector <Member*> mem;
    string city;
    do
    {
        cout <<"\nEnter your city: (Hanoi, Saigon, Da Nang)\n";
        std::getline(cin >>std::ws, city);
        int count = 1;
         //chạy qua vector program->users để kiếm địa chỉ phù hợp với điều kiện available && ==loca
        for(int i = 0; i < program->users.size(); i++){
             if(program->users[i].get_house_loca() == city 
             && program->users[i].get_house_avail() == 1 && 
             &program->users[i] != program->CurrentUser){
                mem.push_back(&program->users[i]);
                cout << "House no." <<count <<":\n";
                program->users[i].get_full_house_info();
            }
        }
        if(mem.size() == 0){
            cout << "No house availabel in "<< city<<" ,do you want to choose again? " <<"\n";
            cout << "0. Exit\n";
            cout << "1. Again\n";
            int user_choice = program->choice();
            if(user_choice == 0){
                cout << "Exit!\n";
                return;
            } else if(user_choice > 1 || user_choice < 0){
                cout << "Invalid input";
                return;
            }
        }        
    } while (!mem.size());
    
    //User chọn thành phố cho riêng mình (q7)
    string choice;
    bool token = true;
        do
        {   
            //Nhập vào lựa chọn của user
            cout <<"\nEnter your choice: (house no:)";
            cin >> choice;
            int int_choice = std::stoi(choice);
            if(int_choice > mem.size() || int_choice <= 0){
                //Trường hợp lựa chọn của user vượt qua vector.size()
                cout << "\nNot a valid choice, do you want to choose again?\n";
                cout << "0. Exit\n";
                cout << "1. Again\n";
                int user_choice = program->choice();
                if(user_choice == 0){
                    token = false;
                    cout << "Exit!\n";
                    return;
                } else if(user_choice > 1 || user_choice < 0){
                    cout << "Invalid input";
                    return;
            }
            }else{
                //print ra lựa chọn của user
                cout <<"\nYour house choice is: "<<"\n"; 
                mem[int_choice-1]->get_full_house_info();
                token = false;
            }
        } while (token);
}
