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
    for(int i = 1; i <= 13; i++){
        for(int j = 1; j <= 4; j++){
            deck[(i-1)*4 + j-1] = Card(i, j);
        }
    }
    shuffle();
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