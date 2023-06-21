#include <utility>

#include "user.h"

string User::getName(){
    return name;
}

User::User(string name): name(move(name)){}

string User::getType(){
    return "Not a User";
}

string User::toString(){
    return "User doesn't exist";
}