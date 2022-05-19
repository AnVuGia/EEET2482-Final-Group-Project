#ifndef LOGIN_H
#define LOGIN_H
#include "Global.h"
#include "Member.h"
int login(Global *program);
void setup(Global *program);
void find_suitable_house(Member *currentUser, Global *program);
void send_request(Member *currenUser, Member *chosenUser);
void rate_house(Member *chosenUser);
void rate_occupier(Member *chosenUser);
void showHouse(Global *program);
void accept_request(Member *currentMember, Global *program);
#endif