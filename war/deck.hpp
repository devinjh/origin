// This is the deck hpp file for the War game.
// Devin Hopkins
// 4190350

#include <iostream>
#include "classifications.cpp"

class Deck{

private:

    Card playerOneDeck[52], playerTwoDeck[52];

    void createCard(Card &sentCard, int x);
    
    void fillDecks();

    void printCard(Card &sentCard);

    void changeCards(int cardGetter, int numOfCards);

    int findEndOfDeck(int deckNum);

    void shiftDeck(int deckShifter);

public:

    Deck();

    void viewDecks();

    bool getWinner();

    void printWinner();

    void goToWar(int numOfCardsPassed);

};