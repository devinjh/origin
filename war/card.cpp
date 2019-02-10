// This is the classifications file for the War game.
// Devin Hopkins
// 4190350

#include "card.hpp"

Card::Card(unsigned char incomingData)
{
    dataForCard = incomingData;
}

unsigned char Card::getData()
{
    // returns the card's unsigned char data
    return dataForCard;
}

std::ostream& operator<<(std::ostream& os, Card c)
{
    // Displays a card's values when given a card
    return os << static_cast<Rank>(os, c.getData() & 0xf) << static_cast<Suit>(os, c.getData() >> 4);
}

std::ostream& operator<<(std::ostream& os, Suit s)
{
    // Displays the appropriate suit when given a suit
    switch (s) {
        case Clubs: return os << "C";
        case Spades: return os << "S";
        case Hearts: return os << "H";
        case Diamonds: return os << "D";
    }
}

std::ostream& operator<<(std::ostream& os, Rank r)
{
    // Displays the appropriate rank when given a rank
    switch (r) {
        case Ace: return os << "A";
        case Two: return os << "2";
        case Three: return os << "3";
        case Four: return os << "4";
        case Five: return os << "5";
        case Six: return os << "6";
        case Seven: return os << "7";
        case Eight: return os << "8";
        case Nine: return os << "9";
        case Ten: return os << "T";
        case Jack: return os << "J";
        case Queen: return os << "Q";
        case King: return os << "K";
    }
}

// Compared by each card's rank
bool operator==(Card a, Card b)
{
    return ((static_cast<int>(a.getData() & 0xf)) == (static_cast<int>(b.getData() & 0xf)));
}

// Compared by each card's rank
bool operator!=(Card a, Card b)
{
    return !(a == b);
}

// Compared by each card's rank
bool operator<(Card a, Card b)
{
    return ((static_cast<int>(a.getData() & 0xf)) < (static_cast<int>(b.getData() & 0xf)));
}

// Compared by each card's rank
bool operator>(Card a, Card b)
{
    return (b < a);
}

// Compared by each card's rank
bool operator<=(Card a, Card b)
{
    return !(b < a);
}

// Compared by each card's rank
bool operator>=(Card a, Card b)
{
    return !(a < b);
}