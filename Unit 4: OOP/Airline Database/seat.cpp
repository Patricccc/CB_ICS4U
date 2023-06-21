#include "seat.h"

Seat::Seat(int num, Customer* contact): seatNumber(num), contact(*contact), available(false){}
Seat::Seat() : seatNumber(-1), contact(Customer("NAME", "ADDRESS", "PHONE")), available(true){}

Customer Seat::getContact(){
    return contact;
}