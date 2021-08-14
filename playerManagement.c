#include "header.h"

void initializePlayers(PlayerList *playerList)
{
    playerList->numberOfPlayers = askAndReturnNumberOfPlayers();
    playerList->starterPlayer = rand() % playerList->numberOfPlayers;
    playerList->winningPlayer = -1;

    for (int playerIncrement = 0; playerIncrement < playerList->numberOfPlayers; playerIncrement++)
    {
        playerList->players[playerIncrement].ID = playerIncrement;
        createPlayer(&playerList->players[playerIncrement]);
    }
    system("clear");
}


int askAndReturnNumberOfPlayers(void)
{
    int choosenPlayers = 0;

    do
    {
        printf("Please choose how many CPUs you would like to play against\n(Pick 1 - 5)");
        scanf("%d", &choosenPlayers);
        choosenPlayers++;
    } while(choosenPlayers > 6 || choosenPlayers < 2);
    return choosenPlayers;
}


void createPlayer(Player *player)
{
    player->confidence = (rand() % 3) - 1;
    player->totalChips = 25;
    player->playerHandSize = 5;
}


void bringIntoRound(PlayerList* playerList)
{
    playerList->starterPlayer++;
    for (int playerIncrement = 0; playerIncrement < playerList->numberOfPlayers; playerIncrement++)
    {
        playerList->players[playerIncrement].inRound = 1;
        playerList->players[playerIncrement].totalChips -= 1;
        playerList->players[playerIncrement].handValue = 0;
    }
}