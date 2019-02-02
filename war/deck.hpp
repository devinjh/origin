// This is the deck hpp file for the War game.
// Devin Hopkins
// 4190350

#include <iostream>
#include "classifications.cpp"

class Deck{

private:

/*
    Card deck[52];

    void createCard(Card &sentCard, int x);
    
    void fillDeck();

*/

public:

    Deck();

    void viewDeck();

    Card deck[52];

    void createCard(Card &sentCard, int x);
    
    void fillDeck();

    std::string printSuit(Card &sentCard);

    std::string printRank(Card &sentCard);

    void shuffle();

    void swap(int firstSwap, int secondSwap);

    void playWar();

    void playCard(Card oneDeck[], Card twoDeck[]);

    int findEndOfDeck(Card randomDeck[]);

    void cleanseWarZoneCards(Card playerOneDeck[], Card playerTwoDeck[], Card warZone[], bool playerOneWinner);

    void shiftDeckOver(Card aDeck[]);

};