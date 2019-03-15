// This is the card.hpp file for the War game
// Devin Hopkins
// 4190350

#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

// Rank enum for the standard card
enum Rank {
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

// Suit enum for the standard card
enum Suit {
    Hearts,
    Spades,
    Diamonds,
    Clubs
};

// Color enum for the joker card
enum Color {
    Red,
    Black,
};

// Abstract Card struct
// All of the other cards (standard card and joker card) are derived
// from this struct
struct Card {
    virtual unsigned char getData() const = 0;

    virtual void print(std::ostream& os) const = 0;

    virtual int getStatus() const = 0;
};

struct StandardCard : Card {
    unsigned char data;

    //std::ostream& print(std::ostream& os) const override;
    void print(std::ostream& os) const override;

    // Constructor
    StandardCard(unsigned char incomingData) : data(incomingData)
    {
        // Empty
    }

    // This returns the unsigned char
    unsigned char getData() const
    {
        return data;
    }

    // This returns a numerical value of the card
    int getStatus() const
    {
        return (int)(data & 0xf);
    }
};

struct JokerCard : Card {
    unsigned char data;

    void print(std::ostream& os) const override;

    // Constructor
    JokerCard(unsigned char incomingData) : data(incomingData)
    {
        // Empty
    }

    // This returns the unsigned char
    unsigned char getData() const
    {
        return data;
    }

    // This returns a numerical value of the card
    int getStatus() const
    {
        return 14;
    }
};

// The output overrides for each of the structs
std::ostream& operator<<(std::ostream& os, Card const& c);
std::ostream& operator<<(std::ostream& os, JokerCard const& j);
std::ostream& operator<<(std::ostream& os, StandardCard const& s);

// The output overrides for each of the enums
std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Color co);

// Boolean operators for comparing two cards
bool operator==(Card const& c, Card const& c2);
bool operator!=(Card const& c, Card const& c2);
bool operator<(Card const& c, Card const& c2);
bool operator<=(Card const& c, Card const& c2);
bool operator>(Card const& c, Card const& c2);
bool operator>=(Card const& c, Card const& c2);

#endif //CARD_HPP