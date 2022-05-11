#include "Date.h"

int main(){
    Date start (11,2,2022);
    Date end (21,12,2022);

    std::cout << "differrence: "<< end.rata_die_days() - start.rata_die_days();
}