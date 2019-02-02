// This is the main file for the War game.
// Devin Hopkins
// 4190350

#include <iostream>
//#include "classifications.cpp"
#include "deck.hpp"

using std::cout;
using std::endl;

/*
void testFunction()
{
    cout << "Hello World!" << endl;
}
*/

int main(int argc, char const *argv[])
{
    // Creating the deck object and filling it
    Deck deck;

    // Viewing the entire deck
    //deck.viewDeck();

    // Shuffles the deck
    deck.shuffle();

    //std::cout << "Shuffle!" << std::endl;
    //deck.viewDeck();

    deck.playWar();

    return 0;
}