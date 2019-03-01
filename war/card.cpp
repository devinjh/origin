// This is the classifications file for the War game.
// Devin Hopkins
// 4190350

#include "card.hpp"

// The if statement to see if a card is a joker or not (true if yes)
// if ((((c.getData() >> 6) & 0x1) == 1) || ((((c.getData() >> 6) & 0x1) == 0) && ((c.getData() >> 7) & 0x1) == 1))

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
    // Detects to see if the card is a black joker or not
    if (((c.getData() >> 6) & 0x1) == 1)
    {
        return os << "BJ";
    }
    // This is for red jokers
    else if ((((c.getData() >> 6) & 0x1) == 0) && ((c.getData() >> 7) & 0x1) == 1)
    {
        return os << "RJ";
    }

    // Displays a card's values when given a card (if it's not a joker)
    return os << static_cast<Card::Rank>(os, c.getData() & 0xf) << static_cast<Card::Suit>(os, c.getData() >> 4);
}

std::ostream& operator<<(std::ostream& os, Card::Suit s)
{
    // Displays the appropriate suit when given a suit
    switch (s) {
        case Card::Clubs: return os << "C";
        case Card::Spades: return os << "S";
        case Card::Hearts: return os << "H";
        case Card::Diamonds: return os << "D";
    }
}

std::ostream& operator<<(std::ostream& os, Card::Rank r)
{
    // Displays the appropriate rank when given a rank
    switch (r) {
        case Card::Ace: return os << "A";
        case Card::Two: return os << "2";
        case Card::Three: return os << "3";
        case Card::Four: return os << "4";
        case Card::Five: return os << "5";
        case Card::Six: return os << "6";
        case Card::Seven: return os << "7";
        case Card::Eight: return os << "8";
        case Card::Nine: return os << "9";
        case Card::Ten: return os << "T";
        case Card::Jack: return os << "J";
        case Card::Queen: return os << "Q";
        case Card::King: return os << "K";
    }
}

// Compared by each card's rank
bool operator==(Card a, Card b)
{
    // Card a is a joker
    if ((((a.getData() >> 6) & 0x1) == 1) || ((((a.getData() >> 6) & 0x1) == 0) && ((a.getData() >> 7) & 0x1) == 1))
    {
        // Card b is a joker
        if ((((b.getData() >> 6) & 0x1) == 1) || ((((b.getData() >> 6) & 0x1) == 0) && ((b.getData() >> 7) & 0x1) == 1))
        {
            return true;
        }

        // Card a is a joker but not card b
        return false;
    }

    // Card b is a joker, but not card a
    if ((((b.getData() >> 6) & 0x1) == 1) || ((((b.getData() >> 6) & 0x1) == 0) && ((b.getData() >> 7) & 0x1) == 1))
    {
        return false;
    }

    // Neither card is a joker
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
    // Card a is a joker
    if ((((a.getData() >> 6) & 0x1) == 1) || ((((a.getData() >> 6) & 0x1) == 0) && ((a.getData() >> 7) & 0x1) == 1))
    {
        // If card a is a joker, than it must be false because card b is either less than or equal to card a
        return false;
    }

    // Card b is a joker, but not card a
    if ((((b.getData() >> 6) & 0x1) == 1) || ((((b.getData() >> 6) & 0x1) == 0) && ((b.getData() >> 7) & 0x1) == 1))
    {
        return true;
    }

    // Neither card is a joker
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