// This is the card hpp file for the War game.
// Devin Hopkins
// 4190350

#include <iostream>

enum Suit {
    // The suits of a card
    Diamonds,
    Clubs,
    Hearts,
    Spades,
};

enum Rank {
    // The ranks of a card
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
    Ace,
};

class Card{

private:

    // The 8 bit data needed for each card (although only 6 bits
    // will be used)
    unsigned char dataForCard;

public:

    Card(unsigned char incomingData);

    unsigned char getData();

    int getRank();

};

// OS operator overloaders
std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);

// Comparative overloaders
bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);
bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);