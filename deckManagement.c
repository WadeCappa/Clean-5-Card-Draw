#include "header.h"


void newRoundDeck(Deck* gameDeck)
{
    initializeDeckValues(gameDeck);
	resetDeckValues(gameDeck);
	shuffleDeck(gameDeck);
}


void initializeDeckValues(Deck *gameDeck)
{
    char suits[4][10] = { "Hearts\0", "Diamonds\0", "Clubs\0", "Spades\0" };
    char faces[13][10] = { "Ace\0", "Two\0", "Three\0", "Four\0", "Five\0", "Six\0", "Seven\0", "Eight\0", "Nine\0", "Ten\0", "Jack\0", "Queen\0", "King\0" };

    gameDeck->faces = 13;
    gameDeck->suits = 4;
    gameDeck->size = 52;
    gameDeck->drawnCards = 1;
    gameDeck->currentCall = 1;

    for (int suitCount = 0; suitCount < gameDeck->suits; suitCount++)
    {
        strcpy(gameDeck->cardSuits[suitCount], suits[suitCount]);
    }

    for (int faceCount = 0; faceCount < gameDeck->faces; faceCount++)
    {
        strcpy(gameDeck->cardFaces[faceCount], faces[faceCount]);
    }
}


void shuffleDeck(Deck *gameDeck)
{

    int suit = 0;
    int face = 0;

    for (int deckPosition = 1; deckPosition <= gameDeck->size; deckPosition++)
    {
        do 
        {
            suit = rand() % gameDeck->suits;
            face = rand() % gameDeck->faces;
        } while (gameDeck->shuffledDeck[suit][face] != 0);

        gameDeck->shuffledDeck[suit][face] = deckPosition;
    }
}


void resetDeckValues(Deck *gameDeck)
{
    for (int incrementRows = 0; incrementRows < gameDeck->suits; incrementRows++)
    {
        for (int incrementColumns = 0; incrementColumns < gameDeck->faces; incrementColumns++)
        {
            gameDeck->shuffledDeck[incrementRows][incrementColumns] = 0;
        }
    }
}


void showDeckDEBUG(Deck *gameDeck)
{
    for (int incrementRows = 0; incrementRows < gameDeck->suits; incrementRows++)
    {
        for (int incrementColumns = 0; incrementColumns < gameDeck->faces; incrementColumns++)
        {
            printf("deck[%d][%d] = %d\n", incrementRows, incrementColumns, gameDeck->shuffledDeck[incrementRows][incrementColumns]);
        }
    }
}

