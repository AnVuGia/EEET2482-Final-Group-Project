#include <iostream>
#include "Login.h"
#include "Member.h"
#include "Global.h"
#include "House.h"
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::stringstream;
Global program;
void guest_route();
void member_route();
void admin_route();
void print_header(){
    cout << "\n\nEEET2482/COSC2082 ASSIGNMENT\n";
    cout << "VACATION HOUSE EXCHANGE APPLICATION";
    cout << "\n\n";
    cout << "Instructor: Mr. Linh Tran" <<"\n"
        << "Group: 25" <<"\n"
        << "s3926888, An Vu" <<"\n"
        << "s3911246, Hung Nguyen" <<"\n"
        << "s3818775, Truong Thanh Long " <<"\n"
        << "s3820373, Thinh Vu " <<"\n";
}
void layer_1(){
    int choice;
    cout << "\nUse the app as: 1. Guest  2. Member   3.  Admin   4.Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        guest_route(); 
        break;
    case 2:
        int state ;
        state = login(&program);
        if(state == 1){
            member_route();
        } else {
            cout << " Please try again\n";
            layer_1();
        }
        break;
    case 3:
        admin_route();
        break;
    default:
        break;
    }
}
void admin_route(){
    string user_inp, pwd;
    cout <<"Enter admin username: ";
    cin >> user_inp;
    if(user_inp == program.admin_username){
        cout << "Enter password: ";
        cin >> pwd;
        if(pwd == program.admin_pwd){
            cout << "In admin: " << endl;
            for(auto user: program.users){
                user.show_info();
            }
            cout<<"-------------------------------------------------------------------------------------------------------";
            cout <<"\n0. Exit";
            cout <<"\n1. Return" << endl;
            int choice = program.choice();
            if(choice == 1){
                layer_1();
            } else{
                return;
            }
        }
    } else{
        cout << "Wrong admin username!";
    }
}
void guest_route(){
    int choice;
    cout << "You are a guest!\n";
    cout<<"0. Exit\n";
    cout << "1. Show info (shortened version): ";
    cout <<"\n2. Register";
    choice = program.choice();
    switch (choice)
    {
    case 1:
        int choice_1;
        for(auto user: program.users){
            user.get_own_house().show_short_info();
        }
        cout <<"0. Back\n";
        cout <<"1. Register\n";
        choice_1 = program.choice();
        if(choice_1 == 0){
            layer_1();
        } else if(choice_1 == 1){
            program.user_register();
            cout << program.CurrentUser;
            member_route();
        } else{
            return;
        }
        break;
    case 2:
        program.user_register();
        member_route();
        break;
    case 0:
        cout << "Exit!";
        return;
    default:
        cout << "Not valid!";
        break;
    }
    
}
void member_route(){
    int choice;
    cout <<"\n\nHi " <<program.CurrentUser->get_userName()<<"\n";
    cout <<"What do you want to do?: \n";
    cout <<"0. Exit\n";
    cout <<"1. Show info\n";
    cout <<"2. Show request\n";
    cout <<"3. List your house\n";
    cout <<"4. Find house (Hanoi, Saigon, Da Nang)\n";
    cout <<"5. Rate your occupying house/occupier\n";
    choice = program.choice();
    switch (choice)
    {
    case 0:
        //go back
        program.CurrentUser = NULL;
        layer_1();
        break;
    case 1:
        //show info
        int choice_1;
        program.CurrentUser->show_info();
        cout <<"0. Exit\n";
        cout <<"1. Return\n";
        choice_1 = program.choice();
        switch (choice_1)
        {
        case 0:
            return;
            break;
        case 1:
            member_route();
            break;
        default:
            cout << "Choice not valid";
            return;
        }
        break;
    case 2:
        //show request -> accept request
        program.CurrentUser->show_requests();
        if(program.CurrentUser->get_req_list().size() == 0){
            member_route();
            break;
        } else {
            cout <<"Do you want to accept request?: \n";
            cout <<"0. No\n";
            cout <<"1. Yes\n";
            int choice_1 = program.choice();
            switch (choice_1)
            {
            case 0:
                member_route();
                break;
            case 1:
                accept_request(program.CurrentUser, &program);
                member_route();
                break;
            default:
                break;
            }
        }
        break;
    case 3:
        //list house
        program.CurrentUser->list_house();
        member_route();
        break;
    case 4:
        //find house
        find_suitable_house(program.CurrentUser, &program);
        member_route();
        break;
    case 5:
        //rate occupying house/occupier , view my rating
        cout <<"1. Rate your occupier/occupying house\n";
        cout <<"2. View your rating\n";
        int choice_2 ;
        choice_2 = program.choice();
        switch (choice_2)
        {
        case 1:
            rate_occupier(program.CurrentUser->get_occupier());
            rate_house(program.CurrentUser->get_occupying());
            member_route();
            break;
        case 2:
            cout << "User rating: \n";
            if(program.CurrentUser->get_ratings().size() == 0) {
                cout << "No rating yet\n";
                member_route();
            } else{
                for(auto rate : program.CurrentUser->get_ratings()){
                    rate.show_rating();
                }
            }
            cout << "House rating: \n";
            if(program.CurrentUser->get_own_house().get_ratings().size() == 0) {
                cout << "No rating yet\n";
                member_route();
            } else{
                for(auto rate : program.CurrentUser->get_own_house().get_ratings()){
                    rate.show_rating();
                }
            }
            member_route();
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void start(){ //on start
    program.inputData();
    setup(&program);
    print_header();
    layer_1();
}

int main(){
    start();
    program.end();
    return 0;
}