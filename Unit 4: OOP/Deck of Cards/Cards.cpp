#include <random>
#include "Headers.h"

using namespace std;

string Card::faces[13] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
string Card::suits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

Card::Card(){
    face = 1;
    suit = 1;
}

Card::Card(int face, int suit){
    if(face < 1 || face > 13 || suit < 1 || suit > 4){
        throw "Face/suit out of range";
    }
    this->face = face;
    this->suit = suit;
}

Card::Card(Card &card){
    this->face = card.face;
    this->suit = card.suit;
}

Card & Card::operator = (Card &card){
    if(this != &card){
        this->face = card.face;
        this->suit = card.suit;
    }
    return *this;
}

ostream& operator << (ostream &out, Card &card){
    out << Card::faces[card.face - 1] << " of " << Card::suits[card.suit - 1];
    return out;
}