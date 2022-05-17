#include <iostream>
#include <sstream>
#include "Date.h"
#include "House.h"
void func2();
void func1(){
        func2();
    }
void func2(){
    std::cout <<"hello";
}
int main(){
    func1();
   return 0;
}