#include "Cards.cpp"
#include "Deck.cpp"
#include <iostream>
using namespace std;

int main(){
    Card *card = new Card(4, 6);
    cout << Card::faces[card->face] << " of " << Card::suits[card->suit] << endl;
    cout << card << endl;
    Card card1 = *card;
    delete card;
    cout << card1 << endl;

    Card *decklist = new Card[4];

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> distCards(1,13);
    uniform_int_distribution<std::mt19937::result_type> distSuit(1,4);
    for(int i = 0; i < 4; i++){
        decklist[i] = Card(distCards(rng), distSuit(rng));
    }

    DeckofCards deck = DeckofCards(decklist, 4);
    cout << deck.size << " " << deck.current << " " << deck.moreCards() << endl;
    for(int i = 0; i < 4; i++){
        cout << deck.deal() << endl;
    }
    deck.current = 0;
    deck.shuffle();
    for(int i = 0; i < 4; i++){
        cout << deck.deal() << endl;
    }
    delete[] decklist;

    cout << "Shuffled deck:" << endl;
    DeckofCards deck2 = DeckofCards();
    for(int i = 0; i < deck2.size; i++){
        cout << deck2.deal() << endl;
    }

    return 1;
}