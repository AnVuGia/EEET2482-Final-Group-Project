#include "Date.h"
#include "House.h"
int main(){
    House Chicago("Chicago", "Pretty sick ngl");
    House Texas("Texas", "It's Texas bruh");
    Chicago.show_info();
    Chicago.set_available();
    Chicago.show_info();
   return 0;
}