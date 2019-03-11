// This is the jokerCard.hpp file for the War game
// Devin Hopkins
// 4190350

class JokerCard : public Card{

private:

    // The 8 bit data needed for each card
    unsigned char dataForCard;

public:

    enum Color {
    // The color of a Joker card
    Black,
    Red,
    };

    Card(unsigned char incomingData);

    unsigned char getData();

    int getRank();

};