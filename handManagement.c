#include "header.h"


void dealHandsToPlayers(Deck *gameDeck, PlayerList *playerList)
{
    for (int playerIncrement = 0; playerIncrement < playerList->numberOfPlayers; playerIncrement++)
    {
        dealHand(gameDeck, &playerList->players[playerIncrement]);
        orginizeHand(&playerList->players[playerIncrement]);
        findHandValue(&playerList->players[playerIncrement]);
    }
    gameDeck->currentPot = playerList->numberOfPlayers;
}

void dealHand(Deck *gameDeck, Player *player)
{
    for (int topCard = gameDeck->drawnCards; topCard < gameDeck->drawnCards + player->playerHandSize; topCard++)
    {
        for (int faceIncrement = 0; faceIncrement < gameDeck->faces; faceIncrement++)
        {
            for (int suitIncrement = 0; suitIncrement < gameDeck->suits; suitIncrement++)
            {
                if (gameDeck->shuffledDeck[suitIncrement][faceIncrement] == topCard)
                {
                    player->playerHand[topCard - gameDeck->drawnCards].suit = suitIncrement;
                    player->playerHand[topCard - gameDeck->drawnCards].faceValue = faceIncrement;
                    player->playerHand[topCard - gameDeck->drawnCards].keepFlag = 0;
                }
            }
        }
    }
    gameDeck->drawnCards += player->playerHandSize;
}

void orginizeHand(Player *player)
{
    Card transferCard = player->playerHand[0];

    for (int totalCardCount = 0; totalCardCount < player->playerHandSize; totalCardCount++)
    {
        for (int selectedCard = 0; selectedCard < (player->playerHandSize - 1 - totalCardCount); selectedCard++)
        {
            if (player->playerHand[selectedCard].faceValue > player->playerHand[selectedCard + 1].faceValue)
            {
                transferCard = player->playerHand[selectedCard];
                player->playerHand[selectedCard] = player->playerHand[selectedCard + 1];
                player->playerHand[selectedCard + 1] = transferCard;
            }
        }
    }
}

void revealAllHands(Deck *gameDeck, PlayerList *playerList)
{
    for (int playerIncrement = 0; playerIncrement < playerList->numberOfPlayers; playerIncrement++)
    {
        printf("Player %d     ", playerList->players[playerIncrement].ID + 1);
        revealHand(gameDeck, &playerList->players[playerIncrement]);
        printf("\n");
    }
}

void revealHand(Deck *gameDeck, Player *player)
{
    displayBestOption(player->handValue);
    for (int increment = 0; increment < 5; increment++)
    {
        printf("%d)        %s of %s\n", increment + 1, gameDeck->cardFaces[player->playerHand[increment].faceValue], gameDeck->cardSuits[player->playerHand[increment].suit]);
    }
}

