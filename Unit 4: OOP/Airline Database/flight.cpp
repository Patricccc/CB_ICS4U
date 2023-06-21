#include "flight.h"
#include <iostream>
#include <utility>

using namespace std;

Flight::Flight(int seatCount): seats(new Seat[seatCount]), seatCount(seatCount){}

bool Flight::fullFlight(){
    for(int i = 0; i < seatCount; i++){
        if(seats[i].available)
            return false;
    }
    return true;
}

bool Flight::checkAvailability(int seatNumber){
    return seats[seatNumber].available;
}

void Flight::setSeat(int seatNumber, Seat seat){
    seats[seatNumber] = move(seat);
}

Customer Flight::checkCustomer(int seatNumber){
    return seats[seatNumber].getContact();
}

int Flight::getSeatCount(){
    return seatCount;
}