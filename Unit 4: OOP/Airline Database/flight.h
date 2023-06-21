#ifndef FLIGHT_H
#define FLIGHT_H

#include "seat.h"

class Flight {
    private:
        Seat* seats;
        int seatCount;

    public:
        //Util
        bool checkAvailability(int seatNumber);
        Customer checkCustomer(int seatNumber);
        void setSeat(int seatNumber, Seat seat);
        bool fullFlight();

        //Constructors
        Flight(int seatCount);

        //Getters
        int getSeatCount();
};

#endif /* FLIGHT_H */
