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
            cout <<"Users info: ";
            for(auto user: program->users){
                user.show_info();
            }
        } else{
            cout << "Wrong pass";
            return;
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
void setup(Global *program){
    cout << "in setup";
    int size = program->users.size();
    for(int i = 0; i < size; i++){
        cout << " searching " << i <<" ";
        cout << program->users[i].get_occupier_name();
        cout << program->users[i].get_occupying_name();
        for(int j = 0; j < size; j++){ 
            if(program->users[i].get_occupier_name() == program->users[j].get_userName()){
                program->users[i].set_occupier(&program->users[j]);
                cout << "in set occupier";
            }
            if(program->users[i].get_occupying_name() == program->users[j].get_userName()){
                program->users[i].set_occupying(&program->users[j]);
                cout << "in set occupying";
            }
        }
    }
}
void send_request(Member *currentUser, Member *chosenUser){
    Request temp_req;   
        string token;
        string inp;
        Date temp_start,temp_end;
        //set start date
        bool is_valid = false;
        do
        {   stringstream start_date;
            stringstream start_res;
            cout << "\nEnter start date: (dd/mm/yyyy): ";
            cin >> inp;
            start_date << inp;
            int day,month,year;
            while(std::getline(start_date, token, '/')) {
            start_res << token <<" ";
            }
            start_res >> day>>month>>year;
            temp_start.set_date(day,month,year);
            if (temp_start.rata_die_days() < chosenUser->get_start_value())
                {
                is_valid =true;
                cout << "\nInvalid input!\n";
            }else{
                is_valid = false;
            }
        } while (is_valid);
        
        
        
        //set end date
        do{   stringstream date_end;
            stringstream end_res;
            cout << "\nEnter end date: (dd/mm/yyyy): ";
            cin >> inp;
            date_end << inp;
            int day,month,year;
            while(std::getline(date_end, token, '/')) {
            end_res << token <<" ";
            }
            end_res >> day>>month>>year;
            temp_end.set_date(day,month,year);
            if (temp_end.rata_die_days() > chosenUser->get_end_value())
                {
                is_valid =true;
                cout << "\nInvalid input!\n";
            }else{
                is_valid = false;
            }
        } while (is_valid);
    temp_req.set_req(1,currentUser->get_userName(),currentUser->get_own_rating_score(),temp_start.get_date(),temp_end.get_date());
    chosenUser->set_request(temp_req);
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
                cout << mem[int_choice-1]->get_userName() <<" 's house: \n";
                mem[int_choice-1]->get_full_house_info() ; 
                send_request(program->CurrentUser, mem[int_choice-1]);
                token = false;
            }
        } while (token);
}

void showHouse(Global *program)
{
    for(size_t i = 0; i < program->users.size(); i++){
        if (program->users[i].get_own_house().get_availalbe())
        {
            program->users[i].get_own_house().show_short_info();
        }
    }
}

void rate_house(Member *chosenUser){
    double score;
    string comment;
    if(chosenUser == NULL){
        cout << "\nNo houses to rate!";
    }else{
        cout<<"\nRate your previously occupied house: "<< chosenUser->get_fullName() << "'s" << "\nEnter score: ";
        cin >> score;
        cout << "Add a comment: ";
        std::getline(cin >> std::ws, comment);
        chosenUser->add_house_rating(Rating(score, comment));
        chosenUser->set_house_rating_score(chosenUser->rating_score(chosenUser->get_own_house().get_ratings()));
    }
}
void rate_occupier(Member *chosenUser){
    double score;
    string comment;
    if(chosenUser == NULL){
        cout << "\nNo occupier to rate!";
    }else{
        cout <<"\nRate your occupier: "<< chosenUser->get_fullName() << "\nEnter score: ";
        cin >> score;
        cout << "Add a comment: ";
        std::getline(cin >> std::ws, comment);
        Rating rate(score, comment);
        chosenUser->add_rating(rate);
        chosenUser->set_own_rating_score(chosenUser->rating_score(chosenUser->get_ratings()));
    }
};

void accept_request(Member* currentMember, Global *program) {
    if(currentMember->get_req_list().size() == 0){
        cout << "No request!";
        return;
    }
    currentMember->show_requests();
    int accept, i = 1;
    cout << "Accepted request: ";
    cin >> accept;
    Request temp = currentMember->get_req_list()[accept-1];
    temp.set_status(2);
    currentMember->get_req_list().clear();
    currentMember->get_req_list().push_back(temp);
    double days = temp.get_end().rata_die_days() - temp.get_start().rata_die_days() + 1;
    double fee = currentMember->get_house_cons_point() * days;
    for(size_t i = 0; i < program->users.size(); i++){
        if(temp.get_req_from() == program->users[i].get_userName()){
            currentMember->set_occupier(&program->users[i]);
            currentMember->add_credit(fee);
            program->users[i].set_occupying(currentMember);
            program->users[i].minus_credit(fee);
            cout << currentMember->get_occupier_name() << " New credit: " << program->users[i].get_creds() << " Days: " << days << " Fees: $" << fee << std::endl; //for testing
            cout << program->users[i].get_occupying_name() << " New credit: " << currentMember->get_creds() << std::endl; //for testing
        }
    }
};

