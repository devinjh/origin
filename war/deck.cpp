// This is the deck.cpp file for the War game
// Devin Hopkins
// 4190350

#include "deck.hpp"

Deck::Deck()
{
    // Empty, don't need/want anything in here
}

void Deck::addCard(Card* ccard)
{    
    // Adding a card to the end of the deck
    deck.push_back(ccard);
}

Card* Deck::get(int x)
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
        // Adding the loser's card to the other deck
        otherDeck.addCard(deck[0]);

        // Taking the loser's card out of their (this) deck
        deck.erase(deck.begin());
    }
}

void Deck::putCardsAtEndOfDeck(int numOfCards)
{
    // This loop takes one card from the front of the deck and puts it
    // at the end
    for (int x = 0; x < numOfCards; ++x)
    {
        // Adding the card to the end
        addCard(deck[0]);

        // Deleting it from the front
        deck.erase(deck.begin());
    }
}

// This is for testing purposes only
void Deck::viewDeck()
{
    // Displays the size of the array and the contents inside
    // This is the vriable that will show the cards nicely
    int split = 0;

    // Shows the size of the deck
    std::cout << "Size of the Deck: " << deck.size() << std::endl;

    // Displays each card in the deck in a nice, orderly fashion
    for (int y = 0; y < deck.size(); ++y)
    {
        split = ((deck.size() % 2) == 1) ? (deck.size() / 2) + 1 : deck.size() / 2;
        if ((y + 1) % split == 0)
        {
            // If this is the last card in the deck, goes to
            // a new line for the next card (makes it look nice)
            std::cout << *(deck[y]) << std::endl;
        }
        else
        {
            // Prints out the card with a space after it so
            // the display doesn't get confusing
            std::cout << *(deck[y]) << " ";
        }
    }

    // Puts a newline character so it doesn't get jumbled with
    // whatever gets displayed next
    std::cout << "\n";
}