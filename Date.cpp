#include <iostream>
#include "Date.h"


int Date::rata_die_days(){
    if(this->month < 3) {
        year--;
        month += 12;
    }
    return 365*this->year + this->year/100 + this->year/400 + (153*this->month - 457 )/5 +this->day-306;
};