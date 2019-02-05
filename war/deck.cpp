// This is the deck file for the War game.
// Devin Hopkins
// 4190350

#include "deck.hpp"

Deck::Deck()
{
    fillDecks();
}

void Deck::fillDecks()
{
    // This fills the original deck up with 52 cards
    Card card;
    Card deck[52];
    for (int x = 0; x < 52; ++x)
    {
        createCard(card, x);
        deck[x] = card;
    }

    // This shuffles the cards by swapping two random cards 10,000 times
    for (int x = 0; x < 10000; ++x)
    {
        // Get two random numbers between 0 and 51
        int randomInt = rand() % 52;
        int randomInt2 = rand() % 52;

        // Swaps the two cards in the place of the two random numbers
        Card temp = deck[randomInt];
        deck[randomInt] = deck[randomInt2];
        deck[randomInt2] = temp;
    }

    // This divides up the cards into the two decks
    int temp = 0;
    int x = 0;
    while (temp <= 50)
    {
        playerOneDeck[x] = deck[temp];
        playerTwoDeck[x] = deck[temp + 1];
        temp += 2;
        ++x;
    }

    // The remaining spots are filled with an empty card
    Card emptyCard;
    emptyCard.rank = None;
    emptyCard.suit = Empty;
    while (x <= 51)
    {
        playerOneDeck[x] = emptyCard;
        playerTwoDeck[x] = emptyCard;
        ++x;
    }
}

void Deck::createCard(Card &sentCard, int x)
{
    // Giving the card the suit
    switch (x % 4){
        case 0 :
            sentCard.suit = Spades;
            break;
        case 1 :
            sentCard.suit = Clubs;
            break;
        case 2 :
            sentCard.suit = Hearts;
            break;
        case 3 :
            sentCard.suit = Diamonds;
            break;
    }

    // Giving the card the rank
    switch (x % 13){
        case 0 :
            sentCard.rank = Ace;
            break;
        case 1 :
            sentCard.rank = King;
            break;
        case 2 :
            sentCard.rank = Two;
            break;
        case 3 :
            sentCard.rank = Three;
            break;
        case 4 :
            sentCard.rank = Four;
            break;
        case 5 :
            sentCard.rank = Five;
            break;
        case 6 :
            sentCard.rank = Six;
            break;
        case 7 :
            sentCard.rank = Seven;
            break;
        case 8 :
            sentCard.rank = Eight;
            break;
        case 9 :
            sentCard.rank = Nine;
            break;
        case 10 :
            sentCard.rank = Ten;
            break;
        case 11 :
            sentCard.rank = Jack;
            break;
        case 12 :
            sentCard.rank = Queen;
            break;
    }
}

void Deck::printCard(Card &sentCard)
{
    // The string that will contain the name of the card
    std::string cardName = "";

    // Getting the rank
    switch (sentCard.rank) {
        case 14 :
            cardName += "Ace";
            break;
        case 2 :
            cardName += "Two";
            break;
        case 3 :
            cardName += "Three";
            break;
        case 4 :
            cardName += "Four";
            break;
        case 5 :
            cardName += "Five";
            break;
        case 6 :
            cardName += "Six";
            break;
        case 7 :
            cardName += "Seven";
            break;
        case 8 :
            cardName += "Eight";
            break;
        case 9 :
            cardName += "Nine";
            break;
        case 10 :
            cardName += "Ten";
            break;
        case 11 :
            cardName += "Jack";
            break;
        case 12 :
            cardName += "Queen";
            break;
        case 13 :
            cardName += "King";
            break;
        case 0 :
            cardName += "None";
            break;
    }
    
    // Adding the spaces and 'of'
    cardName += " of ";

    // Adding the suit
    switch (sentCard.suit) {
        case 1 :
            cardName += "Spades";
            break;
        case 2 :
            cardName += "Clubs";
            break;
        case 3 :
            cardName += "Hearts";
            break;
        case 4 :
            cardName += "Diamonds";
            break;
        case 0 :
            cardName += "Empty";
            break;
    }

    // Printing out the name of the card
    std::cout << cardName << std::endl;
}

void Deck::viewDecks()
{
    // Printing out player one's deck
    std::cout << "\nPlayer One's Deck:" << std::endl;
    for (int x = 0; x < 52; ++x)
    {
        if (playerOneDeck[x].rank == 0)
        {
            break;
        }
        printCard(playerOneDeck[x]);
    }

    // Printing out player two's deck
    std::cout << "\nPlayer Two's Deck:" << std::endl;
    for (int x = 0; x < 52; ++x)
    {
        if (playerTwoDeck[x].rank == 0)
        {
            break;
        }
        printCard(playerTwoDeck[x]);
    }
}

bool Deck::getWinner()
{
    if (playerOneDeck[0].rank == 0 || playerTwoDeck[0].rank == 0)
    {
        return true;
    }
    return false;
}

void Deck::goToWar(int numOfCardsPassed)
{
    if (numOfCardsPassed > 51)
    {
        numOfCardsPassed = 2;
    }

    if (playerOneDeck[numOfCardsPassed].rank > playerTwoDeck[numOfCardsPassed].rank)
    {
        changeCards(1, numOfCardsPassed);
    }
    else if (playerOneDeck[numOfCardsPassed].rank < playerTwoDeck[numOfCardsPassed].rank)
    {
        changeCards(2, numOfCardsPassed);
    }
    else
    {
        goToWar(numOfCardsPassed + 3);
    }
}

// The cardGetter is either 1 (player one) or 2 (player two)
void Deck::changeCards(int cardGetter, int numOfCards)
{
    if (cardGetter == 1)
    {
        int endOfDeck = findEndOfDeck(1);
        for (int x = 0; x < numOfCards; ++x)
        {
            playerOneDeck[endOfDeck] = playerTwoDeck[x];
            playerTwoDeck[x].rank = None;
            playerTwoDeck[x].suit = Empty;
        }
        shiftDeck(2);
    }

    if (cardGetter == 2)
    {
        int endOfDeck = findEndOfDeck(2);
        for (int x = 0; x < numOfCards; ++x)
        {
            playerTwoDeck[endOfDeck] = playerOneDeck[x];
            playerOneDeck[x].rank = None;
            playerOneDeck[x].suit = Empty;
        }
        shiftDeck(1);
    }
}

void Deck::printWinner()
{
    if (getWinner())
    {
        if (playerOneDeck[0].rank == 0)
        {
            std::cout << "Player 2 is the winner!" << std::endl;
        }
        else
        {
            std::cout << "Player 1 is the winner!" << std::endl;
        }
    }
}

// The deckShifter is either 1 (player one) or 2 (player two)
void Deck::shiftDeck(int deckShifter)
{
    if (deckShifter == 1)
    {
        int stopper = 0;
        while (playerOneDeck[0].rank == 0 && stopper < 52)
        {
            for (int x = 0; x < 50; ++x)
            {
                playerOneDeck[x] = playerOneDeck[x + 1];
            }
            ++stopper;
            playerOneDeck[51].rank = None;
            playerOneDeck[51].suit = Empty;
        }
    }

    if (deckShifter == 2)
    {
        int stopper = 0;
        while (playerTwoDeck[0].rank == 0 && stopper < 52)
        {
            for (int x = 0; x < 50; ++x)
            {
                playerTwoDeck[x] = playerTwoDeck[x + 1];
            }
            ++stopper;
            playerTwoDeck[51].rank = None;
            playerTwoDeck[51].suit = Empty;
        }
    }
}

// The deckNum is either 1 (player one) or 2 (player two)
int Deck::findEndOfDeck(int deckNum)
{
    int place = 0;
    
    // This is for player one
    if (deckNum == 1)
    {
        while (playerOneDeck[place].rank != 0)
        {
            ++place;
        }
    }

    // This is for player two
    else
    {
        while (playerTwoDeck[place].rank != 0)
        {
            ++place;
        }
    }

    return place;
}