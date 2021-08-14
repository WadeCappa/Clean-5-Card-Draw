#include "header.h"

int main(void)
{    

    if (mainMenu() == 2)
    {
        srand((unsigned)time(NULL));
        Deck gameDeck;
        PlayerList playerList;
        int currentRound = 1;

        initializePlayers(&playerList);

        do
        {
            printf("---------- ROUND %d ----------\n\n", currentRound, gameDeck.currentCall);

            gameRound(&gameDeck, &playerList);
            currentRound++;

            gameDeck.currentCall++;
        } while(exitGame() != 'n');
    }       

    return 0;
}