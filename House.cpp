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
string House::get_location(){
    return this->location;
}
string House:: get_description(){
    return this->description;
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
    cout << "[ Location: "<< this->location 
        << "\nDescription: "<< this->description;
    if(available){
        cout << " Period: " << this->start_date.get_date() <<" - "<<this->end_date.get_date()<<" ]";
    } else{
        cout <<" ]";
    }
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

