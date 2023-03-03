#include "DeckHeaders.h"

DeckofCards::DeckofCards(Card *deck, int size){
    this->deck = deck;
    this->size = size;
    current = 0;
}

void DeckofCards::shuffle(){
    for(int i = 0; i < size; i++){
        int j = rand() % size;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

DeckofCards::DeckofCards(){
    size = 52;
    deck = new Card[size];
    int count = 0;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 13; j++){
            deck[count++] = Card(j, i);
        }
    }
    shuffle();
    current = 0;
}

Card DeckofCards::deal(){
    if(moreCards()){
        return deck[current++];
    }
    else{
        throw "No more cards";
    }
}

bool DeckofCards::moreCards(){
    return current < size;
}