#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User{
    private:
        string name;
    public:
        //Getters
        string getName();

        //Virtuals
        virtual string getType();
        virtual string toString();

        //Constructors
        explicit User(string name);
};

#endif /* USER_H */
