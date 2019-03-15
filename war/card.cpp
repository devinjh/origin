// This is the card.cpp file for the War game
// Devin Hopkins
// 4190350

#include "card.hpp"

// Output operator for the Suit
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

// Output operator for the Rank
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

// Output operator for the Color
std::ostream& operator<<(std::ostream& os, Color co)
{
    // Displays the appropriate color when given a color
    switch (co) {
        case Red: return os << "R";
        case Black: return os << "B";
    }
}

// Output operator for the Card
std::ostream& operator<<(std::ostream& os, Card const& c)
{
    c.print(os);
    return os;
}

// Output operator for the StandardCard
std::ostream& operator<<(std::ostream& os, StandardCard const& c)
{
    return os << static_cast<Rank>(os, c.getData() & 0xf) << static_cast<Suit>(os, c.getData() >> 4);
}

// Output operator for the JokerCard
std::ostream& operator<<(std::ostream& os, JokerCard const& c)
{
    os << static_cast<Color>(os, c.getData() >> 6);
    return os << "J";
}

// Print function for StandardCard
void StandardCard::print(std::ostream& os) const
{
    os << *this;
}

// Print function for the JokerCard
void JokerCard::print(std::ostream& os) const
{
    os << *this;
}

// == operator for two cards
bool operator==(Card const& c, Card const& c2)
{
    if (c.getStatus() == c2.getStatus())
    {
        return true;
    }
    return false;
}

// != operator for two cards
bool operator!=(Card const& c, Card const& c2)
{
    return !(c == c2);
}

// < operator for two cards
bool operator<(Card const& c, Card const& c2)
{
    if (c.getStatus() < c2.getStatus())
    {
        return true;
    }
    return false;
}

// <= operator for two cards
bool operator<=(Card const& c, Card const& c2)
{
    return !(c2 < c);
}

// > operator for two cards
bool operator>(Card const& c, Card const& c2)
{
    return (c2 < c);
}

// >= operator for two cards
bool operator>=(Card const& c, Card const& c2)
{
    return !(c < c2);
}