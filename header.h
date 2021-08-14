#ifndef HEADER_H 
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>       
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


typedef struct deck
{
    int size;
    int suits;
    int faces;
    int drawnCards;
    int currentCall;
    int currentPot;
    char cardSuits[4][10];
    char cardFaces[13][10];
    int shuffledDeck[4][13];
} Deck;

typedef struct card 
{
    int keepFlag;
	int suit;
    int faceValue;
} Card;

typedef struct player
{
    int ID;
    int inRound;
    int playerHandSize;
    int totalChips;
    int confidence;
    int handValue;
    int scoringOptions[9];
    Card playerHand[5];
} Player;

typedef struct playerList
{
    int numberOfPlayers;
    int starterPlayer;
    int winningPlayer;
    Player players[6];
} PlayerList;

void initializeDeckValues(Deck *gameDeck);
void showDeckDEBUG(Deck *gameDeck);
void shuffleDeck(Deck *gameDeck);
void resetDeckValues(Deck *gameDeck);
void newRoundDeck(Deck* gameDeck);

void displayBestOption(int handValue);
int findHighestOption(int scoringArray[], int size);
void findBestOptions(Player* player);
void checkFor2Pair(Player* player, int faceValue);
void evalutateRepeatedFaceValues(Player* player, int similarCards);
void applyFlushOutcome(Player* player);
void applyStraightOutcome(Player* player);
void testForStraight(Player* player);
void findRepeatingSuits(Player* player);
void findRepeatingFaceValues(Player* player);
void resetArray(int inputArray[], int size);
void populateScoringArray(Player* player);
void findHandValue(Player* player);

void dealHand(Deck *gameDeck, Player *player);
void orginizeHand(Player *player);
void dealHandsToPlayers(Deck *gameDeck, PlayerList *playerList);
void revealHand(Deck *gameDeck, Player *player);
void revealAllHands(Deck *gameDeck, PlayerList *playerList);

void createPlayer(Player *player);
int askAndReturnNumberOfPlayers(void);
void initializePlayers(PlayerList *playerList);

char askToExchangeCards(void);
int askHowManyToExchange(void);
int pickACard(void);
void exchangeCard(Deck* gamedeck, Player* player, int replaceCard);
void redrawCards(Deck* gameDeck, Player* player, int cardsToExchange);
void changeCards(Deck* gameDeck, Player* player);
void changeBotCards(Deck* gameDeck, Player* player);
void exchangeCardRound(Deck* gameDeck, PlayerList* playerList);

int mainMenu(void);
void playerCall(Deck* gameDeck, Player* player);
void dispRules(void);
void actionResults(Deck* gameDeck, Player* player, int choosenAction);
void gameRound(Deck* gameDeck, PlayerList* playerList);
void actionRound(Deck* gameDeck, PlayerList* playerList);
void takeAction(Deck* gameDeck, Player* player);
void actionPlayer(Deck* gameDeck, Player* player);
void actionBot(Deck* gameDeck, Player* player);
void actionResults(Deck* gameDeck, Player* player, int choosenAction);
void bringIntoRound(PlayerList* playerList);
int checkIfActionPossible(Deck* gameDeck, Player* player, int testedAction);
void actionResults(Deck* gameDeck, Player* player, int choosenAction);
void playerRaise(Deck* gameDeck, Player* player);
void playerFold(Player* player);
void initializeRound(Deck* gameDeck, PlayerList* playerList);
char exitGame(void);

int findHighestFaceValueForValuableCards(Player* player);
int breakTie(PlayerList* playerList, int highestHandValue);
int findHighestHandScores(PlayerList* playerList);
void removeFoldedPlayers(PlayerList* playerList);
int findWinner(PlayerList* playerList);
void applyWinnings(Deck* gameDeck, PlayerList* playerList);

void showCurrentChips (PlayerList* playerList);


#endif 