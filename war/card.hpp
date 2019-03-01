// This is the card hpp file for the War game.
// Devin Hopkins
// 4190350

#include <iostream>

class Card{

private:

    // The 8 bit data needed for each card
    unsigned char dataForCard;

public:

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

    enum Suit {
    // The suits of a card
    Diamonds,
    Clubs,
    Hearts,
    Spades,
    };

    Card(unsigned char incomingData);

    unsigned char getData();

    int getRank();

};

// OS operator overloaders
std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Card::Suit s);
std::ostream& operator<<(std::ostream& os, Card::Rank r);

// Comparative overloaders
bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);
bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);