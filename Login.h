#ifndef LOGIN_H
#define LOGIN_H
#include "Global.h"
#include "Member.h"
void login(Global *program);
void find_suitable_house(Member *currentUser,Global *program);
void send_request(Member *currenUser, Member *chosenUser);
void showHouse(Global *program); //câu 2
#endif