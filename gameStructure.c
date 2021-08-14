#include "header.h"

int mainMenu(void)
{
    int menuOption = 0;
	do {

		system("clear");
		if (menuOption == 1) 
		{
			dispRules();
		}

		else if (menuOption == 3) 
		{
			return(menuOption);
		}

		printf("1)Game rules\n2)Start game\n3)Exit\n");
		scanf("%d", &menuOption);

	} while (menuOption != 2);

    system("clear");

    return menuOption;
}


void dispRules(void) {
	printf("You get better cards than the computer\nDon't lose all your chips\nPlay the game good\n");
}


void gameRound(Deck* gameDeck, PlayerList* playerList)
{
	system("clear");

	initializeRound(gameDeck, playerList);

	actionRound(gameDeck, playerList);

	exchangeCardRound(gameDeck, playerList);

	system("clear");

	actionRound(gameDeck, playerList);

	revealAllHands(gameDeck, playerList);

	applyWinnings(gameDeck, playerList);

	showCurrentChips (playerList);
}


void initializeRound(Deck* gameDeck, PlayerList* playerList)
{
	newRoundDeck(gameDeck);

	bringIntoRound(playerList);

	dealHandsToPlayers(gameDeck, playerList);
}


char exitGame(void)
{
	char playerExit;
	printf("\n\nAnother round?\n(y/n)");
	do
	{
		scanf(" %c", &playerExit);
	} while (playerExit != 'n' && playerExit != 'y');
}


