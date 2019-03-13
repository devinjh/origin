// This is the card.hpp file for the War game
// Devin Hopkins
// 4190350

#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

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

enum Suit {
    Hearts,
    Spades,
    Diamonds,
    Clubs
};

enum Color {
    Red,
    Black,
};

struct Card {
    virtual unsigned char getData() = 0;

    virtual void print(std::ostream& os) const = 0;
};

struct StandardCard : Card {
    unsigned char data;

    //std::ostream& print(std::ostream& os) const override;
    void print(std::ostream& os) const override;

    StandardCard(unsigned char incomingData) : data(incomingData)
    {
        // Empty
    }

    unsigned char getData()
    {
        return data;
    }
};

struct JokerCard : Card {
    unsigned char data;

    void print(std::ostream& os) const override;

    JokerCard(unsigned char incomingData) : data(incomingData)
    {
        // Empty
    }

    unsigned char getData()
    {
        return data;
    }
};

std::ostream& operator<<(std::ostream& os, Card const& c);
std::ostream& operator<<(std::ostream& os, JokerCard const& j);
std::ostream& operator<<(std::ostream& os, StandardCard const& s);

std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);

#endif //CARD_HPP