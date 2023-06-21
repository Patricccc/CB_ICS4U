#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "user.h"

class Employee: public User {
    public:
        //Constructors
        Employee(string name);

        //Virtuals
        string getType() override;
        string toString() override;
};

#endif /* EMPLOYEE_H */
