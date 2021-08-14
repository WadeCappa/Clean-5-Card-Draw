#include "header.h"


void exchangeCardRound(Deck* gameDeck, PlayerList* playerList)
{
    if (playerList->players[0].inRound == 1)
    {
        changeCards(gameDeck, &playerList->players[0]);
    }
    
    for (int incrementPlayers = 1; incrementPlayers < playerList->numberOfPlayers; incrementPlayers++)
    {
        if (playerList->players[incrementPlayers].inRound == 1)
        {
            changeBotCards(gameDeck, &playerList->players[incrementPlayers]);
            orginizeHand(&playerList->players[incrementPlayers]);
            findHandValue(&playerList->players[incrementPlayers]);
        }
    }
}


void changeCards(Deck* gameDeck, Player* player)
{
    if (askToExchangeCards() == 'y')
    {       
        redrawCards(gameDeck, player, askHowManyToExchange());
        orginizeHand(player);
        findHandValue(player);
    }
}


char askToExchangeCards(void)
{
    char userAnswer = '\0';
    printf("Would you like to exchange cards?\n(y/n)\n"); 
	do {
		scanf(" %c", &userAnswer);
	} while (userAnswer != 'y' && userAnswer != 'n');

    return userAnswer;
}

int askHowManyToExchange(void)
{
    int numberOfCards;
    printf("How many?\n(options: 0 - 3)");
    do {
        scanf("%d", &numberOfCards);
    } while (numberOfCards > 3 || numberOfCards <= 0);
    return numberOfCards;
}

void redrawCards(Deck* gameDeck, Player* player, int cardsToExchange)
{
    while (cardsToExchange-- > 0)
    {
        int pickedCard = pickACard();
        exchangeCard(gameDeck, player, pickedCard);
    }
}

int pickACard(void)
{
    int replaceCard;
    printf("Pick a Card\n");
    do {
        scanf("%d", &replaceCard);
    } while (replaceCard > 5 || replaceCard <= 0); 
    return (replaceCard - 1);
}


void exchangeCard(Deck* gameDeck, Player* player, int replaceCard)
{
    for (int suitIncrement = 0; suitIncrement < gameDeck->suits; suitIncrement++)
    {
        for (int faceIncrement = 0; faceIncrement < gameDeck->faces; faceIncrement++)
        {
            if (gameDeck->shuffledDeck[suitIncrement][faceIncrement] == gameDeck->drawnCards)
            {
                player->playerHand[replaceCard].suit = suitIncrement;
                player->playerHand[replaceCard].faceValue = faceIncrement;
                player->playerHand[replaceCard].keepFlag = 0;
            }
        }
    }
    gameDeck->drawnCards++;	
}


void changeBotCards(Deck* gameDeck, Player* player)
{
    int exchangedCards = 0;
    for (int selectedCard = 0; selectedCard < player->playerHandSize; selectedCard++)
    {
        if (player->playerHand[selectedCard].keepFlag == 0 && exchangedCards < 3)
        {
            exchangedCards++;
            for (int suitIncrement = 0; suitIncrement < gameDeck->suits; suitIncrement++)
            {
                for (int faceIncrement = 0; faceIncrement < gameDeck->faces; faceIncrement++)
                {
                    if (gameDeck->shuffledDeck[suitIncrement][faceIncrement] == gameDeck->drawnCards)
                    {
                        player->playerHand[selectedCard].suit = suitIncrement;
                        player->playerHand[selectedCard].faceValue = faceIncrement;
                        player->playerHand[selectedCard].keepFlag = 0;
                    }
                }
            }
            gameDeck->drawnCards++;	
        }
    }
}


