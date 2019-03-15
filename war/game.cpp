// This is the game.cpp file for the War game
// Devin Hopkins
// 4190350

#include "game.hpp"

War::War()
{
    // Creates an extra vector to create all of the cards
    std::vector<Card*> fullDeck;
    unsigned char tempData = 0;

    // Creates 52 individual cards and puts them into the full deck (in order)
    for (int x = 0; x < 4; ++x)
    {
        for (int y = 0; y < 13; ++y)
        {
            // Creating the standard card and putting it into the full deck vector
            fullDeck.push_back(new StandardCard(tempData));

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

    // Creating two jokers
    tempData = 0;
    for (int x = 0; x < 2; ++x)
    {
        fullDeck.push_back(new JokerCard(tempData));
        tempData >>= 6;
        tempData += 1;
        tempData <<= 6;
    }

    // Setting up the random number generator and shuffling
    srand(time(0));
    int deckSize = fullDeck.size();
    for (int t = 0; t < 10000; ++t)
    {
        // Making the random number
        int randOne = rand() % deckSize;

        // Decking the card at the random spot and putting it at the back. The front
        // card is then erased to ensure there are no duplicates
        fullDeck.push_back(fullDeck[randOne]);
        fullDeck.erase(fullDeck.begin() + randOne);
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

    // Viewing the deck
    std::cout << "\nEach player's deck.\n";
    std::cout << "Player 1:\n";
    playerOneDeck.viewDeck();
    std::cout << "\nPlayer 2:\n";
    playerTwoDeck.viewDeck();
    std::cout << "\n\n";
}

void War::playWar()
{
    // This continously checks to see if either player is out of cards
    while (!(playerOneDeck.getSize() == 0) && !(playerTwoDeck.getSize() == 0))
    {
        // This variable is used to track the nmber of cards being flipped over
        // Resetting the number of cards flipped to zero
        int numOfFlips = 0;

        // This is used in the ocassion that more cards need to be flipped out than what's
        // available. They keep track of which deck is almost out
        bool deckOneOut = false;
        bool deckTwoOut = false;

        // Checks to see if each player's first card is equal or not
        if ((*playerOneDeck.get(numOfFlips) == *playerTwoDeck.get(numOfFlips)) && !(deckOneOut || deckTwoOut))
        {
            // Displaying to the user what is happening
            std::cout << "Player One's Card: " << *playerOneDeck.get(numOfFlips) << std::endl;
            std::cout << "Player Two's Card: " << *playerTwoDeck.get(numOfFlips) << std::endl;
            std::cout << "This means war!\n\n";

            // Two more cards are flipped out
            numOfFlips += 2;

            // This is to make sure that the number of cards that comes out isn't greater than one of the
            // sizes of the player's decks
            //
            // Checks to see if player one is out of cards and makes the appropriate adjustments
            if (numOfFlips > playerOneDeck.getSize())
            {
                numOfFlips = playerOneDeck.getSize() - 1;
                deckOneOut = true;
            }
            // Checks to see if player two is out of cards and makes the appropriate adjustments
            else if (numOfFlips > playerTwoDeck.getSize())
            {
                numOfFlips = playerTwoDeck.getSize() - 1;
                deckTwoOut = true;
            }

            // The last of the two cards to be flipped out is compared with the other
            while ((*playerOneDeck.get(numOfFlips) == *playerTwoDeck.get(numOfFlips))  && !(deckOneOut || deckTwoOut))
            {
                // Displaying to the user what is happening
                std::cout << "Player One's Card: " << *playerOneDeck.get(numOfFlips) << std::endl;
                std::cout << "Player Two's Card: " << *playerTwoDeck.get(numOfFlips) << std::endl;
                std::cout << "This means war!\n\n";

                // Two more cards are flipped out
                numOfFlips += 2;

                // This is to make sure that the number of cards that comes out isn't greater than one of the
                // sizes of the player's decks
                //
                // Checks to see if player one is out of cards and makes the appropriate adjustments
                if (numOfFlips > playerOneDeck.getSize())
                {
                    numOfFlips = playerOneDeck.getSize() - 1;
                    deckOneOut = true;
                }
                // Checks to see if player two is out of cards and makes the appropriate adjustments
                else if (numOfFlips > playerTwoDeck.getSize())
                {
                    numOfFlips = playerTwoDeck.getSize() - 1;
                    deckTwoOut = true;
                }
            }
        }

        // This is to make sure that the number of cards that comes out isn't greater than one of the
        // sizes of the player's decks
        //
        // Checks to see if player one is out of cards and makes the appropriate adjustments
        if (numOfFlips > playerOneDeck.getSize())
        {
            numOfFlips = playerOneDeck.getSize() - 1;
            deckOneOut = true;
        }
        // Checks to see if player two is out of cards and makes the appropriate adjustments
        else if (numOfFlips > playerTwoDeck.getSize())
        {
            numOfFlips = playerTwoDeck.getSize() - 1;
            deckTwoOut = true;
        }

        // Now that a victor has been determined, cards are transfered from one deck to another
        if (*playerOneDeck.get(numOfFlips) < *playerTwoDeck.get(numOfFlips))
        {
            // Displaying to the user what is happening
            std::cout << "Player One's Card: " << *playerOneDeck.get(numOfFlips) << std::endl;
            std::cout << "Player Two's Card: " << *playerTwoDeck.get(numOfFlips) << std::endl;
            std::cout << "This means Player Two gets " << (numOfFlips + 1) << " cards from Player One!\n\n";

            // Transferring the appropriate number of cards to player two from player one
            playerOneDeck.transferCardsTo(playerTwoDeck, numOfFlips + 1);

            // Making sure the cards that player two just played are put at the end of their deck
            playerTwoDeck.putCardsAtEndOfDeck(numOfFlips + 1);
        }
        else
        {
            // Displaying to the user what is happening
            std::cout << "Player One's Card: " << *playerOneDeck.get(numOfFlips) << std::endl;
            std::cout << "Player Two's Card: " << *playerTwoDeck.get(numOfFlips) << std::endl;
            std::cout << "This means Player One gets " << (numOfFlips + 1) << " cards from Player Two!\n\n";

            // Transferring the appropriate number of cards to player one from player two
            playerTwoDeck.transferCardsTo(playerOneDeck, numOfFlips + 1);

            // Making sure the cards that player one just played are put at the end of their deck
            playerOneDeck.putCardsAtEndOfDeck(numOfFlips + 1);
        }
    }

    // Declaring the winner and displaying it
    if (playerOneDeck.getSize() == 0)
    {
        std::cout << "And with that, Player 1 is out of cards! Player 2 wins!" << std::endl;
    }
    else
    {
        std::cout << "And with that, Player 2 is out of cards! Player 1 wins!" << std::endl;
    }
}