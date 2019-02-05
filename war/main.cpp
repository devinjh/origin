// This is the main file for the War game.
// Devin Hopkins
// 4190350

#include "deck.hpp"

int main(int argc, char const *argv[])
{
    // Creating the deck object and filling it
    Deck war;

    // Playing the game of war
    while(!(war.getWinner()))
    {
        war.goToWar(1);
    }

    // Printing the winner
    war.printWinner();

    return 0;
}