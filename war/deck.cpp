// This is the deck file for the War game.
// Devin Hopkins
// 4190350

#include "deck.hpp"
#include <ctime>
#include <cstdlib>

Deck::Deck()
{
    // Empty, don't need/want anything in here
}

void Deck::addCard(Card& card)
{
    // Adding a card to the end of th deck
    deck.push_back(card);
}

Card Deck::get(int x)
{
    // Returning the card at the spot given by x
    return deck[x];
}

int Deck::getSize()
{
    // Returns the size of the deck
    return deck.size();
}

void Deck::transferCardsTo(Deck &otherDeck, int numOfCards)
{
    // This loop transfers one card at a time from this deck to
    // the other deck
    for (int x = 0; x < numOfCards; ++x)
    {
        // Adding the card to the other deck
        otherDeck.addCard(deck[0]);

        // Taking the card out of this deck
        deck.erase(deck.begin());
    }
}

// This is for testing purposes only
void Deck::viewDeck()
{
    // Displays the size of the array and the contents inside
    // Meant to be used with a standard 52 card deck

    // Shows the size of the deck
    std::cout << deck.size() << std::endl;

    // Displays each card in the deck in a nice, orderly fashion
    for (int y = 0; y < deck.size(); ++y)
    {
        if ((y + 1) % 13 == 0)
        {
            // If this is the last cards in the deck, goes to
            // a new line for the next card (makes it look nice)
            std::cout << deck[y] << std::endl;
        }
        else
        {
            // Prints out the card with a space after it so
            // the display doesn't get confusing
            std::cout << deck[y] << " ";
        }
    }

    // Puts a newline character so it doesn't get jumbled with
    // whatever gets displayed next
    std::cout << "\n";
}