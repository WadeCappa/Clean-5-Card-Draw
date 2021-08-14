#include "header.h"



void actionRound(Deck* gameDeck, PlayerList* playerList)
{
	for (int incrementPlayers = 0; incrementPlayers < playerList->numberOfPlayers; incrementPlayers++)
	{
		takeAction(gameDeck, &playerList->players[(playerList->starterPlayer + incrementPlayers) % playerList->numberOfPlayers]);
	}
}



void takeAction(Deck* gameDeck, Player* player)
{
	if (player->ID == 0 && player->inRound == 1)
	{
		actionPlayer(gameDeck, player);
	}
	else if (player->inRound == 1)
	{
		actionBot(gameDeck, player);
	}
}

void actionPlayer(Deck* gameDeck, Player* player)
{
	revealHand(gameDeck, player);

	int playerAction;
	
	printf("You have %d chips remaining, and the pot currently has %d chips.\n", player->totalChips, gameDeck->currentPot);
	printf("Action?\n1) Fold\n2) Call %d chip(s)\n", gameDeck->currentCall);

	do
	{		
		scanf("%d", &playerAction);
		playerAction = checkIfActionPossible(gameDeck, player, playerAction);
	} while(playerAction > 2 || playerAction < 0);

	actionResults(gameDeck, player, playerAction);
}

int checkIfActionPossible(Deck* gameDeck, Player* player, int testedAction)
{
	switch (testedAction)
	{
		case 3:
			if (player->totalChips > gameDeck->currentCall)
			{
				return 3;
			}
			break;
		case 2:
			if (player->totalChips >= gameDeck->currentCall)
			{
				return 2;
			}
			break;
		case 1:
			return 1;
	}
	return -1;
}


void actionResults(Deck* gameDeck, Player* player, int choosenAction)
{
	if (choosenAction == 2)
	{
		playerCall(gameDeck, player);
		printf("You add %d chips to the pot\n", gameDeck->currentCall);
	}
	else
	{
		playerFold(player);
		printf("You fold\n");
	}
}

void playerCall(Deck* gameDeck, Player* player)
{
	player->totalChips -= gameDeck->currentCall;
	gameDeck->currentPot += gameDeck->currentCall;
}

void playerFold(Player* player)
{
	player->inRound = 0;
}



void actionBot(Deck* gameDeck, Player* player)
{
	if (player->handValue >= 1 - player->confidence)
	{
		playerCall(gameDeck, player);
		printf("Bot %d adds %d to the pot\n", player->ID, gameDeck->currentCall);
	}
	else
	{
		playerFold(player);
		printf("Bot %d folds\n", player->ID);
	}
}