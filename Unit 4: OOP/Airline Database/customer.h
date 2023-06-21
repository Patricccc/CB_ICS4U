#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "user.h"

using namespace std;

class Customer: public User {
    private:
        string address, phone;
    public:
        //Constructors
        Customer(string name, string address, string phone);
        //Virtual functions
        string getType() override;
        string toString() override;
        //Getters
        string getAddress();
        string getPhone();
        //Operator Overloads
        bool operator==(Customer& other);
};

#endif /* CUSTOMER_H */
