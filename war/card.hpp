// This is the card.hpp file for the War game
// Devin Hopkins
// 4190350

//#include <iostream>

class Card{

public:

    virtual unsigned char getData() = 0;

    virtual int getType() = 0;

};

/*
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
*/