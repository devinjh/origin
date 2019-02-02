// This is the classifications file for the War game.
// Devin Hopkins
// 4190350

enum Suit {
    Spades = 1,
    Clubs = 2,
    Hearts = 3,
    Diamonds = 4,
    Empty = 0,
};

enum Rank {
    Ace = 14,
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Jack = 11,
    Queen = 12,
    King = 13,
    None = 0,
};

struct Card {
    Rank rank;
    Suit suit;
};