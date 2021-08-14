#include "header.h"


void applyWinnings(Deck* gameDeck, PlayerList* playerList)
{
    int roundWinner = findWinner(playerList);

    playerList->players[roundWinner].totalChips += gameDeck->currentPot;
    printf("Player %d won %d chips!\n", roundWinner + 1, gameDeck->currentPot);
}



int findWinner(PlayerList* playerList)
{
    removeFoldedPlayers(playerList);

    return (findHighestHandScores(playerList));
}

void removeFoldedPlayers(PlayerList* playerList)
{
    for (int playerIncrement = 0; playerIncrement < playerList->numberOfPlayers; playerIncrement++)
    {
        if (playerList->players[playerIncrement].inRound == 0)
        {
            playerList->players[playerIncrement].handValue = -1;
        }
    }
}


int findHighestHandScores(PlayerList* playerList)
{
    int highestHandValue = -1;
    for (int playerIncrement = 0; playerIncrement < playerList->numberOfPlayers; playerIncrement++)
    {
        if (playerList->players[playerIncrement].handValue > highestHandValue)
        {
            highestHandValue = playerList->players[playerIncrement].handValue;
        }
    }
    return (breakTie(playerList, highestHandValue));
}



int breakTie(PlayerList* playerList, int highestHandValue)
{
    int winningPlayer = -1;
    int highestFaceValue = 0;
    for (int incrementPlayers = 0; incrementPlayers < playerList->numberOfPlayers; incrementPlayers++)
    {
        if (findHighestFaceValueForValuableCards(&playerList->players[incrementPlayers]) > highestFaceValue && playerList->players[incrementPlayers].handValue == highestHandValue)
        {
            winningPlayer = playerList->players[incrementPlayers].ID;
            highestFaceValue = findHighestFaceValueForValuableCards(&playerList->players[incrementPlayers]);
        }
    }
    return winningPlayer;
}


int findHighestFaceValueForValuableCards(Player* player)
{
    int maxFaceValue = 0;
    for (int cardIncrement = 0; cardIncrement < player->playerHandSize; cardIncrement++)
    {
        if (player->playerHand[cardIncrement].keepFlag == 1 && player->playerHand[cardIncrement].faceValue > maxFaceValue)
        {
            maxFaceValue = player->playerHand[cardIncrement].faceValue;
        }
    }
    return maxFaceValue;
}