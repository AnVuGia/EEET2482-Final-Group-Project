#include <iostream>
#include "House.h"
using std::string;

string House::get_location(){
    return this->location;
}
string House:: get_description(){
    return this->description;
}
void House::set_description(string des){
    this->description = des;
}
void House::set_location(string location){
    this->location = location;
}
void House::set_available(){
    
}