// This is the game file for the War game.
// Devin Hopkins
// 4190350

#include "game.hpp"

War::War()
{
    // Creates an extra vector to create all of the cards
    std::vector<Card> fullDeck;
    unsigned char tempData = 0;

    // Creates 52 individual cards and puts them into the full deck (in order)
    for (int x = 0; x < 4; ++x)
    {
        for (int y = 0; y < 13; ++y)
        {
            // Creating the card and putting it into the full deck vector
            Card card{tempData};
            fullDeck.push_back(card);

            // This makes the unsigned char increase by one so the next card's
            // rank is one more
            tempData += 1;
        }
        // This gets rid of the data on the right for bits of the unsigned chars
        // thus getting rid of the rank
        tempData >>= 4;

        // This adds one to the unsigned char and then slides the 1 over four spots,
        // thus allowing the suit to increase by one while resetting the other four
        // bits used for the rank (when combined with the statement above)
        tempData += 1;
        tempData <<= 4;
    }

    // Setting up the random number generator and shuffling
    srand(time(0));
    for (int t = 0; t < 10000; ++t)
    {
        // Making the random number
        int randOne = rand() % 52;

        // Taking the card out of the deck, putting it into tempCard, and then putting
        // it back into the end of the vector, effectively shuffling it
        Card tempCard = fullDeck[randOne];
        fullDeck.erase(fullDeck.begin() + randOne);
        fullDeck.push_back(tempCard);
    }

    // Putting the cards into the decks of the players
    int z = 0;
    while (z < fullDeck.size())
    {
        // Each player gets every other card from the full deck
        playerOneDeck.addCard(fullDeck[z]);
        playerTwoDeck.addCard(fullDeck[z + 1]);
        z += 2;
    }
}

void War::playWar()
{
    // This continously checks to see if either player is out of cards
    while (!(playerOneDeck.getSize() == 0) && !(playerTwoDeck.getSize() == 0))
    {
        // This variable is used to track the nmber of cards being flipped over
        // Resetting the number of cards flipped to zero
        int numOfFlips = 0;

        // Checks to see if each player's first card is equal or not
        if (playerOneDeck.get(numOfFlips) == playerTwoDeck.get(numOfFlips))
        {
            // Displaying to the user what is happening
            std::cout << "Player One's Card: " << playerOneDeck.get(numOfFlips) << std::endl;
            std::cout << "Player Two's Card: " << playerTwoDeck.get(numOfFlips) << std::endl;
            std::cout << "This means war!\n\n";

            // Two more cards are flipped out
            numOfFlips += 2;

            // The last of the two cards to be flipped out is compared with the other
            while (playerOneDeck.get(numOfFlips) == playerTwoDeck.get(numOfFlips))
            {
                // Two more cards are flipped out
                numOfFlips += 2;
            }
        }

        // Now that a victor has been determined, cards are transfered from one deck to another
        if (playerOneDeck.get(numOfFlips) < playerTwoDeck.get(numOfFlips))
        {
            // Displaying to the user what is happening
            std::cout << "Player One's Card: " << playerOneDeck.get(numOfFlips) << std::endl;
            std::cout << "Player Two's Card: " << playerTwoDeck.get(numOfFlips) << std::endl;
            std::cout << "This means Player Two gets " << (numOfFlips + 1) << " cards from Player One!\n\n";

            // Transferring the appropriate number of cards to player two from player one
            playerOneDeck.transferCardsTo(playerTwoDeck, numOfFlips + 1);
        }
        else
        {
            // Displaying to the user what is happening
            std::cout << "Player One's Card: " << playerOneDeck.get(numOfFlips) << std::endl;
            std::cout << "Player Two's Card: " << playerTwoDeck.get(numOfFlips) << std::endl;
            std::cout << "This means Player One gets " << (numOfFlips + 1) << " cards from Player Two!\n\n";

            // Transferring the appropriate number of cards to player two from player one
            playerTwoDeck.transferCardsTo(playerOneDeck, numOfFlips + 1);
        }
    }

    // Declaring the winner and displaying it to the winner
    if (playerOneDeck.getSize() == 0)
    {
        std::cout << "Player 2 wins!" << std::endl;
    }
    else
    {
        std::cout << "Player 1 wins!" << std::endl;
    }
}