#include "customer.h"
#include <utility>

using namespace std;

Customer::Customer(string name, string address, string phone): User(move(name)), address(move(address)), phone(move(phone)){}

string Customer::getType(){
    return "customer";
}

string Customer::getAddress(){
    return address;
}

string Customer::getPhone(){
    return phone;
}

bool Customer::operator==(Customer& other){
    return(getName() == other.getName() && getAddress() == other.address && getPhone() == other.phone);
}

string Customer::toString(){
    return("Customer name: " + getName() + "\nAddress: " + getAddress() + "\nPhone: " + getPhone() + "\n");
}