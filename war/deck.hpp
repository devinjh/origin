// This is the deck.hpp file for the War game
// Devin Hopkins
// 4190350

#include <vector>
#include "card.hpp"

class Deck{

private:

    // The vector of deck of cards
    std::vector<Card*> deck;

public:

    Deck();

    void putCardsAtEndOfDeck(int numOfCards);

    void addCard(Card* card);

    void viewDeck();

    Card* get(int x);

    int getSize();

    void transferCardsTo(Deck& otherDeck, int numOfCards);

};