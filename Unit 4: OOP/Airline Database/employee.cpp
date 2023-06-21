#include "employee.h"
#include <utility>

Employee::Employee(string name): User(move(name)){};

string Employee::getType(){
    return "Employee";
}

string Employee::toString(){
    return "Employee: " + getName();
}