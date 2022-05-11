#include <iostream>
#include <sstream>
#include "Date.h"
#include "House.h"
int main(){
    House Chicago("Chicago", "Pretty sick ngl");
    House Texas("Texas", "It's Texas bruh");
    
    Chicago.set_info(3.4,0,"Chicago","noice", true,"11 06 2003", "22 07 08");
    Chicago.show_info();
   return 0;
}