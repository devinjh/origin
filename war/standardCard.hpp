// This is the standardCard.hpp file for the War game
// Devin Hopkins
// 4190350

class StandardCard : public Card{

private:

    // The 8 bit data needed for each card
    unsigned char dataForStandardCard;

public:

    enum Rank {
    // The ranks of a standard card
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
    // The suits of a standard card
    Diamonds,
    Clubs,
    Hearts,
    Spades,
    };

    StandardCard(unsigned char incomingData);

    unsigned char getData();

    int getRank();

};

// OS operator overloaders
std::ostream& operator<<(std::ostream& os, StandardCard c);
std::ostream& operator<<(std::ostream& os, StandardCard::Suit s);
std::ostream& operator<<(std::ostream& os, StandardCard::Rank r);

// Comparative overloaders
bool operator==(StandardCard a, StandardCard b);
bool operator!=(StandardCard a, StandardCard b);
bool operator<(StandardCard a, StandardCard b);
bool operator>(StandardCard a, StandardCard b);
bool operator<=(StandardCard a, StandardCard b);
bool operator>=(StandardCard a, StandardCard b);