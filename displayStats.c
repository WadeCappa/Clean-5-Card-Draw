#include "header.h"


void showCurrentChips (PlayerList* playerList)
{
    printf("\n   Player  |  Chips remaining  \n");
    printf("--------------------------------\n");
    for (int playerIncrement = 0; playerIncrement < playerList->numberOfPlayers; playerIncrement++)
    {
        printf("    %d      |  %d  \n", playerList->players[playerIncrement].ID, playerList->players[playerIncrement].totalChips);
    }
}
