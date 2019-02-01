// This is the classifications file for the War game.
// Devin Hopkins
// 4190350

enum Suit {
    Spades,
    Clubs,
    Hearts,
    Diamonds,
};

enum Rank {
    Ace,
    One,
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

struct Card {
    Rank rank;
    Suit suit;
};