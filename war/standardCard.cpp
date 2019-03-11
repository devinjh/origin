// This is the standardCard.cpp file for the War game
// Devin Hopkins
// 4190350

StandardCard::StandardCard(unsigned char incomingData)
{
    dataForStandardCard = incomingData;
}

unsigned char StandardCard::getData()
{
    // Returns the card's unsigned char data
    return dataForStandardCard;
}

std::ostream& operator<<(std::ostream& os, StandardCard c)
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

std::ostream& operator<<(std::ostream& os, StandardCard::Suit s)
{
    // Displays the appropriate suit when given a suit
    switch (s) {
        case StandardCard::Clubs: return os << "C";
        case StandardCard::Spades: return os << "S";
        case StandardCard::Hearts: return os << "H";
        case StandardCard::Diamonds: return os << "D";
    }
}

std::ostream& operator<<(std::ostream& os, StandardCard::Rank r)
{
    // Displays the appropriate rank when given a rank
    switch (r) {
        case StandardCard::Ace: return os << "A";
        case StandardCard::Two: return os << "2";
        case StandardCard::Three: return os << "3";
        case StandardCard::Four: return os << "4";
        case StandardCard::Five: return os << "5";
        case StandardCard::Six: return os << "6";
        case StandardCard::Seven: return os << "7";
        case StandardCard::Eight: return os << "8";
        case StandardCard::Nine: return os << "9";
        case StandardCard::Ten: return os << "T";
        case StandardCard::Jack: return os << "J";
        case StandardCard::Queen: return os << "Q";
        case StandardCard::King: return os << "K";
    }
}

// Compared by each card's rank
bool operator==(StandardCard a, StandardCard b)
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
bool operator!=(StandardCard a, StandardCard b)
{
    return !(a == b);
}

// Compared by each card's rank
bool operator<(StandardCard a, StandardCard b)
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
bool operator>(StandardCard a, StandardCard b)
{
    return (b < a);
}

// Compared by each card's rank
bool operator<=(StandardCard a, StandardCard b)
{
    return !(b < a);
}

// Compared by each card's rank
bool operator>=(StandardCard a, StandardCard b)
{
    return !(a < b);
}