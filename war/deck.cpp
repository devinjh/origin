// This is the deck file for the War game.
// Devin Hopkins
// 4190350

#include <iostream>
//#include "classifications.cpp"
#include "deck.hpp"

void Deck::createCard(Card &sentCard, int x)
{
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
    
void Deck::fillDeck()
{
    Card card;
    for (int x = 0; x < 52; ++x)
    {
        createCard(card, x);
        deck[x] = card;
    }
}

Deck::Deck()
{
    fillDeck();
}

void Deck::viewDeck()
{
    for (int x = 0; x < 52; ++x)
    {
        std::cout << printRank(deck[x]) << " of " << printSuit(deck[x]) << std::endl;
    }
}

std::string Deck::printSuit(Card &sentCard)
{
    switch (sentCard.suit) {
        case 1 :
            return "Spades";
        case 2 :
            return "Clubs";
        case 3 :
            return "Hearts";
        case 4 :
            return "Diamonds";
        case 0 :
            return "Empty";
    }
}

std::string Deck::printRank(Card &sentCard)
{
    switch (sentCard.rank) {
        case 14 :
            return "Ace";
        case 2 :
            return "Two";
        case 3 :
            return "Three";
        case 4 :
            return "Four";
        case 5 :
            return "Five";
        case 6 :
            return "Six";
        case 7 :
            return "Seven";
        case 8 :
            return "Eight";
        case 9 :
            return "Nine";
        case 10 :
            return "Ten";
        case 11 :
            return "Jack";
        case 12 :
            return "Queen";
        case 13 :
            return "King";
        case 0 :
            return "None";
        
    }
}

void Deck::shuffle()
{
    for (int x = 0; x < 10000; ++x)
    {
        int randomInt = rand() % 52;
        int randomInt2 = rand() % 52;
        swap(randomInt, randomInt2);
    }
}

void Deck::swap(int firstSwap, int secondSwap)
{
    Card temp = deck[firstSwap];
    deck[firstSwap] = deck[secondSwap];
    deck[secondSwap] = temp;
}

void Deck::playWar()
{
    Card playerOneDeck[52];
    Card playerTwoDeck[52];
    //std::cout << playerOneDeck[0].rank << std::endl;

    int temp = 0;
    int x = 0;
    while (temp <= 50)
    {
        //std::cout << "Temp: " << temp << std::endl << "x: " << x << std::endl;
        playerOneDeck[x] = deck[temp];
        playerTwoDeck[x] = deck[temp + 1];
        //std::cout << printRank(playerOneDeck[x]) << " of " << printSuit(playerOneDeck[x]) << std::endl;
        //std::cout << printRank(playerTwoDeck[x]) << " of " << printSuit(playerTwoDeck[x]) << std::endl;
        temp += 2;
        ++x;
    }

    Card emptyCard;
    emptyCard.rank = None;
    emptyCard.suit = Empty;
    while (x <= 51)
    {
        playerOneDeck[x] = emptyCard;
        playerTwoDeck[x] = emptyCard;
        ++x;
    }

    /*
    if (playerOneDeck[51].rank == 0)
    {
        std::cout << "Yes!" << std::endl;
    }
    */

    //std::cout << std::endl;
    //viewDeck();

    /*
    for (int x = 0; x < 52; ++x)
    {
        std::cout << "Player One: " << printRank(playerOneDeck[x]) << " of " << printSuit(playerOneDeck[x]) << std::endl;
        std::cout << "Player Two: " << printRank(playerTwoDeck[x]) << " of " << printSuit(playerTwoDeck[x]) << std::endl << std::endl;
    }
    */

    while(playerOneDeck[0].rank != 0 && playerTwoDeck[0].rank != 0)
    {
        //std::cout << "HERE 1" <<  std::endl;
        playCard(playerOneDeck, playerTwoDeck);
    }
}

void Deck::playCard(Card oneDeck[], Card twoDeck[])
{
    Card warZone[52];
    int x = 0;
    warZone[x] = oneDeck[0];
    warZone[x + 1] = twoDeck[0];

    bool playerOneWinner = false;
    if (warZone[x].rank > warZone[x + 1].rank)
    {
        //std::cout << "HERE 4" << std::endl;
        playerOneWinner = true;
    }
    else if (warZone[x].rank == warZone[x + 1].rank)
    {
        int y = 0;
        while(warZone[x].rank == warZone[x + 1].rank)
        {
            //std::cout << "HERE 2" << std::endl;
            x += 2;
            for (int z = 0; z < 3; ++z)
            {
                warZone[x] = oneDeck[y];
                ++x;
                warZone[x] = twoDeck[y];
                ++x;
                ++y;
            }
            x -= 2;
        }
        if (warZone[x].rank > warZone[x + 1].rank)
        {
            playerOneWinner = true;
        }
    }

    /*
    std::cout << "HERE 5" << std::endl;
    for (int xx = 0; xx < 52; ++xx)
    {
        std::cout << "War Zone: " << printRank(warZone[xx]) << " of " << printSuit(warZone[xx]) << std::endl;
    }
    */
    x += 2;
    //std::cout << "x: " << x << std::endl;
    Card emptyCard;
    emptyCard.rank = None;
    emptyCard.suit = Empty;
    while (x <= 51)
    {
        warZone[x] = emptyCard;
        ++x;
    }

    cleanseWarZoneCards(oneDeck, twoDeck, warZone, playerOneWinner);
}

int Deck::findEndOfDeck(Card randomDeck[])
{
    int place = 0;
    while (randomDeck[place].rank != 0)
    {
        ++place;
    }
    //std::cout << "Place: " << place << std::endl;
    return place;
}

void Deck::cleanseWarZoneCards(Card playerOneDeck[], Card playerTwoDeck[], Card warZone[], bool playerOneWinner)
{
    Card emptyCard;
    emptyCard.rank = None;
    emptyCard.suit = Empty;
    int q = 0;
    int endOfFirstDeck, endOfSecondDeck;

    //std::cout << "War Zone (cleanse function): " << printRank(warZone[q]) << " of " << printSuit(warZone[q]) << std::endl;
    //while (warZone[q].rank != 0 && warZone[q].rank == playerOneDeck[q].rank && warZone[q].suit == playerOneDeck[q].suit && warZone[q + 1].rank == playerTwoDeck[q].rank && warZone[q + 1].suit == playerTwoDeck[q].suit)
    while (warZone[q].rank != 0 && warZone[q].suit != 0)
    {
        //std::cout << "HERE 3" << std::endl;

        if (playerOneWinner)
        {
            endOfFirstDeck = findEndOfDeck(playerOneDeck);
            playerOneDeck[endOfFirstDeck] = warZone[q];
            playerOneDeck[endOfFirstDeck + 1] = warZone[q + 1];
            playerOneDeck[0] = emptyCard;
            playerTwoDeck[0] = emptyCard;
        }
        else
        {
            endOfSecondDeck = findEndOfDeck(playerTwoDeck);
            playerTwoDeck[endOfSecondDeck] = warZone[q];
            playerTwoDeck[endOfSecondDeck + 1] = warZone[q + 1];
            playerOneDeck[0] = emptyCard;
            playerTwoDeck[0] = emptyCard;
        }
        //std::cout << "HERE 3b" << std::endl;
        q += 2;
        shiftDeckOver(playerOneDeck);
        shiftDeckOver(playerTwoDeck);
    }
}

void Deck::shiftDeckOver(Card aDeck[])
{
    while (aDeck[0].rank == 0)
    {
        for (int x = 0; x < 50; ++x)
        {
            aDeck[x] = aDeck[x + 1];
        }
    }
    Card emptyCard;
    emptyCard.rank = None;
    emptyCard.suit = Empty;
    aDeck[51] = emptyCard;
}