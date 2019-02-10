// This is the deck hpp file for the War game.
// Devin Hopkins
// 4190350

#include "deck.hpp"

class War{

private:

    // Each of the player's decks
    Deck playerOneDeck;
    Deck playerTwoDeck;

public:

    War();

    void playWar();

};