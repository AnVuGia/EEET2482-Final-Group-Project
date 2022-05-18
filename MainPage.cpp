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
void print_header(){
    cout << "\n\nEEET2482/COSC2082 ASSIGNMENT\n";
    cout << "VACATION HOUSE EXCHANGE APPLICATION";
    cout << "\n\n";
    cout << "Instructor: Mr. Linh Tran" <<"\n"
        << "Group: 25" <<"\n"
        << "s, student 1" <<"\n"
        << "s, student 2" <<"\n"
        << "s, student 3" <<"\n";
}
void layer_1(){
    int choice;
    cout << "\nUse the app as: 1. Guest  2. Member   3.  Admin\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        guest_route(); // test câu 2
        break;
        // program.user_register();
        // break;
    case 2:
        login(&program);
        break;
    
    default:
        break;
    }
}
void guest_route(){
    int choice;
    cout << "You are a guest!\n";
    cout<<"0. Exit\n";
    cout << "1. Show info (shortened version): ";
    cout <<"2. Register";
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
    cout <<"in member route";
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