#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include "customer.h"

using namespace std;

class Seat{
    private:
        int seatNumber;
        Customer contact;

    public:
        //Util
        bool available;

        //Getters
        Customer getContact();

        //Constructors
        Seat(int num, Customer* contact);
        Seat();
};

#endif /* SEAT_H */
