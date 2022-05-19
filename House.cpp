#include <iostream>
#include <vector>
#include <sstream>
#include "House.h"
#include <stdlib.h>
#include <string.h>
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::stringstream;
using std::end;
House::House(string location, string description){
    this->location = location;
    this->description = description;
}
int House::set_available(){
    if(this->available == true){
        int user_choice;
        cout << "Your house is already list, do you want to unlist? \n";
        cout << "0. No\n";
        cout << "1. Yes\n";
        cin >> user_choice;
        if(user_choice == 1){
            this->available = false;
            this->start_date.set_date(0,0,0);
            this->end_date.set_date(0,0,0);
            this->consuming_point = 0;
            return 1;
        } else {
            return 0;
        }
    } else{
        string inp;
        cout << "\nDo you want to list your house (y/n): ";
        cin >> inp;
        if(inp == "n"){
            return 0;
        } else {
            stringstream date_start;
            stringstream date_end;
            vector<int> start;
            vector<int> end;
            string token;
            this->available = true;
            //set start date
            cout << "\nEnter start date: (dd/mm/yyyy): ";
            cin >> inp;
            date_start << inp;
            while(std::getline(date_start, token, '/')) {
                stringstream temp(token);
                int num;
                temp >> num;
                start.push_back(num);
            }
            this->start_date.set_date(start[0], start[1], start[2]);
            //set end date
            cout << "\nEnter end date: (dd/mm/yyyy): ";
            cin >> inp;
            date_end << inp;
            while(std::getline(date_end, token, '/')) {
                stringstream temp(token);
                int num;
                temp >> num;
                end.push_back(num);
         }
            this->end_date.set_date(end[0], end[1], end[2]); 
            cout << "\nMin occupier_rating: ";   
            double rating;
            cin >> rating;
            this->min_occupier_rating = rating;
            cout <<"\nPoints per day: ";
            int points;
            cin >> points;
            this->consuming_point = points;
            cout <<"\nYour house is listed!";
        }
        return 0;     
    }          
}    

void House::show_info(){
    cout << "\n[ Location: "<< this->location 
        << "\nDescription: "<< this->description
        << "\n Rating: " << this->house_rating_score <<"\n";
        this->show_ratings();
    if(available){
        cout << " || Period: " << this->start_date.get_date() <<" - "<<this->end_date.get_date()<<" ]";
    } else{
        cout <<" ]";
    }
}
void House::show_short_info(){
    cout << "\n[ Location: " << this->location << std::endl;
    cout << "Description: " << this->description << std::endl;
    cout << "Consumming point: " << this->consuming_point << std::endl;
    cout << "Minimum required occupier rating: " << this->min_occupier_rating << "]" << std::endl;
}

void House::set_info(double houserate,double min_occ_rate,double consuming_point, 
    string loca, string des, bool avail,string startdate,string enddate){
       this->house_rating_score = houserate;
       this->min_occupier_rating = min_occ_rate;
       this->consuming_point = consuming_point;
       this->location = loca;
       this->description = des;
       this->available = avail;
        int day,month, year;
        stringstream ss(startdate); //(day month year)
        ss >> day >> month >> year;
        this->start_date.set_date(day,month,year);
        stringstream ss1(enddate);
        ss1 >> day >> month >> year;
        this->end_date.set_date(day, month, year);
        
}
void House::show_ratings(){
    int i =1;
    cout << "House ratings: " << std::endl;
    if(this->ratings.size() == 0){
        cout << "No rating for this place yet";
    } else{
        for (Rating r: this->ratings) {
        cout << i << ". Score: " << r.getScore() << " || Comment: " << r.getComment() << std::endl;
        i++; 
        }
    } 
};
//getter
string House::get_location(){
    return this->location;
}
string House:: get_description(){
    return this->description;
}
double House::get_houserate(){
    return this->house_rating_score;
}
double House::get_minoccrate(){
    return this->min_occupier_rating;
}
double House::get_conspoint(){
    return this->consuming_point;
};
bool House::get_availalbe(){
    return this->available;
}
string House::get_startdate(){
    if(this->start_date.get_day() > 0){
        return this->start_date.get_date();
    } else{
        return "0 0 0";
    }
}
string House::get_enddate(){
    if(this->end_date.get_day() > 0){
        return this->end_date.get_date();
    } else{
        return "0 0 0";
    }
}
int House::get_start_day_rata(){
    return this->start_date.rata_die_days();
}
int House::get_end_day_rata(){
    return this->end_date.rata_die_days();
}
vector<Rating> House::get_ratings(){
    return this->ratings;
};

//setter
void House::set_location(string location){
    this->location = location;
}
void House::set_descrition(string des){
    this->description = des;
}
void House::set_house_rating_score(double score){
    this->house_rating_score = score;
};

void House::add_rating(Rating rate){
    this->ratings.push_back(rate);
}
