// This is the card.cpp file for the War game
// Devin Hopkins
// 4190350

#include "card.hpp"

std::ostream& operator<<(std::ostream& os, StandardCard const& c)
{
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

std::ostream& operator<<(std::ostream& os, Color co)
{
    // Displays the appropriate color when given a color
    switch (co) {
        case Red: return os << "R";
        case Black: return os << "B";
    }
}

std::ostream& operator<<(std::ostream& os, JokerCard const& c)
{
    os << static_cast<Color>(os, c.getData() >> 6);
    return os << "J";
}

void StandardCard::print(std::ostream& os) const
{
    os << *this;
}

void JokerCard::print(std::ostream& os) const
{
    os << *this;
}

std::ostream& operator<<(std::ostream& os, Card const& c)
{
    c.print(os);
    return os;
}

bool operator==(Card const& c, Card const& c2)
{
    if (c.getStatus() == c2.getStatus())
    {
        return true;
    }
    return false;
}

bool operator!=(Card const& c, Card const& c2)
{
    return !(c == c2);
}

bool operator<(Card const& c, Card const& c2)
{
    if (c.getStatus() < c2.getStatus())
    {
        return true;
    }
    return false;
}

bool operator<=(Card const& c, Card const& c2)
{
    return !(c2 < c);
}

bool operator>(Card const& c, Card const& c2)
{
    return (c2 < c);
}

bool operator>=(Card const& c, Card const& c2)
{
    return !(c < c2);
}

//
/*
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
*/

// The if statement to see if a card is a joker or not (true if yes)
// if ((((c.getData() >> 6) & 0x1) == 1) || ((((c.getData() >> 6) & 0x1) == 0) && ((c.getData() >> 7) & 0x1) == 1))

/*

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
*/

/*std::ostream& operator<<(std::ostream& os)
{
    std::string type = typeid(this).name();
    os << type;
    return os;
}*/
/*
std::ostream& operator<<(std::ostream& os, Card& c)
{
    std::string type = typeid(c).name();
    os << "Type: " << type << "\n";
    return os;
}*/

/*
std::ostream& Card::print(std::ostream& os)
{
    //std::string type = typeid(c).name();
    //os << "       typeid(c): " << typeid(c) << std::endl;
    os << "HERE2!" << std::endl;
    return os << "typeid(this).name(): " << typeid(this).name() << std::endl;
}

std::ostream& operator<<(std::ostream& os, Card* c)
{
    //std::string type = typeid(c).name();
    //os << "       typeid(c): " << typeid(c) << std::endl;
    os << "HERE!" << std::endl;
    return c->print(os);
    //return os;
}
*/
/*
#include "card.hpp"

struct StandardCard : Card {
    //unsigned char data;
    void setData(unsigned char incomingData)
    {
        data = incomingData;
    }

    unsigned char getData()
    {
        return 0;
    }
};

struct JokerCard : Card {
    //unsigned char data;
    void setData(unsigned char incomingData)
    {
        data = incomingData;
    }

    unsigned char getData()
    {
        return 0;
    }
};*/