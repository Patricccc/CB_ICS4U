#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <string>

using namespace std;

class Card {
    public:
        int face, suit;
        
        Card();
        Card(int face, int suit);
        Card(Card &card);

        Card & operator = (Card &card);
        friend ostream& operator << (ostream &out, Card &card);

        static string faces[13];
        static string suits[4];
};

#endif /* HEADERS_H */
