#ifndef DECKHEADERS_H
#define DECKHEADERS_H

#include "Headers.h"

class DeckofCards {
    Card *deck;
    int current;
    int size;

    explicit DeckofCards(Card[], int size);
    DeckofCards();
    void shuffle();

    Card deal();
    bool moreCards();
};

#endif /* DECKHEADERS_H */
