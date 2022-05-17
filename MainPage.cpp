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
void user_choice(){
    int choice;
    cout << "\nUse the app as: 1. Guest  2. Member   3.  Admin\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        showHouse(&program); // test câu 2
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
int main(){
    program.inputData();
    setup(&program);
    print_header();
    user_choice();
    
    accept_request(program.CurrentUser, &program); //test request accept & fees exchange between users
    rate_occupier(program.CurrentUser->get_occupier());   //test rate occupier
    // rate_occupier(program.CurrentUser);  //test avg rating
    // program.CurrentUser->show_user_ratings();
    rate_house(program.CurrentUser->get_occupying()); //test rate house
    // rate_house(program.CurrentUser); //test avg rating
    // // program.CurrentUser->show_info();
    // program.CurrentUser->show_house_ratings();
    // find_suitable_house(program.CurrentUser, &program);
    // program.CurrentUser->show_requests();
    //program.end();

    return 0;
}