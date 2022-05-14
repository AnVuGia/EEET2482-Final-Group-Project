#include <iostream>
#include <vector>
#include <sstream>
#include "House.h"
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::stringstream;
House::House(){};
House::House(string location, string description){
    this->location = location;
    this->description = description;
}
void House::set_available(){
    string inp;
    cout << "\nDo you want to list your house (y/n: ";
    cin >> inp;
    if(inp == "n"){
        return;
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
        cout << start_date.get_date();
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
        cout << end_date.get_date();
        cout << "\nMin occupier_rating: ";   
        double rating;
        cin >> rating;
        this->min_occupier_rating = rating;
    }           
        //set min req occupier rating      
}    

void House::show_info(){
    cout << "\n[ Location: "<< this->location 
        << "\nDescription: "<< this->description;
    if(available){
        cout << " Period: " << this->start_date.get_date() <<" - "<<this->end_date.get_date()<<" ]";
    } else{
        cout <<" ]";
    }
}

void House::show_short_info(){
    cout << "\n[ Location: " << this->location << std::endl;
    cout << "Description: " << this->description << std::endl;
    cout << "Consumming point: " << this->consumming_point << std::endl;
    cout << "Minimum required occupier rating: " << this->min_occupier_rating << "]" << std::endl;
}

void House::set_info(double houserate,double min_occ_rate, 
    string loca, string des, bool avail,string startdate,string enddate){
       this->house_rating_score = houserate;
       this->min_occupier_rating = min_occ_rate;
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
    for(Rating r: this->ratings){
        cout << i << ". Score: " << r.getScore() << " || Comment: " << r.getComment() << std::endl;
        i++; 
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

Comment House::get_house_comments(){
    return this->house_comments;
}
//setter
void House::set_location(string location){
    this->location = location;
}
void House::set_descrition(string des){
    this->description = des;
}
void House::set_rating(Rating rate){
    this->ratings.push_back(rate);
}

//putter
void House::put_comment(string comment, Member& member){
    this->house_comments.add_comment(comment, member);
}

